#include "swapchain.hpp"
#include "VkBootstrap.h"
#include "vulkan/vulkan_core.h"

VKStraction::Swapchain::Swapchain()
{}

VKStraction::Swapchain::Swapchain(VkPhysicalDevice currentGPU, VkDevice device, VkSurfaceKHR surface, Vector2D dimensions, VkPresentModeKHR presentMode)
    : Device(device), PresentMode(presentMode)
{
    vkb::Swapchain builder = vkb::SwapchainBuilder(currentGPU, device, surface)
        .use_default_format_selection()
        .set_desired_present_mode(this->PresentMode)
        .set_desired_extent(dimensions.X, dimensions.Y)
        .build()
        .value();

    this->mSwapchain = builder.swapchain;
    this->Images = builder.get_images().value();
    this->ImageViews = builder.get_image_views().value();
    this->ImageFormat = builder.image_format;
}

VKStraction::Swapchain::~Swapchain()
{
}

void VKStraction::Swapchain::Destroy()
{
    vkDestroySwapchainKHR(this->Device, this->mSwapchain, nullptr);

    for (int x = 0; x < this->ImageViews.size(); x++)
        vkDestroyImageView(this->Device, this->ImageViews[x], nullptr);
}
