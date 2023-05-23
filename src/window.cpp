#include "window.hpp"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_video.h"

VKStraction::Window::Window(std::string_view title, Vector2D dimensions, bool initialize) : Title(title), Dimensions(dimensions)
{
    if (initialize)
        this->Initialize();
}

VKStraction::Window::~Window()
{
    SDL_DestroyWindow(this->mWindow);
}

void VKStraction::Window::Initialize()
{
    this->mWindow = SDL_CreateWindow(this->Title.data(),
                                     0,
                                     2500,
                                     this->Dimensions.X,
                                     this->Dimensions.Y,
                                     (SDL_WindowFlags)(SDL_WINDOW_VULKAN));
}

SDL_Event &VKStraction::Window::PollEvents()
{
    SDL_PollEvent(&this->WindowEvent);

    return this->WindowEvent;
}


SDL_Window* VKStraction::Window::GetInstance()
{
    return this->mWindow;
}
