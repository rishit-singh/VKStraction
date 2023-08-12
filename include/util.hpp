#ifndef UTIL_H_
#define UTIL_H_

#include <vector>
#include <cstring>
#include <cstdlib>

namespace VKStraction::Util
{
    template<typename T>
    int LinearSearch(T, std::vector<T>);

    template<>
    int LinearSearch<char*>(char*, std::vector<char*>);
}

#endif // UTIL_H_
