//
// Created by Grzegorz Rynkowski on 03/10/2016.
//

#ifndef DICTIONARYPATH_DIJKSTRAALGORITHM_H
#define DICTIONARYPATH_DIJKSTRAALGORITHM_H

#include <memory>                                          // std::shared_ptr
#include <unordered_map>                                   // std::unordered_map

#include "ShortestPathAlgorithm.h"                         // ShortestPathAlgorithm
#include "WordsGraph.h"                                    // Node, WordsGraphPtr


class DijkstraAlgorithm;
using DijkstraAlgorithmPtr = std::shared_ptr<DijkstraAlgorithm>;


class DijkstraAlgorithm: public ShortestPathAlgorithm
{
public:
    using DistanceTable = std::unordered_map<Node, unsigned>;
    using DistanceTablePtr = std::shared_ptr<DistanceTable>;
    using ConstDistanceTablePtr = std::shared_ptr<const DistanceTable>;
    using PreviousTable = std::unordered_map<Node, Node>;
    using PreviousTablePtr = std::shared_ptr<PreviousTable>;
    using ConstPreviousTablePtr = std::shared_ptr<const PreviousTable>;

    virtual void setGraph(const WordsGraphPtr &graph) override = 0;

    virtual ConstPathPtr getPath(Node start, Node end) override = 0;

    virtual ConstDistanceTablePtr getDistanceTable() const = 0;

    virtual ConstPreviousTablePtr getPreviousTable() const = 0;
};


#endif //DICTIONARYPATH_DIJKSTRAALGORITHM_H
