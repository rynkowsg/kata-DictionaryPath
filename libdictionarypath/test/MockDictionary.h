//
// Created by Grzegorz Rynkowski on 08/10/2016.
//

#ifndef DICTIONARYPATH_MOCKDICTIONARY_H
#define DICTIONARYPATH_MOCKDICTIONARY_H

#include <set>                                             // std::set

#include <gmock/gmock.h>

#include <DictionaryPath/Dictionary.h>                     // Dictionary, WordsSet
#include "FactoryMathod.h"                                 // FactoryMethod


class MockDictionary: public Dictionary,
                      public FactoryMethod<MockDictionary>,
                      public WordsSet
{
public:
    MockDictionary()
        : WordsSet()
    {
    }

    template<typename ... Args>
    MockDictionary(Args... args)
        : WordsSet{args...}
    {
    }

    inline Iterator find(const Word &word) const override final
    { return WordsSet::find(word); }

    inline Iterator begin() const override final
    { return WordsSet::begin(); }

    inline Iterator end() const override final
    { return WordsSet::end(); }

    inline bool empty() const override final
    { return WordsSet::empty(); }

    inline std::size_t size() const override final
    { return WordsSet::size(); }

    inline InsertingResult insert(const Word &word) override final
    { return WordsSet::insert(word); }

    MOCK_CONST_METHOD1(findPointer, const Word*(const Word &word));
};


#endif //DICTIONARYPATH_MOCKDICTIONARY_H
