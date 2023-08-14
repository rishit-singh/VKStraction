#ifndef DEBUG_H_
#define DEBUG_H_

#include <iostream>
#include <stdexcept>
#include <vulkan/vulkan_core.h>

namespace VKStraction
{
    class DebugMessenger
    {
    private:

        VkDebugUtilsMessengerCreateInfoEXT CreateInfo;

        VkInstance Instance;

        PFN_vkDebugUtilsMessengerCallbackEXT Callback;

        VkDebugUtilsMessengerEXT Messenger;

        static VKAPI_ATTR VkBool32 VKAPI_CALL DefaultDebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT , VkDebugUtilsMessageTypeFlagsEXT , const VkDebugUtilsMessengerCallbackDataEXT*, void*);

        void GenerateCreateInfo();

    public:
        void Enable();
        VkDebugUtilsMessengerCreateInfoEXT* GetCreateInfo();

        DebugMessenger();
        DebugMessenger(VkInstance, PFN_vkDebugUtilsMessengerCallbackEXT = (PFN_vkDebugUtilsMessengerCallbackEXT)DefaultDebugCallback);
        ~DebugMessenger();
    };
}

#endif // DEBUG_H_
