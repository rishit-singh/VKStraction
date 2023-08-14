#include <debug.hpp>

VKStraction::DebugMessenger::DebugMessenger()
{}

VKStraction::DebugMessenger::DebugMessenger(VkInstance instance, PFN_vkDebugUtilsMessengerCallbackEXT callback)
{
    this->Instance = instance;
    this->Callback = callback;

    this->GenerateCreateInfo();
}

VKStraction::DebugMessenger::~DebugMessenger()
{
    vkDestroyDebugUtilsMessengerEXT(this->Instance, this->Messenger, nullptr);
}

void VKStraction::DebugMessenger::GenerateCreateInfo()
{
    this->CreateInfo = {};
    this->CreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
    this->CreateInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    this->CreateInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;

    this->CreateInfo.pfnUserCallback = this->Callback;
}

VkDebugUtilsMessengerCreateInfoEXT* VKStraction::DebugMessenger::GetCreateInfo()
{
    return &this->CreateInfo;
}

void VKStraction::DebugMessenger::Enable()
{
    if (vkCreateDebugUtilsMessengerEXT(this->Instance, &this->CreateInfo, nullptr,  &this->Messenger) != VK_SUCCESS)
        throw std::runtime_error("Failed to initialize debug messenger. ");
}

VKAPI_ATTR VkBool32 VKAPI_CALL VKStraction::DebugMessenger::DefaultDebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT severity, VkDebugUtilsMessageTypeFlagsEXT type, const VkDebugUtilsMessengerCallbackDataEXT* callbackData, void* userData)
{
    std::cerr << "Validation Layer Log: " << callbackData->pMessage << '\n';

    return VK_FALSE;
}
