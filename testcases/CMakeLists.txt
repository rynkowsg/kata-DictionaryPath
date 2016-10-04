cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

add_library(TestCaseLibrary
        src/io/InputData.h
        src/io/OutputData.h
        src/io/InputDataImpl.cpp
        src/io/InputDataImpl.h
        src/io/OutputDataImpl.cpp
        src/io/OutputDataImpl.h
        src/TestCase.cpp
        src/TestCase.h
        )
target_link_libraries(TestCaseLibrary
        DictionaryPath
        Boost::boost
        )
target_include_directories(TestCaseLibrary PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)



set (TEST_FILES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/test_files)
configure_file(test/TestFilesPath.h.in test/TestFilesPath.h @ONLY)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/test)

add_executable(TestCases
        test/TestFilesPath.h.in
        test/TestCases.cpp
        )
target_link_libraries(TestCases
        DictionaryPath
        TestCaseLibrary
        Boost::boost
        GTest::main
        )
add_test(NAME AcceptanceTests COMMAND TestCases WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})



