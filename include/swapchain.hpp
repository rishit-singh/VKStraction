#ifndef SWAPCHAIN_H_
#define SWAPCHAIN_H_

#include <vector>
#include "VkBootstrap.h"
#include "vertex.hpp"
#include "vulkan/vulkan_core.h"
#include "window.hpp"

namespace VKStraction
{
    class Swapchain
    {
    protected:
        VkSwapchainKHR mSwapchain;

        VkDevice Device;

    public:
        VkFormat ImageFormat;

        VkPresentModeKHR PresentMode;

        std::vector<VkImage> Images;

        std::vector<VkImageView> ImageViews;

        void Destroy();

        VkSwapchainKHR GetInstance();

        Swapchain();
        Swapchain(VkPhysicalDevice, VkDevice, VkSurfaceKHR, Vector2D, VkPresentModeKHR = VK_PRESENT_MODE_FIFO_KHR);
        virtual ~Swapchain();
    };
}


#endif // SWAPCHAIN_H_
