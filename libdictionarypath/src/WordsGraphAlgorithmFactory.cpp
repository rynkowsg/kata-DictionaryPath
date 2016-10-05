//
// Created by Grzegorz Rynkowski on 05/10/2016.
//

#include "WordsGraphAlgorithmFactory.h"

#include <memory>                                          // std::make_shared

#include "DefaultDijkstraAlgorithm.h"                      // DefaultDijkstraAlgorithm


DijkstraAlgorithmPtr WordsGraphAlgorithmFactory::CreateDijkstraAlgorithm()
{
    return std::make_shared<DefaultDijkstraAlgorithm>();
}
