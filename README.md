# Ps_Group11_Assignment

### 1. Project Introduction & Application

#### 1.1 Model Introduction

​	The Gray-Scott model is a mathematical model used to describe chemical reactions and diffusion processes. It is a simplified example of a reaction-diffusion system and is often used to study how complex patterns form spontaneously in spatial systems. The model is particularly suitable for simulating patterns that occur in certain biological and chemical processes, such as marking on animal skin or the distribution of chemicals. This project aim at simulating the Gray-Scott model in order to study pattern formation in chemical and biological systems.

#### 1.2 Importance & Application

​	In biology, the Gray-Scott model is an important tool for studying how natural patterns like spots and stripes are formed on living organisms, such as animal skin. It provides a way to understand the biochemical processes underlying these complex patterns. 

​	In chemistry, this model demonstrates how complex spatial patterns can be created through simple chemical reactions and diffusion processes. This is critical for understanding certain types of chemical waves, helix formation and other nonlinear chemical phenomena.

​	In mathematic,  it is a typical example of the application of partial differential equations in simulating complex systems. It is a practical tool for students and professionals in the fields of mathematics and computational science to understand and practice concepts of numerical analysis and computational modeling.



### 2. Main Program

​	The main program is a simulation C++ program for simulating the Gray-Scott model.  It should initial some parameters  such as the diffusion of two chemical material (du and dv), feeding rate (F) and killing rate (k), as well as time steps and number of iterations before use it. This program including simulate step and write the current V value to a VTK file every iteration for visualization. After simulation, Calculating the proportion of grids whose value of V exceeds a certain threshold to the total number of grids. It is used in the program to distinguish areas where chemical concentrations are significant or high enough, which helps identify and analyze pattern formation. For example, in some modes, visible patterns or structures are formed only when the concentration of V exceeds a certain threshold.


### 3. Google Test Setup with CMake

This guide provides instructions on setting up a Google Test environment for C++ projects using CMake on Linux.

## Overview

We have chosen Google Test for testing in our project. Google Test is a popular C++ testing framework designed for a rich testing experience. It supports various types of assertions, test fixtures, and provides mechanisms for organizing and filtering test cases. Google Test simplifies writing test cases through macros, making test code easier to write and maintain.

CMake is a cross-platform build system that uses CMakeLists.txt files to define the build process of a project. It generates standard build files like Makefile or Visual Studio project files, which are then used to compile and link the program. The advantage of CMake lies in its cross-platform capabilities and flexibility, allowing it to handle complex build environments.

## Steps for Setup

### Step 1: Install CMake and Related Tools

Ensure that CMake, a C++ compiler, and Git are installed on your system.

### Step 2: Obtain Google Test Source Code

Clone the Google Test source code from GitHub:

```
git clone https://github.com/google/googletest.git
```

### Step 3: Create Your Project

Create a new directory for your project and set up a CMakeLists.txt file and a test source file:

```
mkdir my_project
cd my_project
touch CMakeLists.txt
touch test.cpp
```

### Step 4: Edit CMakeLists.txt

Set up your CMakeLists.txt with the necessary configurations for Google Test:

```
include_directories(${CMAKE_SOURCE_DIR}/src)

cmake_minimum_required(VERSION 3.24)
project(Ps_Group11_Assignment1)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(GrayScottTests
    tests/test.cpp
    src/gs.cpp
)

target_link_libraries(
    GrayScottTests
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(GrayScottTests)
```

### Step 6: Build the Project

Create a build directory, run CMake, and then use make to build the project:

```
mkdir build
cd build
cmake ..
make
```

### Step 7: Run the Tests

Execute your tests from the build directory:

```
./my_test
```

## Conclusion

This README provides a comprehensive guide to setting up and running Google Test with CMake for C++ projects, ensuring a reliable and maintainable codebase.

### 4. Test Program


​	The test program is to prove that the main program is greatly complete the simulation and make sure the logic and data is correct, including three parts:

(0.1) Check that the type of the model parameters (F , k) matches that of the element type of the u and v vectors.

(0.2) Check that the variables u and v are the same size.

(0.3) Check that the simulation produces the mathematically correct answer when u = 0 and v = 0.
