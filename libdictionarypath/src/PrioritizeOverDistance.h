//
// Created by Grzegorz Rynkowski on 07/10/2016.
//

#ifndef DICTIONARYPATH_PRIORITIZEOVERDISTANCE_H
#define DICTIONARYPATH_PRIORITIZEOVERDISTANCE_H

#include "DijkstraAlgorithm.h"                             // DijkstraAlgorithmPtr
#include "WordsGraph.h"                                    // Node


/// Functor class that compares two Nodes for Dijkstra algorithm.
///
/// Functor class written for priority queue used in Dijkstra
/// algorithm. It gets two `Node`'s and makes a comparision of their
/// distance to starting node.
///
class PrioritizeOverDistance final
{
public:
    PrioritizeOverDistance(const DijkstraAlgorithm &algorithm);

    bool operator()(const Node &node1, const Node &node2) const;

private:
    const DijkstraAlgorithm &algorithm_;
};


#endif //DICTIONARYPATH_PRIORITIZEOVERDISTANCE_H
