cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

# library: "DictionaryPath"
add_library(DictionaryPath
        include/DictionaryPath/Dictionary.h src/Dictionary.cpp
        include/DictionaryPath/DictionaryFactory.h src/DictionaryFactory.cpp
        include/DictionaryPath/DictionaryPath.h src/DictionaryPath.cpp
        src/DefaultDictionary.h
        src/DefaultDijkstraAlgorithm.h src/DefaultDijkstraAlgorithm.cpp
        src/DefaultWordsGraph.h src/DefaultWordsGraph.cpp
        src/DijkstraAlgorithm.h
        src/Path.h src/Path.cpp
        src/PrioritizeOverDistance.h src/PrioritizeOverDistance.cpp
        src/ShortestPathAlgorithm.h
        src/WordsGraph.h
        src/WordsGraphAlgorithmFactory.h src/WordsGraphAlgorithmFactory.cpp
        src/WordsGraphFactory.h src/WordsGraphFactory.cpp
        )
target_include_directories(DictionaryPath PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)


# test: "DictionaryTest"
add_executable(DictionaryTest test/DictionaryTest.cpp)
target_include_directories(DictionaryTest PRIVATE src)
target_link_libraries(DictionaryTest GTest::main DictionaryPath)
add_test(NAME DictionaryTest COMMAND DictionaryTest)


# test: "WordsGraphTest"
add_executable(WordsGraphTest
        test/WordsGraphTest.cpp
        test/MockDictionary.h test/MockDictionary.cpp
        test/FactoryMathod.h
        )
# TODO: Move test/FactoryMathod.h to seperate header-only library.
target_include_directories(WordsGraphTest PRIVATE src)
target_link_libraries(WordsGraphTest GTest::main GMock::main DictionaryPath)
add_test(NAME WordsGraphTest COMMAND WordsGraphTest)


# test: "ShortestPathTest"
add_executable(ShortestPathTest
        test/ShortestPathTest.cpp
        test/MockWordsGraph.h test/MockWordsGraph.cpp
        )
target_include_directories(ShortestPathTest PRIVATE src)
target_link_libraries(ShortestPathTest GTest::main GMock::main DictionaryPath)
add_test(NAME ShortestPathTest COMMAND ShortestPathTest)
