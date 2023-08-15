#include "debug.hpp"
#include "validationlayer.hpp"
#include <builder.hpp>
#include <stdexcept>


VKStraction::VulkanInstance::VulkanInstance(VkApplicationInfo* appInfo)
    : AppInfo(appInfo), Instance(nullptr), EnableValidationLayers(false), ValidationLayers(ValidationLayer(nullptr)), Messenger(DebugMessenger())
{
    #ifdef DEBUG
    std::cout << "Debug enabled\n";
    this->EnableValidationLayers = true;
    #endif

    if (this->EnableValidationLayers)
    {
        this->ValidationLayers = ValidationLayer(&this->CreateInfo);
        this->ValidationLayers.Enable();
    }
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

    if (this->EnableValidationLayers)
         this->Messenger.Enable(this->Instance);

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

    if (this->EnableValidationLayers)
    {
        this->EnabledExtensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
        this->ValidationLayers = ValidationLayer(&this->CreateInfo);

        this->ValidationLayers.AddLayer("VK_LAYER_KHRONOS_validation");
    }

    this->CreateInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;

    this->CreateInfo.enabledExtensionCount = this->EnabledExtensions.size();
    this->CreateInfo.ppEnabledExtensionNames = this->EnabledExtensions.data();

    if (this->EnableValidationLayers)
    {
        this->ValidationLayers.Enable();
        this->CreateInfo.pNext = this->Messenger.GetCreateInfo();
    }
    else
    {
        this->CreateInfo.enabledLayerCount = 0;
        this->CreateInfo.pNext = nullptr;
    }

    return this->CreateInfo;
}

