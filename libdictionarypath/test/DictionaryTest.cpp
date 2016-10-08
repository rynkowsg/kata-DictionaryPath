//
// Created by Grzegorz Rynkowski on 08/10/2016.
//

#include <gtest/gtest.h>

#include <DictionaryPath/DictionaryFactory.h>              // DictionaryFactory

TEST(DictionarySize, Empty)
{
    auto dict = DictionaryFactory::CreateDictionary();
    ASSERT_EQ(0, dict->size());
}

TEST(DictionarySize, DifferentWords)
{
    auto dict = DictionaryFactory::CreateDictionary("aaa", "bbb", "ccc");
    ASSERT_EQ(3, dict->size());
}

TEST(DictionarySize, SameWords)
{
    auto dict = DictionaryFactory::CreateDictionary("aaa", "aaa", "aaa");
    ASSERT_EQ(1, dict->size());
}

TEST(DictionarySize, SameWords2)
{
    auto dict = DictionaryFactory::CreateDictionary("aaa", "bbb", "aaa");
    ASSERT_EQ(2, dict->size());
}

TEST(FindingWordsInDictionary, InEmptyDictionary)
{
    auto dict = DictionaryFactory::CreateDictionary();
    ASSERT_EQ(dict->end(), dict->find("aaa"));
    ASSERT_EQ(nullptr, dict->findPointer("aaa"));
}

TEST(FindingWordsInDictionary, InOneElementDictionary)
{
    auto dict = DictionaryFactory::CreateDictionary("aaa");
    ASSERT_NE(dict->end(), dict->find("aaa"));
    ASSERT_NE(nullptr, dict->findPointer("aaa"));
    ASSERT_EQ(dict->end(), dict->find("bbb"));
    ASSERT_EQ(nullptr, dict->findPointer("bbb"));
}

TEST(FindingWordsInDictionary, InTwoElementsDictionary)
{
    auto dict = DictionaryFactory::CreateDictionary("aaa", "bbb");
    ASSERT_NE(dict->end(), dict->find("aaa"));
    ASSERT_NE(nullptr, dict->findPointer("aaa"));
    ASSERT_NE(dict->end(), dict->find("bbb"));
    ASSERT_NE(nullptr, dict->findPointer("bbb"));
    ASSERT_EQ(dict->end(), dict->find("ccc"));
    ASSERT_EQ(nullptr, dict->findPointer("ccc"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
