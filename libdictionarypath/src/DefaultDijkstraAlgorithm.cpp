//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#include "DefaultDijkstraAlgorithm.h"

#include <limits>                                          // std::numeric_limits
#include <memory>                                          // std::make_shared


namespace
{
const auto kUndefined = std::string{""};

constexpr auto kInfinity = static_cast<unsigned int>(std::numeric_limits<int>::max());
}

DefaultDijkstraAlgorithm::DefaultDijkstraAlgorithm()
    : priorityQueue_{PriorityQueue(*this)}
{
}

void DefaultDijkstraAlgorithm::setGraph(const WordsGraphPtr &graph)
{
    graph_ = graph;
}

void DefaultDijkstraAlgorithm::calculate(Node start)
{
    initializeAlgorithm(start);
    fillOutTables();
}

void DefaultDijkstraAlgorithm::fillOutTables()
{
    while (!priorityQueue_.empty()) {
        auto node = priorityQueue_.top();
        priorityQueue_.pop();

        for (const auto &neighbour : graph_->getNeighbours(node)) {
            if (distance_->at(neighbour) > distance_->at(node) + 1) {
                distance_->at(neighbour) = distance_->at(node) + 1;
                previous_->at(neighbour) = node;
                priorityQueue_.push(neighbour);
            }
        }
    }
}

void DefaultDijkstraAlgorithm::initializeAlgorithm(Node start)
{
    distance_ = std::make_shared<DistanceTable>();
    previous_ = std::make_shared<PreviousTable>();

    for (auto &node : *graph_->getNodes()) {
        (*distance_)[node] = kInfinity;
        (*previous_)[node] = kUndefined;
    }

    distance_->at(start) = 0;
    priorityQueue_.push(start);
}

ConstPathPtr DefaultDijkstraAlgorithm::getPath(Node start, Node end)
{
    path_ = std::make_shared<Path>();

    initializeAlgorithm(start);
    calculate(start);

    // TODO: Consider caching results from previous requests
    //       (caching of distance and previous tables).

    if (path_->empty() && distance_->at(end) != kInfinity) {
        for (Node node = end; node != kUndefined; node = previous_->at(node)) {
            path_->push_front(node);
        }
    }

    return path_;
}

void DefaultDijkstraAlgorithm::printDistanceTable(std::ostream &os)
{
    for (auto &node : *graph_->getNodes()) {
        os << "distance_->at(" << node << "): " << distance_->at(node) << "\n";
    }
    os << "\n";
}

void DefaultDijkstraAlgorithm::printPreviousTable(std::ostream &os)
{
    for (auto &node : *graph_->getNodes()) {
        os << "previous_->at(" << node << "): "
           << (previous_->at(node) != kUndefined ? previous_->at(node) : "X") << "\n";
    }
}
