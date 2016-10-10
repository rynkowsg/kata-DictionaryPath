//
// Created by Grzegorz Rynkowski on 10/10/2016.
//

#include <gtest/gtest.h>
#include <WordsGraphAlgorithmFactory.h>

#include "MockWordsGraph.h"

using ::testing::_;
using ::testing::NiceMock;
using ::testing::Return;
using ::testing::ReturnRef;


TEST(CalculatingShortestPath, OneWord)
{
    auto nodes = NodesPtr(new Nodes{"cat"});
    auto connections = ConnectionsPtr(new Connections{
        {"cat", {}}
    });
    auto mock = std::make_shared<NiceMock<MockWordsGraph>>();
    ON_CALL(*mock, contains("cat"))
        .WillByDefault(Return(connections->find("cat") != connections->end()));
    ON_CALL(*mock, getNodes())
        .WillByDefault(Return(nodes));
    ON_CALL(*mock, getNeighbours("cat"))
        .WillByDefault(ReturnRef(connections->at("cat")));

    auto algorithm = WordsGraphAlgorithmFactory::CreateShortestPathAlgorithm();
    algorithm->setGraph(mock);

    auto emptyPath = Path{};
    EXPECT_EQ(emptyPath, *(algorithm->getPath("cad", "cat")));
}

TEST(CalculatingShortestPath, TwoWordsWithConnection)
{
    auto nodes = NodesPtr(new Nodes{"cat", "cad"});
    auto connections = ConnectionsPtr(new Connections{
        {"cat", {"cad"}},
        {"cad", {"cat"}}
    });
    auto mock = std::make_shared<NiceMock<MockWordsGraph>>();
    ON_CALL(*mock, contains("cad"))
        .WillByDefault(Return(connections->find("cad") != connections->end()));
    ON_CALL(*mock, contains("cat"))
        .WillByDefault(Return(connections->find("cat") != connections->end()));
    ON_CALL(*mock, getNodes())
        .WillByDefault(Return(nodes));
    ON_CALL(*mock, getNeighbours("cad"))
        .WillByDefault(ReturnRef(connections->at("cad")));
    ON_CALL(*mock, getNeighbours("cat"))
        .WillByDefault(ReturnRef(connections->at("cat")));

    auto algorithm = WordsGraphAlgorithmFactory::CreateShortestPathAlgorithm();
    algorithm->setGraph(mock);

    auto expectingPathFromCadToCat = Path{"cad", "cat"};
    EXPECT_EQ(expectingPathFromCadToCat, *(algorithm->getPath("cad", "cat")));

    auto expectingPathFromCatToCad = Path{"cat", "cad"};
    EXPECT_EQ(expectingPathFromCatToCad, *(algorithm->getPath("cat", "cad")));
}

TEST(CalculatingShortestPath, FiveWordsTwoStepPath)
{
    auto nodes = NodesPtr(new Nodes{"git", "mit", "mat", "hat", "gat"});
    auto connections = ConnectionsPtr(new Connections{
        {"git", {"gat", "mit"}},
        {"mit", {"git", "mat"}},
        {"mat", {"gat", "hat", "mit"}},
        {"hat", {"gat", "mat"}},
        {"gat", {"git", "hat", "mat"}},

    });
    auto mock = std::make_shared<NiceMock<MockWordsGraph>>();
    ON_CALL(*mock, contains("git"))
        .WillByDefault(Return(connections->find("git") != connections->end()));
    ON_CALL(*mock, contains("mit"))
        .WillByDefault(Return(connections->find("mit") != connections->end()));
    ON_CALL(*mock, contains("mat"))
        .WillByDefault(Return(connections->find("mat") != connections->end()));
    ON_CALL(*mock, contains("hat"))
        .WillByDefault(Return(connections->find("hat") != connections->end()));
    ON_CALL(*mock, contains("gat"))
        .WillByDefault(Return(connections->find("gat") != connections->end()));
    ON_CALL(*mock, getNodes())
        .WillByDefault(Return(nodes));
    ON_CALL(*mock, getNeighbours("git"))
        .WillByDefault(ReturnRef(connections->at("git")));
    ON_CALL(*mock, getNeighbours("mit"))
        .WillByDefault(ReturnRef(connections->at("mit")));
    ON_CALL(*mock, getNeighbours("mat"))
        .WillByDefault(ReturnRef(connections->at("mat")));
    ON_CALL(*mock, getNeighbours("hat"))
        .WillByDefault(ReturnRef(connections->at("hat")));
    ON_CALL(*mock, getNeighbours("gat"))
        .WillByDefault(ReturnRef(connections->at("gat")));

    auto algorithm = WordsGraphAlgorithmFactory::CreateShortestPathAlgorithm();
    algorithm->setGraph(mock);

    auto expectingPathFromGitToHat = Path{"git", "gat", "hat"};
    EXPECT_EQ(expectingPathFromGitToHat, *(algorithm->getPath("git", "hat")));

    auto expectingPathFromGitToMit = Path{"git", "mit"};
    EXPECT_EQ(expectingPathFromGitToMit, *(algorithm->getPath("git", "mit")));

    auto expectingPathFromGatToMat = Path{"gat", "mat"};
    EXPECT_EQ(expectingPathFromGatToMat, *(algorithm->getPath("gat", "mat")));

    auto expectingPathFromHatToMit = Path{"hat", "mat", "mit"};
    EXPECT_EQ(expectingPathFromHatToMit, *(algorithm->getPath("hat", "mit")));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
