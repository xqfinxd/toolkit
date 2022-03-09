#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

#include "vulkan/vulkan.h"

int main(int argc, char** argv) {
    VkInstance instance;
    vkCreateInstance(nullptr, nullptr, &instance);
    const char* str = "-100a";

    char* pos = nullptr;
    int num = strtol(str, &pos, 10);
    
    std::cout << std::addressof(str) << std::endl;
    std::cout << std::addressof(pos) << std::endl;
    #ifdef _DASSERT
    std::cout << strlen(pos) << _DASSERT << std::endl;
    #endif
	std::cout << num << std::endl;

	return 0;
}