//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#include "DictionaryPath/Dictionary.h"


void PrintDictionary(std::ostream &os, const Dictionary &dictionary)
{
    if (dictionary.empty()) {
        return;
    }

    auto it = dictionary.begin();
    os << "[" << *it;
    for (++it; it != dictionary.end(); ++it)
        os << ", " << *it;
    os << "]";
}

void PrintDictionary(std::ostream &os, DictionaryPtr dictionary)
{
    if (dictionary->empty()) {
        return;
    }

    auto it = dictionary->begin();
    os << "[" << *it;
    for (++it; it != dictionary->end(); ++it)
        os << ", " << *it;
    os << "]";
}

std::ostream &operator<<(std::ostream &os, const Dictionary &dictionary)
{
    PrintDictionary(os, dictionary);
    return os;
}

std::ostream &operator<<(std::ostream &os, DictionaryPtr dictionary)
{
    PrintDictionary(os, dictionary);
    return os;
}
