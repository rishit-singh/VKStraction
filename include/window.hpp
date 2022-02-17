#ifndef WINDOW_H_
#define WINDOW_H_

#include <GLFW/glfw3.h>
#include <string>
#include "types.hpp"

namespace VKStraction
{
    typedef Vector2D<int> WindowResolution;

    class Window
    {
    private:
        void Delete();

    public:
        std::string Title;

        GLFWwindow* GLFWWindowObject;

        WindowResolution Resolution;

        void Initialize();

        Window();
        ~Window();
    };
}

#endif // WINDOW_H_
