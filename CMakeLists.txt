cmake_minimum_required(VERSION 3.17)
project(LockBox)

set(CMAKE_CXX_STANDARD 14)

add_executable(LockBox
        src/main.cpp src/folder.cpp src/main.h)
