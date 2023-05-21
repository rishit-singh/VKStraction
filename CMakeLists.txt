cmake_minimum_required(VERSION 3.14)
project(VKStraction)

## Testing verified commits
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_CXX_STANDARD 20)
# For compiling shaders
include(cmake/shaders.cmake)
include(deps/deps.cmake)

set(CMAKE_BUILD_TYPE Debug)

# Add source to this project's executable.
file(GLOB SOURCES
  src/*.cpp
)

add_executable (Main ${SOURCES})
target_include_directories(Main PUBLIC
  include/
)

target_include_directories(Main PUBLIC "${CMAKE_SOURCE_DIR}" ${VULKAN_HADERS_INCLUDE_DIRS} ${DEPS_INCLUDE_DIRS})
target_link_libraries(Main vk-bootstrap VulkanMemoryAllocator glm::glm tinyobjloader)
target_link_libraries(Main Vulkan::Vulkan SDL2::SDL2)
