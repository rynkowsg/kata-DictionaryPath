//
// Created by Grzegorz Rynkowski on 03/10/2016.
//

#include <cmath>                                           // std::pow

#include <gtest/gtest.h>

#include "WordsGraphFactory.h"                             // WordsGraphFactory

#include "MockDictionary.h"                                // MockDictionary

TEST(ProcessingDictionary, 0Words)
{
    auto dict = MockDictionary::Create();
    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);

    auto nodes = wordsGraph->getNodes();
    EXPECT_EQ(0, nodes->size());
}

TEST(ProcessingDictionary, 1Word)
{
    auto dict = MockDictionary::Create("cat");
    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);
    EXPECT_EQ(1, wordsGraph->getNodes()->size());
    EXPECT_EQ(0, wordsGraph->getNeighbours("cat").size());
}

TEST(ProcessingDictionary, 2DifferentWords)
{
    auto dict = MockDictionary::Create("cad", "cat");
    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);
    EXPECT_EQ(2, wordsGraph->getNodes()->size());
    EXPECT_EQ(1, wordsGraph->getNeighbours("cad").size());
    EXPECT_EQ(1, wordsGraph->getNeighbours("cat").size());
    EXPECT_EQ("cat", *wordsGraph->getNeighbours("cad").begin());
    EXPECT_EQ("cad", *wordsGraph->getNeighbours("cat").begin());
}

TEST(ProcessingDictionary, 2SameWords)
{
    auto dict = MockDictionary::Create("cat", "cat");
    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);
    EXPECT_EQ(1, wordsGraph->getNodes()->size());
    EXPECT_EQ(0, wordsGraph->getNeighbours("cat").size());
}

TEST(ProcessingDictionary, 3DifferentWords)
{
    auto dict = MockDictionary::Create("cad", "cat", "rat");
    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);
    EXPECT_EQ(3, wordsGraph->getNodes()->size());
    EXPECT_EQ(1, wordsGraph->getNeighbours("cad").size());
    EXPECT_EQ(2, wordsGraph->getNeighbours("cat").size());
    EXPECT_EQ(1, wordsGraph->getNeighbours("rat").size());
    EXPECT_EQ("cat", *wordsGraph->getNeighbours("cad").begin());
    EXPECT_EQ("cat", *wordsGraph->getNeighbours("rat").begin());

    const auto& catNeighbours = wordsGraph->getNeighbours("cat");
    EXPECT_NE(catNeighbours.end(), catNeighbours.find("cad"));
    EXPECT_NE(catNeighbours.end(), catNeighbours.find("rat"));
}

TEST(ProcessingDictionary, 676DifferentWords)
{
    auto dict = MockDictionary::Create();
    for (char a = 'a'; a <= 'z'; ++a) {
        for (char b = 'a'; b <= 'z'; ++b) {
            dict->insert(std::string{a} + b);
        }
    }
    auto amountOfAddedWords = std::pow('z' - 'a' + 1, 2);
    ASSERT_EQ(amountOfAddedWords, dict->size());

    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);

    auto nodes = wordsGraph->getNodes();
    EXPECT_EQ(amountOfAddedWords, nodes->size());
}

// AmountOfWords.DifferentWords17576 takes around 30-50 seconds.
// With current algorithm of build graph, I decided to disable it.
TEST(ProcessingDictionary, 17576DifferentWords)
{
    auto dict = MockDictionary::Create();
    for (char a = 'a'; a <= 'z'; ++a) {
        for (char b = 'a'; b <= 'z'; ++b) {
            for (char c = 'a'; c <= 'z'; ++c) {
                dict->insert(std::string{a} + b + c);
            }
        }
    }
    auto amountOfAddedWords = std::pow('z' - 'a' + 1, 3);
    ASSERT_EQ(amountOfAddedWords, dict->size());

    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);

    auto nodes = wordsGraph->getNodes();
    EXPECT_EQ(amountOfAddedWords, nodes->size());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
