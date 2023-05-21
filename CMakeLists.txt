cmake_minimum_required(VERSION 2.8)
project(VKStraction)

set(CMAKE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/opt/local/include/SDL2 -Wall -D_THREAD_SAFE --std=c++20")

file(GLOB VKStraction_SOURCES
        src/*.cpp)

find_package(Vulkan REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(include/)
add_executable(VKStraction ${VKStraction_SOURCES})
#add_executable(CVcli src/main.cpp)
target_include_directories(VKStraction PRIVATE include/)
target_link_libraries(VKStraction ${SDL2_LIBRARIES})
target_link_libraries(VKStraction PRIVATE SDL2_image::SDL2_image)
project("VKStraction")
