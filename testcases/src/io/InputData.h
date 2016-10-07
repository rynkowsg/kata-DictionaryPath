//
// Created by Grzegorz Rynkowski on 04/10/2016.
//

#ifndef DICTIONARYPATH_INPUTDATA_H
#define DICTIONARYPATH_INPUTDATA_H

#include <memory>                                          // std::shared_ptr

#include <DictionaryPath/Dictionary.h>                     // DictionaryPtr, Word

class InputData;
using InputDataPtr = std::shared_ptr<InputData>;

class InputData
{
public:
    virtual DictionaryPtr getDictonary() = 0;

    virtual Word getStartingWord() = 0;

    virtual Word getEndingWord() = 0;
};


#endif //DICTIONARYPATH_INPUTDATA_H
