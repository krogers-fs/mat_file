
cmake_minimum_required(VERSION 3.10)
project(Test)
add_executable(Main main.cpp)

target_include_directories(Main PUBLIC
                           "../src"
                           "../lib/matlab/extern/include"
                           )