#ifndef VALIDATIONLAYER_H_
#define VALIDATIONLAYER_H_

#include <vector>
#include <string_view>
#include <vulkan/vulkan_core.h>
#include <util.hpp>

namespace VKStraction
{
    class ValidationLayer
    {
    private:
        std::vector<const char*> Layers;

        std::vector<VkLayerProperties> AvailableLayers;

        bool LayerExists(const char*);

        bool CheckSupport();
    public:
        void AddLayer(const char*);

        ValidationLayer() = default;
        ~ValidationLayer();
    };
}

#endif // VALIDATIONLAYER_H_
