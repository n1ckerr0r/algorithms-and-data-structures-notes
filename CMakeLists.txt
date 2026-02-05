cmake_minimum_required(VERSION 3.22)

project(Note VERSION 1.0.0 LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(myapp sortes/intro_sort.cpp)
