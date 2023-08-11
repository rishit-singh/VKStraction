#ifndef WINDOW_H_
#define WINDOW_H_

#include <GLFW/glfw3.h>
#include <initializer_list>
#include <string_view>

namespace VKStraction
{
    struct Dimensions2D
    {
        uint32_t Height;
        uint32_t Width;

        Dimensions2D(uint32_t, uint32_t);

        Dimensions2D(std::initializer_list<uint32_t>);

        Dimensions2D& operator =(std::initializer_list<uint32_t>);
    };

    class Window
    {
    private:
        GLFWwindow* _Window;

        Dimensions2D Dimensions;

        std::string_view Title;

    public:
        void Show();

        Window(Dimensions2D, std::string_view);
        ~Window();
    };
}
#endif // WINDOW_H_
