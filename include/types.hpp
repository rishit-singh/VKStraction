#ifndef TYPES_H_
#define TYPES_H_

namespace VKStraction
{

    /*
     * Stores 2D vectors.
     * */
    struct Vector2D
    {
    public:
            double X;

            double Y;

            Vector2D(double = 0.0f, double = 0.0f);
    };
}

#endif // TYPES_H_
