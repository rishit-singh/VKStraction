#ifndef WINDOW_H_
#define WINDOW_H_

#include <string_view>
#include "types.hpp"


#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

namespace VKStraction
{
    class Window
    {
    private:
        void Delete();

        SDL_Window* mWindow;

    public:
        std::string_view Title;

        void Initialize();

        Window();
        ~Window();
    };
}

#endif // WINDOW_H_
