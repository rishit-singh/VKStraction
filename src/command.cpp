#include "command.hpp"
#include "vulkan/vulkan_core.h"

VKStraction::CommandPoolCreateInfo::CommandPoolCreateInfo(uint32_t queueFamilyIndex, VkCommandPoolCreateFlags flags)
{
    this->mCommandPoolCreateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;

    this->mCommandPoolCreateInfo.pNext = nullptr;

    this->mCommandPoolCreateInfo.queueFamilyIndex = queueFamilyIndex;
    this->mCommandPoolCreateInfo.flags = flags;
}

VkCommandPoolCreateInfo VKStraction::CommandPoolCreateInfo::GetInstance()
{
    return this->mCommandPoolCreateInfo;
}

VkCommandBufferAllocateInfo VKStraction::CommandBufferAllocateInfo::GetInstance() {

    return this->mCommandBufferAllocateInfo;
}

VKStraction::CommandBufferAllocateInfo::CommandBufferAllocateInfo(VkCommandPool commandPool)
{
    this->mCommandBufferAllocateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    this->mCommandBufferAllocateInfo.pNext = nullptr;
    this->mCommandBufferAllocateInfo.commandPool = commandPool;
    this->mCommandBufferAllocateInfo.commandBufferCount = 1;
    this->mCommandBufferAllocateInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
}

VKStraction::Command::Command(VkDevice device, CommandPoolCreateInfo poolCreateInfo)
{
    VkCommandPoolCreateInfo createInfo = poolCreateInfo.GetInstance();
    VkCommandBufferAllocateInfo allocateInfo = {};

    VK_CHECK(vkCreateCommandPool(device, &createInfo, nullptr, &this->CommandPool));

    allocateInfo = CommandBufferAllocateInfo(this->CommandPool).GetInstance();

    VK_CHECK(vkAllocateCommandBuffers(device, &allocateInfo, &this->CommandBuffer));
}

