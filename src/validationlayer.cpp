#include "vulkan/vulkan_core.h"
#include <validationlayer.hpp>

void VKStraction::ValidationLayer::AddLayer(const char* layer)
{
    this->Layers.push_back(layer);
}

bool VKStraction::ValidationLayer::CheckSupport()
{
    uint32_t count;

    vkEnumerateInstanceLayerProperties(&count, nullptr);

    this->AvailableLayers.reserve(count);

    vkEnumerateInstanceLayerProperties(&count, this->AvailableLayers.data());

    for (int x = 0; x < this->Layers.size(); x++)
        if (!this->LayerExists(this->Layers[x]))
            return false;

    return true;
}

bool VKStraction::ValidationLayer::LayerExists(const char *layer)
{
    for (int x = 0; x < this->AvailableLayers.size(); x++)
        if (!strcmp(layer, this->AvailableLayers[x].layerName))
            return true;

    return false;
}
