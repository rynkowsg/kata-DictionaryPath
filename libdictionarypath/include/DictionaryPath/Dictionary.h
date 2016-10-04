//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#ifndef DICTIONARYPATH_DICTIONARY_H
#define DICTIONARYPATH_DICTIONARY_H

#include <memory>                                          // std::shared_ptr
#include <ostream>                                         // std::ostream
#include <string>                                          // std::string
#include <set>                                             // std::set
#include <unordered_set>                                   // std::unordered_set

using Word = std::string;

using Dictionary = std::set<Word>;
using RawPointersDictionary = std::unordered_set<Word *>;

using DictionaryPtr = std::shared_ptr<Dictionary>;
using RawPointersDictionaryPtr = std::shared_ptr<RawPointersDictionary>;

void PrintDictionary(std::ostream &os, const Dictionary &dictionary);
void PrintDictionary(std::ostream &os, DictionaryPtr dictionary);
void PrintDictionary(std::ostream &os, const RawPointersDictionary &dictionary);
void PrintDictionary(std::ostream &os, RawPointersDictionaryPtr dictionary);
std::ostream &operator<<(std::ostream &os, const Dictionary &dictionary);
std::ostream &operator<<(std::ostream &os, DictionaryPtr dictionary);
std::ostream &operator<<(std::ostream &os, const RawPointersDictionary &dictionary);
std::ostream &operator<<(std::ostream &os, RawPointersDictionaryPtr dictionary);

#endif //DICTIONARYPATH_DICTIONARY_H
