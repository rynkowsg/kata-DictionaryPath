//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#ifndef DICTIONARYPATH_WORDSGRAPH_H
#define DICTIONARYPATH_WORDSGRAPH_H

#include <ostream>                                         // std::ostream

#include "DictionaryPath/Dictionary.h"                     // DictionaryPtr
#include "Graph.h"                                         // ConnectionsPtr, ConstConnectionsPtr, ConstNodesPtr, NodesPtr, Graph

class WordsGraph;
using WordsGraphPtr = std::shared_ptr<WordsGraph>;
using ConstWordsGraphPtr = std::shared_ptr<const WordsGraph>;

class WordsGraph final: public Graph
{
public:
    WordsGraph();
    ~WordsGraph() = default;

    void setData(DictionaryPtr dictionary) override;

    ConstNodesPtr getNodes() const override
    { return nodes_; }

    ConstConnectionsPtr getConnections() const override
    { return connections_; }

    void printConnections(std::ostream &os);

private:
    void initVariables(DictionaryPtr dictionary = std::make_shared<Dictionary>());
    void findConnections();

    DictionaryPtr dictionary_;
    NodesPtr nodes_;
    ConnectionsPtr connections_;
};

#endif //DICTIONARYPATH_WORDSGRAPH_H
