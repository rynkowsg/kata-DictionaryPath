cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

add_executable(SampleApp src/main.cpp)
target_link_libraries(SampleApp DictionaryPath)
