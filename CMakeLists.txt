cmake_minimum_required(VERSION 3.10)

project(System_monitor)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/CPUParser.cpp
    src/MemoryParser.cpp)

include_directories(include)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)