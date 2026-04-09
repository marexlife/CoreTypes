cmake_minimum_required(VERSION 3.20)
project(CoreTypes)

set(CUSTOM_HEADER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Public/CoreTypes)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME}
    Private/Int32.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    Public
)

target_precompile_headers(${PROJECT_NAME} PUBLIC
    ${CUSTOM_HEADER_PATH}/Numbers.h
)