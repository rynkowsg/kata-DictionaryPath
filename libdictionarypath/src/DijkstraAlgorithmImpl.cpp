//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#include "DijkstraAlgorithmImpl.h"

#include <limits>                                          // std::numeric_limits
#include <memory>                                          // std::make_shared

namespace
{
constexpr auto kUndefined = nullptr;

constexpr auto kInfinity = static_cast<unsigned int>(std::numeric_limits<int>::max());
}

DijkstraAlgorithmImpl::DijkstraAlgorithmImpl()
    : priorityQueue_{PriorityQueue(*this)}
{
}

void DijkstraAlgorithmImpl::setGraph(const GraphPtr &graph)
{
    graph_ = graph;
}

void DijkstraAlgorithmImpl::calculate(Node start)
{
    initializeAlgorithm(start);
    fillOutTables();
}

void DijkstraAlgorithmImpl::fillOutTables()
{
    while (!priorityQueue_.empty()) {
        auto node = priorityQueue_.top();
        priorityQueue_.pop();

        for (const auto &neighbour : graph_->getConnections()->at(node)) {
            if (distance_->at(neighbour) > distance_->at(node) + 1) {
                distance_->at(neighbour) = distance_->at(node) + 1;
                previous_->at(neighbour) = node;
                priorityQueue_.push(neighbour);
            }
        }
    }
}

void DijkstraAlgorithmImpl::initializeAlgorithm(Node start)
{
    if (!distance_)
        distance_ = std::make_shared<DistanceTable>();

    if (!previous_)
        previous_ = std::make_shared<PreviousTable>();

    for (auto &node : *graph_->getNodes()) {
        (*distance_)[node] = kInfinity;
        (*previous_)[node] = kUndefined;
    }

    distance_->at(start) = 0;
    priorityQueue_.push(start);
}

ConstPathPtr DijkstraAlgorithmImpl::getPath(Node start, Node end)
{
    if (!path_) {
        path_ = std::make_shared<Path>();
    }

    if (!distance_) {
        calculate(start);
    }

    if (path_->empty() && distance_->at(end) != kInfinity) {
        for (Node node = end; node != kUndefined; node = previous_->at(node)) {
            path_->push_front(node);
        }
    }

    return path_;
}

void DijkstraAlgorithmImpl::printDistanceTable(std::ostream &os)
{
    for (auto &node : *graph_->getNodes()) {
        os << "distance_->at(" << *node << "): " << distance_->at(node) << "\n";
    }
    os << "\n";
}

void DijkstraAlgorithmImpl::printPreviousTable(std::ostream &os)
{
    for (auto &node : *graph_->getNodes()) {
        os << "previous_->at(" << *node << "): "
           << (previous_->at(node) ? *previous_->at(node) : "X") << "\n";
    }
}
