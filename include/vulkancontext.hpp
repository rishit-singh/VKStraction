#ifndef VULKANCONTEXT_H_
#define VULKANCONTEXT_H_

// #include <vk_types.h>
// #include <vk_initializers.h>

#include <string_view>
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>
#include "VkBootstrap.h"
#include "swapchain.hpp"
#include "vulkan/vulkan_core.h"
#include "swapchain.hpp"
#include "graphicsqueue.hpp"
#include "command.hpp"

namespace VKStraction
{
    class VulkanContext
    {
    public:
            VkInstance Instance;

            VkDebugUtilsMessengerEXT DebugLogger;

            VkPhysicalDevice CurrentGPU;

            VkDevice Device;

            VkSurfaceKHR Surface;

            VkCommandPool CommandPool;

            VkCommandBuffer CommandBuffer;

            Swapchain SwapchainInstance;

            GraphicsQueue Queue;

            Command CommandInstance;

            void Initialize();

            VulkanContext() = default;
            VulkanContext(Window&, std::string_view);

            virtual ~VulkanContext();
    };
}

#endif // VULKANCONTEXT_H_
