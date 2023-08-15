#include <validationlayer.hpp>

VKStraction::ValidationLayer::ValidationLayer(VkInstanceCreateInfo *createInfo)
    : CreateInfo(createInfo) {}


VKStraction::ValidationLayer::~ValidationLayer()
{
}


void VKStraction::ValidationLayer::AddLayer(const char* layer)
{
    this->Layers.push_back(layer);
}

bool VKStraction::ValidationLayer::CheckSupport()
{
    uint32_t count;

    if (vkEnumerateInstanceLayerProperties(&count, nullptr) != VK_SUCCESS)
        throw std::runtime_error("Failed to get instance layer count.");

    this->AvailableLayers = std::vector<VkLayerProperties>(count);

    if (vkEnumerateInstanceLayerProperties(&count, this->AvailableLayers.data()) != VK_SUCCESS)
        throw std::runtime_error("Failed to get instance layer properties.");

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

void VKStraction::ValidationLayer::Enable()
{
    if (!this->CheckSupport())
            throw std::runtime_error("Validation layers not supported");

    this->CreateInfo->enabledLayerCount = this->Layers.size();
    this->CreateInfo->ppEnabledLayerNames = this->Layers.data();
}
