//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#ifndef DICTIONARYPATH_DEFAULTWORDSGRAPH_H
#define DICTIONARYPATH_DEFAULTWORDSGRAPH_H

#include <ostream>                                         // std::ostream

#include "DictionaryPath/Dictionary.h"                     // DictionaryPtr
#include "WordsGraph.h"                                    // ConnectionsPtr, ConstConnectionsPtr, ConstNodesPtr, NodesPtr, WordsGraph


class DefaultWordsGraph;
using WordsGraphPtr = std::shared_ptr<WordsGraph>;
using ConstWordsGraphPtr = std::shared_ptr<const WordsGraph>;


class DefaultWordsGraph final: public WordsGraph
{
public:
    DefaultWordsGraph();
    ~DefaultWordsGraph() = default;

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


#endif //DICTIONARYPATH_DEFAULTWORDSGRAPH_H
