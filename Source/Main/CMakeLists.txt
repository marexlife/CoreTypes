cmake_minimum_required(VERSION 3.20)
project(CoreTypes)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
    Private/main.cpp
)