//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#ifndef DICTIONARYPATH_DIJKSTRAALGORITHMIMPL_H
#define DICTIONARYPATH_DIJKSTRAALGORITHMIMPL_H

#include <ostream>                                         // std::ostream
#include <queue>                                           // std::priority_queue
#include <vector>                                          // std::vector

#include "DijkstraAlgorithm.h"                             // DijkstraAlgorithm
#include "Path.h"                                          // Path
#include "WordsGraph.h"                                    // Node, WordsGraphPtr

class DijkstraAlgorithmImpl: public DijkstraAlgorithm
{
public:
    DijkstraAlgorithmImpl();

    void setGraph(const WordsGraphPtr &graph) override;
    void calculate(Node start);

    ConstDistanceTablePtr getDistanceTable() const override
    { return distance_; }

    ConstPreviousTablePtr getPreviousTable() const override
    { return previous_; }

    ConstPathPtr getPath(Node start, Node end) override;

private:
    class PrioritizeOverDistance
    {
    public:
        PrioritizeOverDistance(const DijkstraAlgorithmImpl &algorithm)
            : algorithm_{algorithm}
        {
        }

        bool operator()(const Node &node1, const Node &node2)
        {
            const auto &distance = algorithm_.getDistanceTable();
            return distance->at(node1) > distance->at(node2);
        }

    private:
        const DijkstraAlgorithmImpl &algorithm_;
    };

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

#endif //DICTIONARYPATH_DIJKSTRAALGORITHMIMPL_H
