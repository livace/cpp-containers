cmake_minimum_required(VERSION 3.8)
project(list)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp container.h queue.h QueueNode.h testQueue.cpp testQueue.h)
add_executable(list ${SOURCE_FILES})
