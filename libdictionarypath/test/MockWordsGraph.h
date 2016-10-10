//
// Created by Grzegorz Rynkowski on 10/10/2016.
//

#ifndef DICTIONARYPATH_MOCKWORDSGRAPH_H
#define DICTIONARYPATH_MOCKWORDSGRAPH_H

#include <gmock/gmock.h>

#include "WordsGraph.h"                                    // WordsGraph


class MockWordsGraph: public WordsGraph
{
public:
    MOCK_METHOD1(setData, void(DictionaryPtr dictionary));
    MOCK_CONST_METHOD0(getNodes, ConstNodesPtr());
    MOCK_CONST_METHOD1(getNeighbours, const Neighbours&(const Node &node));
    MOCK_CONST_METHOD1(contains, bool(const Node &node));
};


#endif //DICTIONARYPATH_MOCKWORDSGRAPH_H
