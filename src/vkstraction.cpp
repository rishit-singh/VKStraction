#include "../include/vkstraction.hpp"
#include <GLFW/glfw3.h>

void VKStraction::Engine::InitializeWindow()
{
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    this->Window = glfwCreateWindow(800, 600, "VKStraction", nullptr, nullptr);
}

void VKStraction::Engine::RunMainLoop()
{
    this->InitializeWindow();

    while (!glfwWindowShouldClose(this->Window))
    {
        glfwPollEvents();
    }
}

void VKStraction::Engine::CleanUp()
{
    glfwDestroyWindow(this->Window);
    glfwTerminate();
}

VKStraction::Engine::Engine()
{
}

VKStraction::Engine::~Engine()
{
    this->CleanUp();
}
