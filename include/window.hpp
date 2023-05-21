#ifndef WINDOW_H_
#define WINDOW_H_

#include <string_view>
#include "vertex.hpp"


#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

namespace VKStraction
{
    class Window
    {
    protected:
        SDL_Window* mWindow;

    public:
        std::string_view Title;

        Vector2D Dimensions;

        SDL_Event WindowEvent;

        void Initialize();

        SDL_Event& PollEvents();

        Window(std::string_view, Vector2D, bool = false);
        ~Window();
    };
}

#endif // WINDOW_H_
