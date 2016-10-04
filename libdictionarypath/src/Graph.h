//
// Created by Grzegorz Rynkowski on 03/10/2016.
//

#ifndef DICTIONARYPATH_GRAPH_H
#define DICTIONARYPATH_GRAPH_H

#include <memory>                                          // std::shared_ptr
#include <unordered_map>                                   // std::unordered_map
#include <unordered_set>                                   // std::unordered_set

#include "DictionaryPath/Dictionary.h"                     // DictionaryPtr

using Node = const Word *;
using Nodes = std::unordered_set<Node>;
using NodesPtr = std::shared_ptr<Nodes>;
using ConstNodesPtr = std::shared_ptr<const Nodes>;

using Neighbours = Nodes;
using Connections = std::unordered_map<Node, Neighbours>;
using ConnectionsPtr = std::shared_ptr<Connections>;
using ConstConnectionsPtr = std::shared_ptr<const Connections>;

class Graph;
using GraphPtr = std::shared_ptr<Graph>;
using ConstGraphPtr = std::shared_ptr<const Graph>;

class Graph
{
public:
    virtual void setData(DictionaryPtr dictionary) = 0;

    virtual ConstNodesPtr getNodes() const = 0;

    virtual ConstConnectionsPtr getConnections() const = 0;
};

#endif //DICTIONARYPATH_GRAPH_H
