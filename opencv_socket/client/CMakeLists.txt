cmake_minimum_required(VERSION 2.8)
project(client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3 -std=c++11")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

#find_package(PkgConfig)
#pkg_check_modules(OpenCV opencv>=3.1.0)
#set(OpenCV_LIBS ${OpenCV_LIBRARIES})
#LINK_DIRECTORIES(${OpenCV_LIBDIR})

find_package(Boost REQUIRED COMPONENTS 
        filesystem
        system)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    ${Boost_LIBRARIES}
    boost_filesystem
    boost_system
    boost_thread)
