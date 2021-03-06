//
// Created by Grzegorz Rynkowski on 06/10/2016.
//

#include "DictionaryPath/DictionaryFactory.h"

#include <memory>                                          // std::make_shared
#include <utility>                                         // std::move

#include "DefaultDictionary.h"                             // DefaultDictionary


DictionaryPtr DictionaryFactory::CreateDictionary()
{
    return std::make_shared<DefaultDictionary>();
}

DictionaryPtr DictionaryFactory::CreateDictionary(const WordsSet &set)
{
    return std::make_shared<DefaultDictionary>(set);
}

DictionaryPtr DictionaryFactory::CreateDictionary(WordsSet &&set)
{
    return std::make_shared<DefaultDictionary>(std::move(set));
}

DictionaryPtr DictionaryFactory::CreateDictionary(std::initializer_list<Word> list)
{
    return std::make_shared<DefaultDictionary>(std::move(list));
}
