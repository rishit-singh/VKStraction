#include "window.hpp"

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
}

void VKStraction::Window::Delete()
{
}
