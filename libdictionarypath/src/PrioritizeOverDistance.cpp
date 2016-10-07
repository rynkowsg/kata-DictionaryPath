//
// Created by Grzegorz Rynkowski on 07/10/2016.
//

#include "PrioritizeOverDistance.h"


PrioritizeOverDistance::PrioritizeOverDistance(const DijkstraAlgorithm &algorithm)
    : algorithm_{algorithm}
{
}

bool PrioritizeOverDistance::operator()(const Node &node1, const Node &node2) const
{
    const auto &distance = algorithm_.getDistanceTable();
    return distance->at(node1) > distance->at(node2);
}
