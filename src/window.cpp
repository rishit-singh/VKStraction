#include <GLFW/glfw3.h>
#include <window.hpp>

VKStraction::Dimensions2D::Dimensions2D(uint32_t height, uint32_t width)
    : Height(height), Width(width) {}

VKStraction::Dimensions2D::Dimensions2D(std::initializer_list<uint32_t> initList)
{
    *this = initList;
}

VKStraction::Dimensions2D& VKStraction::Dimensions2D::operator =(std::initializer_list<uint32_t> initList)
{
    if (initList.size() <= 0)
    {
        this->Height = 0;
        this->Width = 0;

        return *this;
    }

    const unsigned int* begin = initList.begin();

    this->Height = *begin;

    if ((begin + 1))
        this->Width = *(begin + 1);
    else
        this->Width = 0;

    return *this;
}

VKStraction::Window::Window(Dimensions2D dimensions, std::string_view title)
    : Dimensions(dimensions), Title(title)
{
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    this->_Window = glfwCreateWindow(dimensions.Width, dimensions.Height, title.data(), nullptr, nullptr);
}

VKStraction::Window::~Window()
{
    glfwDestroyWindow(this->_Window);
    glfwTerminate();
}

void VKStraction::Window::Show()
{
    glfwMakeContextCurrent(this->_Window);

    while (!glfwWindowShouldClose(this->_Window))
    {
        glfwPollEvents();
    }
}
