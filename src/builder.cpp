#include "vulkan/vulkan_core.h"
#include <builder.hpp>

VKStraction::VulkanInstance::VulkanInstance(VkApplicationInfo* appInfo)
    : AppInfo(appInfo), Instance(nullptr)
{
    this->GetCreateInfo();
    this->Build();
}

VKStraction::VulkanInstance::~VulkanInstance()
{
   vkDestroyInstance(this->Instance, nullptr);
}

const VkInstance& VKStraction::VulkanInstance::Build()
{
    if (vkCreateInstance(&this->CreateInfo, nullptr, &this->Instance) != VK_SUCCESS)
        throw std::runtime_error("Failed to create VkInstance");

    return this->Instance;
}


VkInstanceCreateInfo &VKStraction::VulkanInstance::GetCreateInfo()
{
    this->CreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    this->CreateInfo.pApplicationInfo = this->AppInfo;

    uint32_t extensionCount = 0;

    const char** extensions = glfwGetRequiredInstanceExtensions(&extensionCount);

    this->CreateInfo.enabledExtensionCount = extensionCount;
    this->CreateInfo.ppEnabledExtensionNames = extensions;
    this->CreateInfo.enabledLayerCount = 0;

    return this->CreateInfo;
}
