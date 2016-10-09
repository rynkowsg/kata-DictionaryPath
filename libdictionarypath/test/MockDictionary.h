//
// Created by Grzegorz Rynkowski on 08/10/2016.
//

#ifndef DICTIONARYPATH_MOCKDICTIONARY_H
#define DICTIONARYPATH_MOCKDICTIONARY_H

#include <set>                                             // std::set

#include <gmock/gmock.h>

#include <DictionaryPath/Dictionary.h>                     // Dictionary
#include "FactoryMathod.h"                                 // FactoryMethod


class MockDictionary: public Dictionary,
                      public FactoryMethod<MockDictionary>,
                      public std::set<Word>
{
public:
    MockDictionary()
        : std::set<Word>()
    {
    }

    template<typename ... Args>
    MockDictionary(Args... args)
        : std::set<Word>{args...}
    {
    }

    inline Iterator find(const Word &word) const override final
    { return std::set<Word>::find(word); }

    inline Iterator begin() const override final
    { return std::set<Word>::begin(); }

    inline Iterator end() const override final
    { return std::set<Word>::end(); }

    inline bool empty() const override final
    { return std::set<Word>::empty(); }

    inline std::size_t size() const override final
    { return std::set<Word>::size(); }

    inline InsertingResult insert(const Word &word) override final
    { return std::set<Word>::insert(word); }

    MOCK_CONST_METHOD1(findPointer, const Word*(const Word &word));
};


#endif //DICTIONARYPATH_MOCKDICTIONARY_H