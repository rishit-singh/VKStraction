#ifndef ERROR_H_
#define ERROR_H_

#include <iostream>

#define VK_CHECK(x)                                                 \
    do                                                              \
    {                                                               \
        VkResult err = x;                                           \
        if (err)                                                    \
        {                                                           \
            std::cout <<"Detected Vulkan error: " << err << std::endl; \
            abort();                                                \
        }                                                           \
    } while (0)

#endif // ERROR_H_
