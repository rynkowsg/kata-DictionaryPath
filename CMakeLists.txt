cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

# Hunter Dependency Manger
# https://docs.hunter.sh/en/latest/quick-start.html
include("cmake/HunterGate.cmake")
HunterGate(
        # https://github.com/ruslo/hunter/releases
        URL "https://github.com/ruslo/hunter/archive/v0.16.8.tar.gz"
        SHA1 "3432a4ce48b1de653e15f6a21851599337b15202"
)

project(DictionaryPath VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O3")


# Add GTest package
# https://github.com/ruslo/hunter/wiki/pkg.gtest
hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)
find_package(GMock CONFIG REQUIRED)

# Add Boost package
# https://github.com/ruslo/hunter/wiki/pkg.boost
hunter_add_package(Boost)
find_package(Boost CONFIG REQUIRED)

### Testing ###
enable_testing()

### Subdirectories ###
add_subdirectory(libdictionarypath)
add_subdirectory(sample)
add_subdirectory(testcases)
