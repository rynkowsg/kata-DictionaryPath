//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#ifndef DICTIONARYPATH_DEFAULTDIJKSTRAALGORITHM_H
#define DICTIONARYPATH_DEFAULTDIJKSTRAALGORITHM_H

#include <ostream>                                         // std::ostream
#include <queue>                                           // std::priority_queue
#include <vector>                                          // std::vector

#include "DijkstraAlgorithm.h"                             // DijkstraAlgorithm
#include "Path.h"                                          // Path
#include "PrioritizeOverDistance.h"                        // PrioritizeOverDistance
#include "WordsGraph.h"                                    // Node, WordsGraphPtr


class DefaultDijkstraAlgorithm final: public DijkstraAlgorithm
{
public:
    DefaultDijkstraAlgorithm();

    void setGraph(const WordsGraphPtr &graph) override;
    void calculate(Node start);

    ConstDistanceTablePtr getDistanceTable() const override
    { return distance_; }

    ConstPreviousTablePtr getPreviousTable() const override
    { return previous_; }

    ConstPathPtr getPath(Node start, Node end) override;

private:
    using PriorityQueue = std::priority_queue<Node, std::vector<Node>, PrioritizeOverDistance>;

    void initializeAlgorithm(Node start);
    void fillOutTables();
    void printDistanceTable(std::ostream &os);
    void printPreviousTable(std::ostream &os);

    ConstWordsGraphPtr graph_;

    DistanceTablePtr distance_;
    PreviousTablePtr previous_;
    PriorityQueue priorityQueue_;
    PathPtr path_;
};


#endif //DICTIONARYPATH_DEFAULTDIJKSTRAALGORITHM_H
