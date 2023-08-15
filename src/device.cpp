#include "vulkan/vulkan_core.h"
#include <device.hpp>

VKStraction::PhysicalDevice::PhysicalDevice()
{}

VKStraction::PhysicalDevice::PhysicalDevice(VkPhysicalDevice device)
    : Device(device)
{
    this->Initialize();
}


VKStraction::PhysicalDeviceManager::PhysicalDeviceManager(VkInstance instance)
    : Instance(instance)
{
    this->FetchDevices();
    this->ChooseDevice();
}

VKStraction::PhysicalDeviceManager::~PhysicalDeviceManager() {}

void VKStraction::PhysicalDeviceManager::FetchDevices()
{
    uint32_t count;

    std::vector<VkPhysicalDevice> devices;

    if (vkEnumeratePhysicalDevices(this->Instance, &count, nullptr) != VK_SUCCESS)
        throw std::runtime_error("Failed enumerate phyical device count.");

    devices.reserve(count);

    if (vkEnumeratePhysicalDevices(this->Instance, &count, devices.data()) != VK_SUCCESS)
        throw std::runtime_error("Failed enumerate phyical devices.");

    this->Devices.reserve(count);

    for (int x = 0; x < devices.size(); x++)
        this->Devices[x] = PhysicalDevice(devices[x]);
}

void VKStraction::PhysicalDeviceManager::ChooseDevice()
{
    for (int x = 0; x < this->Devices.size(); x++)
        if (this->Devices[x].IsSuitable())
        {
            this->Device = this->Devices[x];
            return;
        }

    throw std::runtime_error("No suitable device found.");
}

void VKStraction::PhysicalDevice::Initialize()
{
    vkGetPhysicalDeviceProperties(this->Device, &this->Properties);
    vkGetPhysicalDeviceFeatures(this->Device, &this->Features);
}

bool VKStraction::PhysicalDevice::IsSuitable()
{
  // return (this->Properties.deviceType ==
  //         VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU &&
  //         this->Features.geometryShader);

    return this->GetQueueFamilyIndices().has_value();
}


std::optional<uint32_t> VKStraction::PhysicalDevice::GetQueueFamilyIndices()
{
    std::optional<uint32_t> index;

    std::vector<VkQueueFamilyProperties> queueFamilies;

    uint32_t count;

    vkGetPhysicalDeviceQueueFamilyProperties(this->Device, &count, nullptr);
    queueFamilies.reserve(count);
    vkGetPhysicalDeviceQueueFamilyProperties(this->Device, &count, queueFamilies.data());


    for (uint32_t x = 0; x < queueFamilies.size(); x++)
        if (queueFamilies[x].queueFlags & VK_QUEUE_GRAPHICS_BIT)
            index = x;

    return index;
}
