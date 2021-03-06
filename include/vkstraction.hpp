#ifndef VKSTRACTION_H_
#define VKSTRACTION_H_

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <string>
#include "../include/window.hpp"

namespace VKStraction
{
    struct EngineInfo
    {
    };

    class Engine
    {
    private:
            void InitializeVulkan();
            void CleanUp();
    public:
            Window WindowObject;

            void RunMainLoop();

            Engine();
            ~Engine();
    };
}

#endif // VKSTRACTION_H_
