#include <builder.hpp>

VKStraction::VulkanInstance::VulkanInstance(VkApplicationInfo* appInfo)
    : AppInfo(appInfo), Instance(nullptr), EnableValidationLayers(true), ValidationLayers(ValidationLayer(nullptr))
{
    if (this->EnableValidationLayers)
        this->ValidationLayers = ValidationLayer(&this->CreateInfo);
}

VKStraction::VulkanInstance::~VulkanInstance()
{
   vkDestroyInstance(this->Instance, nullptr);
}

const VkInstance& VKStraction::VulkanInstance::Build()
{
    this->GetCreateInfo();

    if (vkCreateInstance(&this->CreateInfo, nullptr, &this->Instance) != VK_SUCCESS)
        throw std::runtime_error("Failed to create VkInstance");

    return this->Instance;
}

void VKStraction::VulkanInstance::GetSupportedExtensions()
{
    uint32_t count;

    vkEnumerateInstanceExtensionProperties(nullptr, &count, this->SupportedExtensions.data());
}

VkInstanceCreateInfo &VKStraction::VulkanInstance::GetCreateInfo()
{
    this->CreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    this->CreateInfo.pApplicationInfo = this->AppInfo;

    uint32_t extensionCount = 0;

    const char** extensionBuffer = glfwGetRequiredInstanceExtensions(&extensionCount);

    this->EnabledExtensions = std::vector<const char*>(extensionBuffer, extensionBuffer + extensionCount);

    this->EnabledExtensions.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);

    #ifdef DEBUG
    this->EnabledExtensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    #endif

    this->CreateInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;

    this->CreateInfo.enabledExtensionCount = this->EnabledExtensions.size();
    this->CreateInfo.ppEnabledExtensionNames = this->EnabledExtensions.data();
    this->CreateInfo.enabledLayerCount = 0;

    return this->CreateInfo;
}

