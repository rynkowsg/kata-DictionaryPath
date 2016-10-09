//
// Created by Grzegorz Rynkowski on 08/10/2016.
//

#include <gtest/gtest.h>

#include <DictionaryPath/DictionaryFactory.h>              // DictionaryFactory

TEST(DictionarySize, Empty)
{
    auto dict = DictionaryFactory::CreateDictionary();
    EXPECT_EQ(0, dict->size());
    EXPECT_TRUE(dict->empty());
}

TEST(DictionarySize, DifferentWords)
{
    auto dict = DictionaryFactory::CreateDictionary("aaa", "bbb", "ccc");
    EXPECT_EQ(3, dict->size());
    EXPECT_FALSE(dict->empty());
}

TEST(DictionarySize, SameWords)
{
    auto dict = DictionaryFactory::CreateDictionary("aaa", "aaa", "aaa");
    EXPECT_EQ(1, dict->size());
    EXPECT_FALSE(dict->empty());
}

TEST(DictionarySize, SameWords2)
{
    auto dict = DictionaryFactory::CreateDictionary("aaa", "bbb", "aaa");
    EXPECT_EQ(2, dict->size());
    EXPECT_FALSE(dict->empty());
}

TEST(AdditingToDictionary, AddingExistingWord)
{
    auto dict = DictionaryFactory::CreateDictionary("aaa", "bbb", "ccc");
    auto result = dict->insert("aaa");
    auto isInserted = result.second;
    EXPECT_FALSE(isInserted);
    EXPECT_FALSE(dict->empty());
}

TEST(AdditingToDictionary, AddingNewWord)
{
    auto dict = DictionaryFactory::CreateDictionary("aaa", "bbb", "ccc");
    auto result = dict->insert("ddd");
    auto isInserted = result.second;
    EXPECT_TRUE(isInserted);
    EXPECT_FALSE(dict->empty());
}

TEST(AdditingToDictionary, AddingNewWordToEmptyDictionary)
{
    auto dict = DictionaryFactory::CreateDictionary();
    auto result = dict->insert("ddd");
    auto isInserted = result.second;
    EXPECT_TRUE(isInserted);
    EXPECT_FALSE(dict->empty());
}

TEST(FindingWordsInDictionary, InEmptyDictionary)
{
    auto dict = DictionaryFactory::CreateDictionary();
    EXPECT_TRUE(dict->empty());
    EXPECT_FALSE(dict->contains("aaa"));
}

TEST(FindingWordsInDictionary, InOneElementDictionary)
{
    auto dict = DictionaryFactory::CreateDictionary("aaa");
    EXPECT_TRUE(dict->contains("aaa"));
    EXPECT_FALSE(dict->contains("bbb"));
}

TEST(FindingWordsInDictionary, InTwoElementsDictionary)
{
    auto dict = DictionaryFactory::CreateDictionary("aaa", "bbb");
    EXPECT_TRUE(dict->contains("aaa"));
    EXPECT_TRUE(dict->contains("bbb"));
    EXPECT_FALSE(dict->contains("ccc"));
}

namespace
{
Word CreateWord(unsigned length = 3)
{
    auto word = std::string{};
    for (auto i = 0u; i < length; ++i) {
        word += "a";
    }
    return word;
}
}

TEST(LongWords, CreateADict)
{
    const auto longWord = CreateWord(2500);
    auto dict = DictionaryFactory::CreateDictionary(longWord);
    EXPECT_FALSE(dict->empty());
    EXPECT_EQ(1, dict->size());

    auto anotherLongWord = longWord.substr(0, longWord.length() - 1) + "b";
    ASSERT_EQ(anotherLongWord.length(), longWord.length());
    dict->insert(anotherLongWord);
    EXPECT_FALSE(dict->empty());
    EXPECT_EQ(2, dict->size());
}

TEST(LongWords, AddSecondWord)
{
    const auto longWord = CreateWord(2500);
    auto dict = DictionaryFactory::CreateDictionary(longWord);

    auto secondLongWord = longWord.substr(0, longWord.length() - 1) + "b";
    ASSERT_EQ(secondLongWord.length(), longWord.length());

    dict->insert(secondLongWord);
    EXPECT_FALSE(dict->empty());
    EXPECT_EQ(2, dict->size());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
