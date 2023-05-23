#include "vulkancontext.hpp"
#include "VkBootstrap.h"
#include "command.hpp"
#include "graphicsqueue.hpp"
#include "vulkan/vulkan_core.h"

VKStraction::VulkanContext::VulkanContext(Window& window, std::string_view appName)
{
    vkb::Instance builder = vkb::InstanceBuilder()
                        .set_app_name(appName.data())
                        .request_validation_layers(true)
                        .require_api_version(1, 1, 0)
                        .use_default_debug_messenger()
                        .build().value();


    this->Instance = builder.instance;
    this->DebugLogger = builder.debug_messenger;

    SDL_Vulkan_CreateSurface(window.GetInstance(), this->Instance, &this->Surface);


    vkb::PhysicalDevice selector = vkb::PhysicalDeviceSelector(builder)
        .set_minimum_version(1, 1)
        .set_surface(this->Surface)
        .select()
        .value();

    vkb::Device deviceBuilder = vkb::DeviceBuilder(selector)
        .build()
        .value();

    this->Device = deviceBuilder.device;
    this->CurrentGPU = deviceBuilder.physical_device;


    this->Queue = GraphicsQueue(deviceBuilder);

    this->SwapchainInstance = Swapchain(this->CurrentGPU, this->Device, this->Surface, window.Dimensions);

    this->CommandInstance = Command(this->Device, CommandPoolCreateInfo(this->Queue.GetQueueFamily(), VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT));
}

VKStraction::VulkanContext::~VulkanContext()
{

    vkDestroyCommandPool(this->Device, this->CommandInstance.CommandPool, nullptr);

    this->SwapchainInstance.Destroy();

    vkDestroyDevice(this->Device, nullptr);

    vkDestroySurfaceKHR(this->Instance, this->Surface, nullptr);

    vkb::destroy_debug_utils_messenger(this->Instance, this->DebugLogger);

    vkDestroyInstance(this->Instance, nullptr);
}
