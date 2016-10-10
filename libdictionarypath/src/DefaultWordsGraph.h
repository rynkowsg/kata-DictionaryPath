//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#ifndef DICTIONARYPATH_DEFAULTWORDSGRAPH_H
#define DICTIONARYPATH_DEFAULTWORDSGRAPH_H

#include <ostream>                                         // std::ostream

#include "DictionaryPath/Dictionary.h"                     // DictionaryPtr
#include "DictionaryPath/DictionaryFactory.h"              // DictionaryFactory
#include "WordsGraph.h"                                    // ConnectionsPtr, ConstConnectionsPtr, ConstNodesPtr, NodesPtr, WordsGraph


class DefaultWordsGraph;
using WordsGraphPtr = std::shared_ptr<WordsGraph>;
using ConstWordsGraphPtr = std::shared_ptr<const WordsGraph>;


class DefaultWordsGraph final: public WordsGraph
{
public:
    DefaultWordsGraph();

    void setData(DictionaryPtr dictionary) override;

    inline ConstNodesPtr getNodes() const override final
    { return nodes_; }

    inline const Neighbours &getNeighbours(const Node &node) const override final
    { return connections_->at(node); }

    inline bool contains(const Node& node) const override final
    { return nodes_->find(node) != nodes_->end(); }

    void printConnections(std::ostream &os);

private:
    void initVariables(DictionaryPtr dictionary = DictionaryFactory::CreateDictionary());
    void findConnections();

    DictionaryPtr dictionary_;
    NodesPtr nodes_;
    ConnectionsPtr connections_;
};


#endif //DICTIONARYPATH_DEFAULTWORDSGRAPH_H
