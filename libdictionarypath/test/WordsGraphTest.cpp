//
// Created by Grzegorz Rynkowski on 03/10/2016.
//

#include <cmath>                                           // std::pow

#include <gtest/gtest.h>

#include "DictionaryPath/Dictionary.h"                     // DictionaryPtr
#include "WordsGraphFactory.h"                             // WordsGraphFactory


TEST(AmountOfWords, NoWords)
{
    auto dict = DictionaryPtr(new Dictionary{});

    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);

    auto nodes = wordsGraph->getNodes();
    EXPECT_EQ(0, nodes->size());
}

TEST(AmountOfWords, DifferentWords2)
{
    auto dict = DictionaryPtr(new Dictionary{"cad", "cat"});

    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);

    auto nodes = wordsGraph->getNodes();
    EXPECT_EQ(2, nodes->size());
}

TEST(AmountOfWords, SameWords2)
{
    auto dict = DictionaryPtr(new Dictionary{"cat", "cat"});

    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
    wordsGraph->setData(dict);

    auto nodes = wordsGraph->getNodes();
    EXPECT_EQ(1, nodes->size());
}

TEST(AmountOfWords, DifferentWords676)
{
    auto dict = DictionaryPtr(new Dictionary{});
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
// With current algorithm of build graph, I decided to skip it.
//TEST(AmountOfWords, DifferentWords17576)
//{
//    auto dict = DictionaryPtr(new Dictionary{});
//    for (char a = 'a'; a <= 'z'; ++a) {
//        for (char b = 'a'; b <= 'z'; ++b) {
//            for (char c = 'a'; c <= 'z'; ++c) {
//                dict->insert(std::string{a} + b + c);
//            }
//        }
//    }
//    auto amountOfAddedWords = std::pow('z' - 'a' + 1, 3);
//
//    auto wordsGraph = WordsGraphFactory::CreateWordsGraph();
//    wordsGraph->setData(dict);
//
//    auto nodes = wordsGraph->getNodes();
//    EXPECT_EQ(amountOfAddedWords, nodes->size());
//    EXPECT_EQ(dict->size(), nodes->size());
//}
