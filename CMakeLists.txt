cmake_minimum_required(VERSION 3.12)
project(VKStraction)

set(CMAKE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
set(CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_FLAGS "-Wall -D_THREAD_SAFE --std=c++20")

find_package(glfw3 3.3 REQUIRED)
find_package(Vulkan REQUIRED)

file(GLOB COMMON_SOURCES
    src/window.cpp
    src/builder.cpp
    src/engine.cpp
    src/validationlayer.cpp
    src/util.cpp
    src/debug.cpp
    src/device.cpp
)

include_directories( include/ )

add_executable(engine src/main.cpp ${COMMON_SOURCES})

target_include_directories(engine PRIVATE include/)
target_link_libraries(engine PUBLIC glfw Vulkan::Vulkan)
