# How to run

## Pre-requisites

1. <a href="https://cmake.org/download/">CMake </a>, version >= 17.0
2. IDE or text editor

## Steps

1. Tell CMake where the source files are and where to output build files
```
$ cmake -S . -B build/
```

2. Build the project
```
$ cmake --build build/
```

3. Run the executable
```
$ ./build/src
```

Step 1 is only necessary the first time you're trying to run the project. After telling CMake where the source files are and creating an output directory, you only need to build the project (Step 2) and run the executable (Step 3).