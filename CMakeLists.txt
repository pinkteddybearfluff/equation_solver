cmake_minimum_required(VERSION 3.10)

project(matrixSuite)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(matrix
        #        test.cpp
        #        equation_parser.cpp
        equation_solver.cpp
        equation_parser.cpp
        matrix_utilities.cpp
)