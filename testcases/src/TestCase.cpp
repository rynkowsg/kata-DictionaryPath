//
// Created by Grzegorz Rynkowski on 04/10/2016.
//

#include "TestCase.h"

TestCase::TestCase(const InputDataPtr &inputData,
                   const OutputDataPtr &outputData,
                   DictionaryPath dictionaryPath)
    : inputData_{inputData},
      outputData_{outputData},
      dictionaryPath_{dictionaryPath}
{
}

int TestCase::run()
{
    auto result = dictionaryPath_.calculatePathLength(inputData_->getDictonary(),
                                                      inputData_->getStartingWord(),
                                                      inputData_->getEndingWord());
    auto expectingResult = outputData_->getExpectingResult();

    auto isCorrect = result == expectingResult;
    auto testResult = !isCorrect;
    return testResult;
}
