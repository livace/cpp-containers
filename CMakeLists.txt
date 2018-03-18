cmake_minimum_required(VERSION 3.8)
project(list)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp containers/container.h containers/queue/queue.h containers/queue/queueNode.h tests/testQueue.cpp tests/testQueue.h)
add_executable(list ${SOURCE_FILES})
