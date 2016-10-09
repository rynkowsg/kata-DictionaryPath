//
// Created by Grzegorz Rynkowski on 03/10/2016.
//

#include <cmath>                                           // std::pow

#include <gtest/gtest.h>

#include "DictionaryPath/Dictionary.h"                     // DictionaryPtr
#include "DictionaryPath/DictionaryFactory.h"              // DictionaryFactory
#include "WordsGraphFactory.h"                             // WordsGraphFactory

#include "MockDictionary.h"                                // MockDictionary

TEST(AmountOfWords, NoWords)
{
    auto dict = MockDictionary::Create();
    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);

    auto nodes = wordsGraph->getNodes();
    ASSERT_EQ(0, nodes->size());
}

TEST(AmountOfWords, OneWord)
{
    auto dict = MockDictionary::Create("cat");
    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);
    ASSERT_EQ(1, wordsGraph->getNodes()->size());
}

TEST(AmountOfWords, DifferentWords2)
{
    auto dict = MockDictionary::Create("cad", "cat");
    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);
    ASSERT_EQ(2, wordsGraph->getNodes()->size());
}

TEST(AmountOfWords, SameWords2)
{
    auto dict = MockDictionary::Create("cat", "cat");
    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);
    ASSERT_EQ(1, wordsGraph->getNodes()->size());
}

TEST(AmountOfWords, DifferentWords676)
{
    auto dict = MockDictionary::Create();
    for (char a = 'a'; a <= 'z'; ++a) {
        for (char b = 'a'; b <= 'z'; ++b) {
            dict->insert(std::string{a} + b);
        }
    }
    auto amountOfAddedWords = std::pow('z' - 'a' + 1, 2);

    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);

    auto nodes = wordsGraph->getNodes();
    EXPECT_EQ(amountOfAddedWords, nodes->size());
    EXPECT_EQ(dict->size(), nodes->size());
}

// AmountOfWords.DifferentWords17576 takes around 30-50 seconds.
// With current algorithm of build graph, I decided to disable it.
TEST(AmountOfWords, DISABLED_DifferentWords17576)
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

    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);

    auto nodes = wordsGraph->getNodes();
    EXPECT_EQ(amountOfAddedWords, nodes->size());
    EXPECT_EQ(dict->size(), nodes->size());
}

TEST(ProcessingDictionary, EmptyDictionary)
{
    auto dict = MockDictionary::Create();
    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);

    auto nodes = wordsGraph->getNodes();
    auto connections = wordsGraph->getConnections();
    EXPECT_EQ(0, nodes->size());
    EXPECT_EQ(0, connections->size());
}

TEST(ProcessingDictionary, OneWordDictionary)
{
    auto dict = MockDictionary::Create("cat");
    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);

    auto nodes = wordsGraph->getNodes();
    auto connections = wordsGraph->getConnections();
    EXPECT_EQ(1, nodes->size());
    EXPECT_EQ(1, connections->size());

    auto connectionsOfAddedNode = (*connections->begin()).second;
    EXPECT_EQ(0, connectionsOfAddedNode.size());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
