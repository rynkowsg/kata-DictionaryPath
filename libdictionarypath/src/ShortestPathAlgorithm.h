//
// Created by Grzegorz Rynkowski on 03/10/2016.
//

#ifndef DICTIONARYPATH_SHORTESTPATHALGORITHM_H
#define DICTIONARYPATH_SHORTESTPATHALGORITHM_H

#include <memory>                                          // std::shared_ptr

#include "Graph.h"                                         // GraphPtr, Node
#include "Path.h"                                          // ConstPathPtr

class ShortestPathAlgorithm;
using ShortestPathAlgorithmPtr = std::shared_ptr<ShortestPathAlgorithm>;

class ShortestPathAlgorithm
{
public:
    virtual void setGraph(const GraphPtr &graph) = 0;

    virtual ConstPathPtr getPath(Node start, Node end) = 0;
};


#endif //DICTIONARYPATH_SHORTESTPATHALGORITHM_H