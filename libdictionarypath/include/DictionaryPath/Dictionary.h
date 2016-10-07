//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#ifndef DICTIONARYPATH_DICTIONARY_H
#define DICTIONARYPATH_DICTIONARY_H

#include <cstddef>                                         // std::size_t
#include <memory>                                          // std::shared_ptr
#include <ostream>                                         // std::ostream
#include <string>                                          // std::string
#include <set>                                             // std::set

using Word = std::string;

class Dictionary;
using DictionaryPtr = std::shared_ptr<Dictionary>;

struct Dictionary
{
    using WordsSet = std::set<Word>;
    using InsertingResult = std::pair<WordsSet::iterator, bool>;
    using Iterator = WordsSet::iterator;

    virtual ~Dictionary() = default;

    virtual Iterator find(const Word &word) const = 0;
    virtual Iterator begin() const = 0;
    virtual Iterator end() const = 0;
    virtual bool empty() const = 0;
    virtual std::size_t size() const = 0;

    virtual InsertingResult insert(const Word &word) = 0;
    virtual const Word *findPointer(const Word &word) const = 0;
};

void PrintDictionary(std::ostream &os, const Dictionary &dictionary);
void PrintDictionary(std::ostream &os, DictionaryPtr dictionary);
std::ostream &operator<<(std::ostream &os, const Dictionary &dictionary);
std::ostream &operator<<(std::ostream &os, DictionaryPtr dictionary);

#endif //DICTIONARYPATH_DICTIONARY_H
