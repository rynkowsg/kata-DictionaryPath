//
// Created by Grzegorz Rynkowski on 04/10/2016.
//

#ifndef DICTIONARYPATH_TESTCASE_H
#define DICTIONARYPATH_TESTCASE_H

#include <DictionaryPath/DictionaryPath.h>

#include "io/InputData.h"                                  // InputDataPtr
#include "io/OutputData.h"                                 // OutputDataPtr

class TestCase
{
public:
    TestCase(const InputDataPtr& inputData,
             const OutputDataPtr& outputData,
             DictionaryPath dictionaryPath);

    int run();

private:
    InputDataPtr inputData_;
    OutputDataPtr outputData_;
    DictionaryPath dictionaryPath_;
};

#endif //DICTIONARYPATH_TESTCASE_H
