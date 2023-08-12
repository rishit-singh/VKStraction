#include <util.hpp>


template <typename T>
int VKStraction::Util::LinearSearch(T val, std::vector<T> array) {
    for (int x = 0; x < array.size(); x++)
        if (val == array[x])
            return x;

    return -1;
}

template <>
int VKStraction::Util::LinearSearch<char*>(char *str, std::vector<char *> array)
{
    for (int x = 0; x < array.size(); x++)
        if (!strcmp(str, array[x]))
            return x;

    return -1;
}
