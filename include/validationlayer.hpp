#ifndef VALIDATIONLAYER_H_
#define VALIDATIONLAYER_H_

#include <vector>
#include <string_view>
#include <vulkan/vulkan_core.h>
#include <util.hpp>
#include <iostream>

namespace VKStraction
{
    class ValidationLayer
    {
    private:
        std::vector<const char*> Layers;

        std::vector<VkLayerProperties> AvailableLayers;

        VkInstanceCreateInfo* CreateInfo;

        bool LayerExists(const char*);

        bool CheckSupport();

    public:
        void AddLayer(const char*);
        void Enable();

        ValidationLayer(VkInstanceCreateInfo*);
        ~ValidationLayer();
    };
}

#endif // VALIDATIONLAYER_H_
