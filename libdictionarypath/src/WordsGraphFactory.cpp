//
// Created by Grzegorz Rynkowski on 05/10/2016.
//

#include "WordsGraphFactory.h"

#include <memory>                                          // std::make_shared

#include "DefaultWordsGraph.h"                             // DefaultWordsGraph


WordsGraphPtr WordsGraphFactory::CreateWordsGraph()
{
    return std::make_shared<DefaultWordsGraph>();
}
