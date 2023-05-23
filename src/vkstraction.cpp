#include "vkstraction.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_events.h"
#include "vulkancontext.hpp"

void VKStraction::Engine::Run()
{
    this->IsRunning = true;

    while (this->IsRunning)
    {
        if (this->EngineWindow.PollEvents().type == SDL_QUIT)
            this->IsRunning = false;
    }
}

void VKStraction::Engine::CleanUp()
{
    SDL_Quit();
}

VKStraction::Engine::Engine(std::string_view appName, Vector2D dimensions)
        : AppName(appName), EngineWindow(appName, dimensions), IsRunning(false)
{
    SDL_Init(SDL_INIT_VIDEO);

    this->EngineWindow.Initialize();

    this->VkContext = VulkanContext(this->EngineWindow, this->AppName);
}

VKStraction::Engine::~Engine()
{
    this->CleanUp();
}
