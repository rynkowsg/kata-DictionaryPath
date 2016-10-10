//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#include "DictionaryPath/DictionaryPath.h"

#include "WordsGraphAlgorithmFactory.h"                    // WordsGraphAlgorithmFactory
#include "WordsGraphFactory.h"                             // WordsGraphFactory


int DictionaryPath::calculatePathLength(const DictionaryPtr &dictionary,
                                        const Word &start,
                                        const Word &end)
{
    // Each intermediate word must exist in the given dictionary.
    // It doesn't mention that start or end needs to be in the dictionary.
    // "Each intermediate word must exist in the given dictionary"
    if (start == end) {
        return 0;
    }

    // If start and end are not the same, both needs to be in the Dictionary.
    // If one of them is not in the dict, there is no path between them.
    if (!dictionary->contains(start) || !dictionary->contains(end)) {
        return DictionaryPath::kPathNotExist;
    }

    auto graph = WordsGraphFactory::CreateWordsGraph();
    graph->setData(dictionary);

    auto shortestPathAlgorithm = WordsGraphAlgorithmFactory::CreateDijkstraAlgorithm();
    shortestPathAlgorithm->setGraph(graph);

    auto path = shortestPathAlgorithm->getPath(start, end);
    if (path->size() == 0) {
        return DictionaryPath::kPathNotExist;
    }
    else {
        return static_cast<unsigned>(path->size() - 1);
    }
}
