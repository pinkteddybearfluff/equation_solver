cmake_minimum_required(VERSION 3.10)

project(matrixSuite)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_HEADERS
        matrix_utilities.h
        equation_parser.h
        facilities.h
)

set(PROJECT_SOURCES
        equation_solver.cpp
        equation_parser.cpp
        matrix_utilities.cpp)

add_executable(matrix_utilities
        ${PROJECT_SOURCES} ${PROJECT_HEADERS}
)
