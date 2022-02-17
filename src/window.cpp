#include "../include/window.hpp"
#include <GLFW/glfw3.h>

VKStraction::Window::Window() : Title("VKStraction App"), Resolution(WindowResolution(800, 600))
{
    this->Initialize();
}

VKStraction::Window::~Window()
{
    this->Delete();
}

void VKStraction::Window::Initialize()
{
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    this->GLFWWindowObject = glfwCreateWindow(this->Resolution.X, this->Resolution.Y, this->Title.c_str(), nullptr, nullptr);
}

void VKStraction::Window::Delete()
{
    glfwDestroyWindow(this->GLFWWindowObject);
    glfwTerminate();
}
