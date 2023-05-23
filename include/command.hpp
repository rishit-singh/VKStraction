#ifndef COMMAND_H_
#define COMMAND_H_

#include "vulkan/vulkan_core.h"
#include "error.hpp"

namespace VKStraction
{
    class CommandPoolCreateInfo
    {
    protected:
        VkCommandPoolCreateInfo mCommandPoolCreateInfo;

    public:
            VkCommandPoolCreateInfo GetInstance();

            CommandPoolCreateInfo(uint32_t, VkCommandPoolCreateFlags = 0);
    };

    class CommandBufferAllocateInfo
    {
    protected:
        VkCommandBufferAllocateInfo mCommandBufferAllocateInfo;

    public:
            VkCommandBufferAllocateInfo GetInstance();

            CommandBufferAllocateInfo(VkCommandPool);
    };


    class Command
    {
    public:
            VkCommandPool CommandPool;

            VkCommandBuffer CommandBuffer;

            void Destroy();

            Command() = default;
            Command(VkDevice, CommandPoolCreateInfo);
            virtual ~Command() = default;
    };
}

#endif // COMMAND_H_
