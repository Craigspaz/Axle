#include <iostream>
#include <assert.h>
#include "Menu-UI/Label.h"

// Tests Getters and Setters
int Label_Test_001()
{
    std::string testText = "Hello World";
    glm::vec3 testPosition(1,2,3);
    glm::vec3 testRotation(4,5,6);
    glm::vec3 testScale(7,8,9);
    bool testVisible = false;
    bool testDisabled = true;
    Label testLabel(testText, testPosition, testRotation, testScale, testVisible, testDisabled);

    if (testLabel.getText().compare(testText) != 0 || testLabel.getPosition() != testPosition || testLabel.getRotation() != testRotation || testLabel.getScale() != testScale || testLabel.isVisible() != testVisible || testLabel.isDisabled() != testDisabled)
    {
        std::cerr << "Label_Test_001 failed with constructor values tested with getters and setters" << std::endl;
        return 0;
    }

    testLabel.setIsDisabled(false);
    if(testLabel.isDisabled() != false)
    {
        std::cerr << "Label_Test_001 failed. The setIsDisabled setter and isDisabled getter did not match as expected" << std::endl;
        return 0;
    }

    testLabel.setIsVisible(true);

    if(testLabel.isVisible() != true)
    {
        std::cerr << "Label_Test_001 failed. The setIsVisible setter and isVisible getter did not match as expected" << std::endl;
        return 0;
    }

    testLabel.setText("Hello World Again");
    if(testLabel.getText().compare("Hello World Again") != 0)
    {
        std::cerr << "Label_Test_001 failed. The setText setter and getText getter did not match as expected" << std::endl;
        return 0;
    }

    std::cout << "Label_Test_001 Passed" << std::endl;
    return 1;
}

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

    int numberOfTests = 1;
    int numberOfTestsPassed = 0;

    numberOfTestsPassed += Label_Test_001();


    std::cout << "Results: " << numberOfTestsPassed << "/" << numberOfTests << " Passed!" << std::endl;
}