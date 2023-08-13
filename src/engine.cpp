#include <engine.hpp>

VKStraction::Engine::Engine(std::string_view appName, Dimensions2D windowDimensions) : AppName(appName), _Window(Window(windowDimensions, appName)), Instance(nullptr)
{
    this->GetAppInfo();
    this->Instance = VulkanInstance(&this->AppInfo);

    this->Instance.Build();
}

VkApplicationInfo &VKStraction::Engine::GetAppInfo()
{
    this->AppInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    this->AppInfo.pApplicationName = this->AppName.data();
    this->AppInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    this->AppInfo.pEngineName = "VKStraction";
    this->AppInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    this->AppInfo.apiVersion = VK_API_VERSION_1_0;

    return this->AppInfo;
}

void VKStraction::Engine::Run()
{
    this->_Window.Show();
}
