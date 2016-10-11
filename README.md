kata-DictionaryPath [![Build Status](https://travis-ci.org/rynkowsg/kata-DictionaryPath.svg)](https://travis-ci.org/rynkowsg/kata-DictionaryPath)
===================


#### Build environment and requirements:

The project has been compiled and tested on OS X only.
In the future I'm going to ensure that it works also on other platforms.

Two requirements needed to build and run the project on OS X:

- Xcode Command Line Tools
- CMake 3.6 or above

#### To compile:

    cmake -H. -Bbuild
    cmake --build build

#### To run a sample:

    ./build/sample/SampleApp

#### To run tests:

    cmake --build build --target test

#### To run tests in verbose mode:

    cmake -E chdir build cmake -E time ctest -V
