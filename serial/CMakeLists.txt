cmake_minimum_required(VERSION 2.8)
project(serial)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3 -std=c++11")

find_package(Boost REQUIRED COMPONENTS 
        system)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} serial.cpp)
target_link_libraries( ${PROJECT_NAME} 
    boost_system
    )

