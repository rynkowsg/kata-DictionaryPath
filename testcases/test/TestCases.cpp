//
// Created by Grzegorz Rynkowski on 04/10/2016.
//

#include <gtest/gtest.h>

#include <DictionaryPath/DictionaryPath.h>

#include "io/InputData.h"                                  // InputDataPtr
#include "io/InputDataImpl.h"                              // InputDataImpl
#include "io/OutputData.h"                                 // OutputDataPtr
#include "io/OutputDataImpl.h"                             // OutputDataImpl

// A header formatted by CMake based on TestFilesPath.h.in
#include "TestFilesPath.h"                                 // TEST_FILES_PATH

#define TEST_FROM_FILE(TEST_NAME)                                                        \
TEST(TestCaseFromFile, TEST_NAME) {                                                      \
    auto inputData = InputDataImpl(TEST_FILES_PATH "/" #TEST_NAME ".in");                \
    auto outputData = OutputDataImpl(TEST_FILES_PATH "/" #TEST_NAME ".out");             \
    auto result = DictionaryPath().calculatePathLength(inputData.getDictonary(),         \
                                                       inputData.getStartingWord(),      \
                                                       inputData.getEndingWord());       \
    auto expectingResult = outputData.getExpectingResult();                              \
    EXPECT_EQ( expectingResult, result );                                                \
}

// Below list of test cases refers to the list of *.in/*.out files at test_files/ dir.
TEST_FROM_FILE(0_task_sample);
TEST_FROM_FILE(1_simple_test);
TEST_FROM_FILE(2_simple_test);
TEST_FROM_FILE(3_no_path);
TEST_FROM_FILE(4_5000_random_3chars);
