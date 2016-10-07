//
// Created by Grzegorz Rynkowski on 06/10/2016.
//

#include "DefaultDictionary.h"


DefaultDictionary::InsertingResult DefaultDictionary::insert(const Word &word)
{
    return set_.insert(word);
}

const Word *DefaultDictionary::findPointer(const Word &word) const
{
    auto iterator = set_.find(word);
    if (iterator == set_.end()) {
        return nullptr;
    }
    return &*iterator;
}
