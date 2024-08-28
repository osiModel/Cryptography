cmake_minimum_required(VERSION 3.28.2)

project(TEST)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCES
    crypt.cpp
    main.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ..)

add_executable(software ${SOURCES})