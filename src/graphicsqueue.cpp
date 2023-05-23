#include "graphicsqueue.hpp"

VKStraction::GraphicsQueue::GraphicsQueue(vkb::Device &device)
{
    this->mGraphicsQueue = device.get_queue(vkb::QueueType::graphics).value();
    this->QueueFamily = device.get_queue_index(vkb::QueueType::graphics).value();
}

VkQueue VKStraction::GraphicsQueue::GetQueue()
{
    return this->mGraphicsQueue;
}

uint32_t VKStraction::GraphicsQueue::GetQueueFamily()
{
    return this->QueueFamily;
}
