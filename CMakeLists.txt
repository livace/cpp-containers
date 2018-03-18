cmake_minimum_required(VERSION 3.8)
project(containers)

add_subdirectory(lib/googletest)



include_directories(lib/googletest/include)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp containers/container.h containers/queue/queue.h containers/queue/queueNode.h tests/testQueue.cpp tests/testQueue.h)
add_executable(containers ${SOURCE_FILES})

target_link_libraries(containers gtest)