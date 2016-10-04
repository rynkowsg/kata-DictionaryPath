cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

# Hunter Dependency Manger
# https://docs.hunter.sh/en/latest/quick-start.html
include("cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.16.5.tar.gz"
        SHA1 "51594bfe1f58a7264c811a0d84bea79fc6758d6b"
)

project(DictionaryPath VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
