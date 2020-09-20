#include <iostream>
#include <assert.h>
#include "Menu-UI/Label.h"

// Tests Getters and Setters
int Label_Test_001()
{
    std::string testText = "Hello World";
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;
    Label testLabel(testText, testPosition, testRotation, testScale, testVisible, testDisabled);

    if (testLabel.getText().compare(testText) != 0 || testLabel.getPosition() != testPosition || testLabel.getRotation() != testRotation || testLabel.getScale() != testScale || testLabel.isVisible() != testVisible || testLabel.isDisabled() != testDisabled)
    {
        std::cerr << "Label_Test_001 failed with constructor values tested with getters and setters" << std::endl;
        return 0;
    }

    testLabel.setIsDisabled(false);
    if (testLabel.isDisabled() != false)
    {
        std::cerr << "Label_Test_001 failed. The setIsDisabled setter and isDisabled getter did not match as expected" << std::endl;
        return 0;
    }

    testLabel.setIsVisible(true);

    if (testLabel.isVisible() != true)
    {
        std::cerr << "Label_Test_001 failed. The setIsVisible setter and isVisible getter did not match as expected" << std::endl;
        return 0;
    }

    testLabel.setText("Hello World Again");
    if (testLabel.getText().compare("Hello World Again") != 0)
    {
        std::cerr << "Label_Test_001 failed. The setText setter and getText getter did not match as expected" << std::endl;
        return 0;
    }

    std::cout << "Label_Test_001 Passed" << std::endl;
    return 1;
}

// Tests Label Operator ==
int Label_Test_002()
{
    std::string testText = "Hello World";
    std::string testText1 = "Hello World!";
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;
    Label testLabel(testText, testPosition, testRotation, testScale, testVisible, testDisabled);
    Label testLabel2(testText, testPosition, testRotation, testScale, testVisible, testDisabled);
    Label testLabel3(testText1, testPosition, testRotation, testScale, testVisible, testDisabled);
    glm::vec3 testPosition1(1, 2, 4);
    Label testLabel4(testText, testPosition1, testRotation, testScale, testVisible, testDisabled);
    glm::vec3 testPosition2(1, 2, 3);
    Label testLabel5(testText, testPosition2, testRotation, testScale, testVisible, testDisabled);

    if (testLabel == testLabel)
    {
    }
    else
    {
        std::cerr << "Label does not equal itself!" << std::endl;
        return 0;
    }

    if (testLabel == testLabel2)
    {
    }
    else
    {
        std::cerr << "Label does not equal label with same details!" << std::endl;
        return 0;
    }

    if (testLabel == testLabel3)
    {
        std::cerr << "Labels with different text were found to match!" << std::endl;
        return 0;
    }

    if (testLabel == testLabel4)
    {
        std::cerr << "Labels with different position were found to match" << std::endl;
        return 0;
    }

    if (testLabel == testLabel5)
    {
    }
    else
    {
        std::cerr << "Labels with different position objects but same values did not match" << std::endl;
        return 0;
    }

    std::cout << "Label_Test_002 Passed" << std::endl;
    return 1;
}

// Tests Label Operator !=
int Label_Test_003()
{
    std::string testText = "Hello World";
    std::string testText1 = "Hello World!";
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;
    Label testLabel(testText, testPosition, testRotation, testScale, testVisible, testDisabled);
    Label testLabel2(testText, testPosition, testRotation, testScale, testVisible, testDisabled);
    Label testLabel3(testText1, testPosition, testRotation, testScale, testVisible, testDisabled);
    glm::vec3 testPosition1(1, 2, 4);
    Label testLabel4(testText, testPosition1, testRotation, testScale, testVisible, testDisabled);
    glm::vec3 testPosition2(1, 2, 3);
    Label testLabel5(testText, testPosition2, testRotation, testScale, testVisible, testDisabled);

    if (testLabel != testLabel)
    {
        std::cerr << "Label did not equal itself" << std::endl;
        return 0;
    }

    if (testLabel != testLabel2)
    {
        std::cerr << "Labels that are equal were found to be different" << std::endl;
        return 0;
    }

    if (testLabel != testLabel3)
    {
    }
    else
    {
        std::cerr << "Labels with different text were found to be equal" << std::endl;
        return 0;
    }

    if (testLabel != testLabel4)
    {
    }
    else
    {
        std::cerr << "Labels with different position were found to be equal" << std::endl;
        return 0;
    }

    if (testLabel != testLabel5)
    {
        std::cerr << "Labels with different position objects were found to be different" << std::endl;
        return 0;
    }

    std::cout << "Label_Test_003 Passed" << std::endl;
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

    int numberOfTests = 3;
    int numberOfTestsPassed = 0;

    numberOfTestsPassed += Label_Test_001();
    numberOfTestsPassed += Label_Test_002();
    numberOfTestsPassed += Label_Test_003();

    std::cout << "Results: " << numberOfTestsPassed << "/" << numberOfTests << " Passed!" << std::endl;
}