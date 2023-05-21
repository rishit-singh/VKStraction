#ifndef VKSTRACTION_H_
#define VKSTRACTION_H_

#include <vulkan/vulkan.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>
#include <string>
#include "window.hpp"

namespace VKStraction
{

    class Engine
    {
    private:
            void InitializeVulkan();
            void CleanUp();

            std::string_view AppName;
    public:
            Window EngineWindow;

            bool IsRunning;

            void Run();

            Engine(std::string_view = "VKStraction App", Vector2D = Vector2D(800, 600));
            ~Engine();
    };
}

#endif // VKSTRACTION_H_
