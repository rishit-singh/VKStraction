#ifndef DEBUG_H_
#define DEBUG_H_

#include <iostream>
#include <stdexcept>
#include <vulkan/vulkan_core.h>

VKAPI_ATTR VkResult VKAPI_CALL vkCreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger);

namespace VKStraction
{
    class DebugMessenger
    {
    private:
        PFN_vkCreateDebugUtilsMessengerEXT CreateDebugUtilsMessengerEXT;

        PFN_vkDestroyDebugUtilsMessengerEXT  DestroyDebugUtilsMEssengerEXT;

        VkDebugUtilsMessengerCreateInfoEXT CreateInfo;

        VkInstance Instance;

        PFN_vkDebugUtilsMessengerCallbackEXT Callback;

        VkDebugUtilsMessengerEXT Messenger;

        static VKAPI_ATTR VkBool32 VKAPI_CALL DefaultDebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT , VkDebugUtilsMessageTypeFlagsEXT , const VkDebugUtilsMessengerCallbackDataEXT*, void*);

        void LoadAPI();

    public:
        void GenerateCreateInfo();
        void Enable(VkInstance);
        VkDebugUtilsMessengerCreateInfoEXT* GetCreateInfo();

        DebugMessenger(PFN_vkDebugUtilsMessengerCallbackEXT = (PFN_vkDebugUtilsMessengerCallbackEXT)DefaultDebugCallback);
        ~DebugMessenger();
    };
}

#endif // DEBUG_H
