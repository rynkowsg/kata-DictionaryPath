##### Requirements:

- CMake 3.6 or above
- compiler
  - on OS X: Xcode Command Line Tools
  - on Windows: Visual Studio
  - on Linux: gcc or clang

##### To compile:

    cmake -H. -Bbuild
    cmake --build build

##### To run a sample:

    ./build/sample/SampleApp

##### To run tests:

    cmake --build build --target test
