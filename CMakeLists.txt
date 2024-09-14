cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(cry)

set(CMAKE_CXX_STANDARD 14)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PRIVATE 
        src/crypt.cpp
)           

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
