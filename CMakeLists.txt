cmake_minimum_required(VERSION 3.12)
project(VKStraction)

set(CMAKE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
set(CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -D_THREAD_SAFE --std=c++20")

find_package(glfw3 3.3 REQUIRED)

file(GLOB COMMON_SOURCES
	src/*.cpp) # to be changed when there are common files

include_directories( include/ )

add_executable(engine src/main.cpp)

target_link_libraries(engine glfw)
target_include_directories(engine PRIVATE include/)
