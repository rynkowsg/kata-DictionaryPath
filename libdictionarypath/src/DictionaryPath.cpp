//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#include "DictionaryPath/DictionaryPath.h"

#include "WordsGraphAlgorithmFactory.h"                    // WordsGraphAlgorithmFactory
#include "WordsGraphFactory.h"                             // WordsGraphFactory


unsigned int DictionaryPath::calculatePathLength(const DictionaryPtr &dictionary,
                                                 const Word *start,
                                                 const Word *end)
{
    auto graph = WordsGraphFactory::CreateWordsGraph();
    graph->setData(dictionary);

    auto shortestPathAlgorithm = WordsGraphAlgorithmFactory::CreateDijkstraAlgorithm();
    shortestPathAlgorithm->setGraph(graph);

    auto path = shortestPathAlgorithm->getPath(start, end);
    if (path->size() == 0) {
        return 0;
    }
    else {
        return static_cast<unsigned>(path->size() - 1);
    }
}
