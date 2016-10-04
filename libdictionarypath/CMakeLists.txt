cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

add_library(DictionaryPath
        include/DictionaryPath/Dictionary.h
        src/Dictionary.cpp
        include/DictionaryPath/DictionaryPath.h
        src/DictionaryPath.cpp
        src/WordsGraph.cpp
        src/WordsGraph.h
        src/DijkstraAlgorithmImpl.cpp
        src/DijkstraAlgorithmImpl.h
        src/Path.cpp
        src/Path.h
        src/Graph.h
        src/ShortestPathAlgorithm.h
        src/DijkstraAlgorithm.h
        )

target_include_directories(DictionaryPath PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)


add_executable(GraphTest test/GraphTest.cpp)
target_link_libraries(GraphTest GTest::main DictionaryPath)
add_test(NAME GraphTest COMMAND GraphTest)
