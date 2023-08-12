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

    const char** extensionBuffer = glfwGetRequiredInstanceExtensions(&extensionCount);

    for (int x = 0; x < extensionCount; x++)
        this->Extensions.push_back(extensionBuffer[x]);

    this->Extensions.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);

    this->CreateInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;

    this->CreateInfo.enabledExtensionCount = extensionCount;
    this->CreateInfo.ppEnabledExtensionNames = this->Extensions.data();
    this->CreateInfo.enabledLayerCount = 0;

    return this->CreateInfo;
}
