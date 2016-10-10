kata-DictionaryPath [![Build Status](https://travis-ci.org/rynkowsg/kata-DictionaryPath.svg)](https://travis-ci.org/rynkowsg/kata-DictionaryPath)
===================


#### Requirements:

- CMake 3.6 or above
- compiler
  - on OS X: Xcode Command Line Tools
  - on Windows: Visual Studio
  - on Linux: gcc or clang

The project and tests should compile and run on all three platforms,
although I tested it only on OS X for now (on private computer and on Travis CI).

#### To compile:

    cmake -H. -Bbuild
    cmake --build build

#### To run a sample:

    ./build/sample/SampleApp

#### To run tests:

    cmake --build build --target test

#### To run tests in verbose mode:

    cmake -E chdir build cmake -E time ctest -V
