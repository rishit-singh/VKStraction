#ifndef ENGINE_H_
#define ENGINE_H_

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>
#include <window.hpp>
#include <builder.hpp>

namespace VKStraction
{
   class Engine
    {
    private:
        Window _Window;

        VulkanInstance Instance;

        std::string_view AppName;

        VkApplicationInfo AppInfo;

        VkApplicationInfo& GetAppInfo();
    public:
        void Run();

        Engine(std::string_view, Dimensions2D);
        ~Engine() = default;
    };
}

#endif // ENGINE_H_
