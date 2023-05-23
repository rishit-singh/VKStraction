#ifndef GRAPHICSQUEUE_H_
#define GRAPHICSQUEUE_H_


#include <vulkan/vulkan_core.h>
#include "VkBootstrap.h"

namespace VKStraction
{
    class GraphicsQueue
    {
    protected:
            VkQueue mGraphicsQueue;

            uint32_t QueueFamily;
    public:
            VkQueue GetQueue();

            uint32_t GetQueueFamily();

            GraphicsQueue() = default;
            GraphicsQueue(vkb::Device&);
            virtual ~GraphicsQueue() = default;
    };
}

#endif // GRAPHICSQUEUE_H_
