#include "../include/vkstraction.hpp"
#include <GLFW/glfw3.h>

void VKStraction::Engine::RunMainLoop()
{
    while (!glfwWindowShouldClose(this->WindowObject.GLFWWindowObject))
    {
        glfwPollEvents();
    }
}

void VKStraction::Engine::CleanUp()
{
}

VKStraction::Engine::Engine()
{
}

VKStraction::Engine::~Engine()
{
    this->CleanUp();
}
