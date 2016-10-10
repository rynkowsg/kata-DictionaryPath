//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#ifndef DICTIONARYPATH_DICTIONARYPATH_H
#define DICTIONARYPATH_DICTIONARYPATH_H

#include "Dictionary.h"                                    // DictionaryPtr, Word

class DictionaryPath
{
public:
    int calculatePathLength(const DictionaryPtr &dictionary_,
                            const Word &start,
                            const Word &end);

    static constexpr auto kPathNotExist = -1;
};

#endif //DICTIONARYPATH_DICTIONARYPATH_H
