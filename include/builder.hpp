#ifndef BUILDER_H_
#define BUILDER_H_

#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>
#include <vector>
#include <stdexcept>
#include <stdlib.h>
#include <string>

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

        VkInstanceCreateInfo& GetCreateInfo();

        void GetSupportedExtensions();

        bool CheckValidationLayerSupport();
    public:
        const VkInstance& Build();

        VulkanInstance() = default;
        VulkanInstance(VkApplicationInfo*);
        ~VulkanInstance();
    };
}


#endif // BUILDER_H_
