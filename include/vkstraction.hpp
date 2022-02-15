#ifndef VKSTRACTION_H_
#define VKSTRACTION_H_

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <string>

namespace VKStraction
{
    struct EngineInfo
    {};

    class Engine
    {
    private:
            GLFWwindow* Window;

            void InitializeWindow();
            void InitializeVulkan();
            void CleanUp();
    public:
            void RunMainLoop();

            Engine();
            ~Engine();
    };
}

#endif // VKSTRACTION_H_
