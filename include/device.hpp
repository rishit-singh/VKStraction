#ifndef DEVICE_H_
#define DEVICE_H_

#include <vulkan/vulkan_core.h>
#include <vector>
#include <optional>
#include <stdexcept>


namespace VKStraction
{
    class PhysicalDevice
    {
    private:
        VkPhysicalDeviceProperties Properties;

        VkPhysicalDeviceFeatures Features;

        void Initialize();

        std::optional<uint32_t> GetQueueFamilyIndices();

    public:
        VkPhysicalDevice Device;

        bool IsSuitable();

        PhysicalDevice();
        PhysicalDevice(VkPhysicalDevice);
        ~PhysicalDevice();
    };

    class PhysicalDeviceManager
    {
    private:
        PhysicalDevice Device;

        VkInstance Instance;

        std::vector<PhysicalDevice> Devices;

        void FetchDevices();

        void ChooseDevice();

    public:
        const PhysicalDevice& GetSuitableDevice();

        PhysicalDeviceManager(VkInstance);
        ~PhysicalDeviceManager();
    };
}

#endif // DEVICE_H_
