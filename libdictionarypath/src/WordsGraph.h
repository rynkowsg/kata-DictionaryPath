//
// Created by Grzegorz Rynkowski on 05/10/2016.
//

#ifndef DICTIONARYPATH_WORDSGRAPH_H
#define DICTIONARYPATH_WORDSGRAPH_H

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

class WordsGraph;
using WordsGraphPtr = std::shared_ptr<WordsGraph>;
using ConstWordsGraphPtr = std::shared_ptr<const WordsGraph>;


struct WordsGraph
{
    virtual void setData(DictionaryPtr dictionary) = 0;

    virtual ConstNodesPtr getNodes() const = 0;

    virtual ConstConnectionsPtr getConnections() const = 0;
};


#endif //DICTIONARYPATH_WORDSGRAPH_H
