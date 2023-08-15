#ifndef BUILDER_H_
#define BUILDER_H_

#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include <validationlayer.hpp>
#include <debug.hpp>
#include <vector>
#include <stdexcept>
#include <stdlib.h>
#include <string>

#define DEBUG

namespace VKStraction
{
    class VulkanInstance
    {
    private:
        VkInstance Instance;

        VkApplicationInfo* AppInfo;

        VkInstanceCreateInfo CreateInfo;

        std::vector<const char*> EnabledExtensions;

        std::vector<VkExtensionProperties> SupportedExtensions;

        ValidationLayer ValidationLayers;

        DebugMessenger Messenger;

        VkInstanceCreateInfo& GetCreateInfo();

        void GetSupportedExtensions();

        bool CheckValidationLayerSupport();

        bool EnableValidationLayers;
    public:
        const VkInstance& Build();

        VulkanInstance(VkApplicationInfo*);
        ~VulkanInstance();
    };
}


#endif // BUILDER_H_
