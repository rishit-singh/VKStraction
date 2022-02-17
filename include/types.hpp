#ifndef TYPES_H_
#define TYPES_H_

namespace VKStraction
{
    template<typename T>
    struct Vector2D
    {
    public:
            T X, Y;

            Vector2D(T x, T y) : X(x), Y(y)
            {
            }
    };
}

#endif // TYPES_H_
