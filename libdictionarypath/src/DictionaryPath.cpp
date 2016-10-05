//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#include "DictionaryPath/DictionaryPath.h"

#include "DijkstraAlgorithmImpl.h"                         // DijkstraAlgorithmImpl
#include "WordsGraphFactory.h"                             // WordsGraphFactory

unsigned int DictionaryPath::calculatePathLength(const DictionaryPtr &dictionary,
                                                 const Word *start,
                                                 const Word *end)
{
    auto graph = WordsGraphFactory::CreateWordsGraph();
    graph->setData(dictionary);

    auto shortest_path_algorithm = static_cast<ShortestPathAlgorithmPtr>(
        std::make_shared<DijkstraAlgorithmImpl>());
    shortest_path_algorithm->setGraph(graph);

    auto path = shortest_path_algorithm->getPath(start, end);
    if (path->size() == 0) {
        return 0;
    }
    else {
        return static_cast<unsigned>(path->size() - 1);
    }
}
