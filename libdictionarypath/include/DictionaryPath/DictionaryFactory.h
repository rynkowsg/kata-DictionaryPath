//
// Created by Grzegorz Rynkowski on 06/10/2016.
//

#ifndef DICTIONARYPATH_DICTIONARYFACTORY_H
#define DICTIONARYPATH_DICTIONARYFACTORY_H

#include <initializer_list>                                // std::initializer_list
#include <utility>                                         // std::forward

#include "DictionaryPath/Dictionary.h"                     // DictionaryPtr, WordsSet


class DictionaryFactory
{
public:
    template<typename... Args>
    static DictionaryPtr CreateDictionary(Args &&... args)
    {
        return CreateDictionary({std::forward<Args>(args)...});
    }

    static DictionaryPtr CreateDictionary();

    static DictionaryPtr CreateDictionary(const WordsSet &set);

    static DictionaryPtr CreateDictionary(WordsSet &&set);

    static DictionaryPtr CreateDictionary(std::initializer_list<Word> list);
};


#endif //DICTIONARYPATH_DICTIONARYFACTORY_H
