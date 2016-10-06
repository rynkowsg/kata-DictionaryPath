//
// Created by Grzegorz Rynkowski on 06/10/2016.
//

#include "DefaultDictionary.h"


DefaultDictionary::InsertingResult DefaultDictionary::insert(const Word &word)
{
    return set_.insert(word);
}
