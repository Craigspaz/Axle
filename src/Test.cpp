#include <iostream>

#if defined(_WIN32)
    #define PLATFORM_NAME "windows"
    int WinMain()
#elif defined(_WIN64)
    #define PLATFORM_NAME "windows"
    int WinMain()
#elif defined(__linux__)
    #define PLATFORM_NAME "linux"
    int main()
#elif defined(__APPLE__)
    #define PLATFORM_NAME "apple"
    int main()
#else
    #define PLATFORM_NAME NULL
    int main()
#endif
{
    if (PLATFORM_NAME != NULL)
    {
        std::cout << "You are currently running on the supported platform: " << PLATFORM_NAME << std::endl;
    }
    else
    {
        std::cout << "You are currently running on an  unsupported platform!" << std::endl;
    }

    // TODO: Do Stuff
}