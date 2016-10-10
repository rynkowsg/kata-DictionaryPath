//
// Created by Grzegorz Rynkowski on 05/10/2016.
//

#ifndef DICTIONARYPATH_WORDSGRAPHALGORITHMFACTORY_H
#define DICTIONARYPATH_WORDSGRAPHALGORITHMFACTORY_H

#include "ShortestPathAlgorithm.h"                         // ShortestPathAlgorithmPtr
#include "DijkstraAlgorithm.h"                             // DijkstraAlgorithmPtr


class WordsGraphAlgorithmFactory
{
public:
    static ShortestPathAlgorithmPtr CreateShortestPathAlgorithm();

    static DijkstraAlgorithmPtr CreateDijkstraAlgorithm();
};


#endif //DICTIONARYPATH_WORDSGRAPHALGORITHMFACTORY_H
