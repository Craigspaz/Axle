#include <iostream>
#include <assert.h>
#include "Menu-UI/Label.h"
#include "Menu-UI/Button.h"

// Tests Label Getters and Setters
int Label_Test_001()
{
    std::string testText = "Hello World";
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;
    Label testLabel(testText, testPosition, testRotation, testScale, testVisible, testDisabled);

    // Tests constructor input and getters
    if (testLabel.getText().compare(testText) != 0 || testLabel.getPosition() != testPosition || testLabel.getRotation() != testRotation || testLabel.getScale() != testScale || testLabel.isVisible() != testVisible || testLabel.isDisabled() != testDisabled)
    {
        std::cerr << "Label_Test_001 failed with constructor values tested with getters and setters" << std::endl;
        return 0;
    }

    // Tests setIsDisabled setter
    testLabel.setIsDisabled(false);
    if (testLabel.isDisabled() != false)
    {
        std::cerr << "Label_Test_001 failed. The setIsDisabled setter and isDisabled getter did not match as expected" << std::endl;
        return 0;
    }

    // Tests setIsVisible setter
    testLabel.setIsVisible(true);
    if (testLabel.isVisible() != true)
    {
        std::cerr << "Label_Test_001 failed. The setIsVisible setter and isVisible getter did not match as expected" << std::endl;
        return 0;
    }

    // Tests setText setter
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

    glm::vec3 testRotation2(4, 5, 7);
    Label testLabel6(testText, testPosition, testRotation2, testScale, testVisible, testDisabled);

    glm::vec3 testScale2(7, 8, 19);
    Label testLabel7(testText, testPosition, testRotation, testScale2, testVisible, testDisabled);

    Label testLabel8(testText, testPosition, testRotation, testScale2, true, testDisabled);

    Label testLabel9(testText, testPosition, testRotation, testScale2, testVisible, false);

    // Tests to see if label is equal to itself
    if (testLabel == testLabel)
    {
    }
    else
    {
        std::cerr << "Label_Test_002 failed. Label does not equal itself!" << std::endl;
        return 0;
    }

    // Tests if label is equal to label with same text but different object
    if (testLabel == testLabel2)
    {
    }
    else
    {
        std::cerr << "Label_Test_002 failed. Label does not equal label with same details!" << std::endl;
        return 0;
    }

    // Tests labels with different text don't equal
    if (testLabel == testLabel3)
    {
        std::cerr << "Label_Test_002 failed. Labels with different text were found to match!" << std::endl;
        return 0;
    }

    // Tests labels with different positions don't equal
    if (testLabel == testLabel4)
    {
        std::cerr << "Label_Test_002 failed. Labels with different position were found to match" << std::endl;
        return 0;
    }

    // Tests labels with different position objects equal if their positions are the same
    if (testLabel == testLabel5)
    {
    }
    else
    {
        std::cerr << "Label_Test_002 failed. Labels with different position objects but same values did not match" << std::endl;
        return 0;
    }

    // Tests labels with different rotations equal if their rotations are the same
    if (testLabel == testLabel6)
    {
        std::cerr << "Label_Test_002 failed. Labels with different rotations were found to be equal" << std::endl;
        return 0;
    }

    // Tests labels with different scales equal if their scales are the same
    if (testLabel == testLabel7)
    {
        std::cerr << "Label_Test_002 failed. Labels with different scales were found to be equal" << std::endl;
        return 0;
    }

    // Tests labels with different visibility equal if their visibility is the same
    if (testLabel == testLabel8)
    {
        std::cerr << "Label_Test_002 failed. Labels with different visibilities were found to be equal" << std::endl;
        return 0;
    }

    // Tests labels with different disabled states equal if their disabled state are the same
    if (testLabel == testLabel9)
    {
        std::cerr << "Label_Test_002 failed. Labels with different disabled states were found to be equal" << std::endl;
        return 0;
    }

    std::cout << "Label_Test_002 Passed" << std::endl;
    return 1;
}

// Tests Label Operator != (Note this is the inverse of the == so doing minimal tests)
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

    // Tests labels to confirm labels should equal themselves
    if (testLabel != testLabel)
    {
        std::cerr << "Label_Test_003 failed. Label did not equal itself" << std::endl;
        return 0;
    }

    // Tests labels to confirm equal labels are found to be equal
    if (testLabel != testLabel2)
    {
        std::cerr << "Label_Test_003 failed. Labels that are equal were found to be different" << std::endl;
        return 0;
    }

    // Tests labels with different text are found to be different
    if (testLabel != testLabel3)
    {
    }
    else
    {
        std::cerr << "Label_Test_003 failed. Labels with different text were found to be equal" << std::endl;
        return 0;
    }

    std::cout << "Label_Test_003 Passed" << std::endl;
    return 1;
}

// Tests Button Getters and Setters
int Button_Test_001()
{
    std::string testText = "Hello World";
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    Button button(testText, testPosition, testRotation, testScale, testVisible, testDisabled);

    // Tests if Button constructor and getters work as intented
    if (button.getText().compare(testText) != 0 || button.getPosition() != testPosition || button.getRotation() != testRotation || button.getScale() != testScale || button.isVisible() != testVisible || button.isDisabled() != testDisabled)
    {
        std::cerr << "Button_Test_001 failed with constructor values tested with getters and setters" << std::endl;
        return 0;
    }

    // Tests button setText setter
    testText = "Hello World!";
    button.setText(testText);
    if (button.getText().compare("Hello World!") != 0)
    {
        std::cerr << "Button_Test_001 failed with setText" << std::endl;
        return 0;
    }

    // Tests button setPosition
    glm::vec3 testPosition2(1, 2, 4);
    button.setPosition(testPosition2);
    if (button.getPosition() == testPosition)
    {
        std::cerr << "Button_Test_001 failed. setPosition failed" << std::endl;
        return 0;
    }

    // Tests button setRotation
    glm::vec3 testRotation2(4, 5, 7);
    button.setRotation(testRotation2);
    if (button.getRotation() == testRotation)
    {
        std::cerr << "Button_Test_001 failed. setRotation failed" << std::endl;
        return 0;
    }

    // Tests button setScale
    glm::vec3 testScale2(7, 8, 10);
    button.setScale(testScale2);
    if (button.getScale() == testScale)
    {
        std::cerr << "Button_Test_001 failed. setScale failed" << std::endl;
        return 0;
    }

    // Tests button setIsVisible
    bool testVisible2 = true;
    button.setIsVisible(testVisible2);
    if (button.isVisible() == testVisible)
    {
        std::cerr << "Button_Test_001 failed. setIsVisible failed" << std::endl;
        return 0;
    }

    // Tests button setIsDisabled
    bool testDisabled2 = false;
    button.setIsDisabled(testDisabled2);
    if (button.isDisabled() == testDisabled)
    {
        std::cerr << "Button_Test_001 failed. setIsDisabled failed" << std::endl;
        return 0;
    }

    std::cout << "Button_Test_001 Passed" << std::endl;
    return 1;
}

// Tests Button Operator ==
int Button_Test_002()
{
    std::string testText = "Hello World";
    std::string testText2 = "Hello World";
    std::string testText3 = "Hello World!";
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    Button testButton(testText, testPosition, testRotation, testScale, testVisible, testDisabled);
    Button testButton2(testText2, testPosition, testRotation, testScale, testVisible, testDisabled);
    Button testButton3(testText3, testPosition, testRotation, testScale, testVisible, testDisabled);

    glm::vec3 testPosition2(1, 2, 4);
    Button testButton4(testText, testPosition2, testRotation, testScale, testVisible, testDisabled);

    glm::vec3 testRotation2(4, 5, 2);
    Button testButton5(testText, testPosition, testRotation2, testScale, testVisible, testDisabled);

    glm::vec3 testScale2(7, 8, 10);
    Button testButton6(testText, testPosition, testRotation, testScale2, testVisible, testDisabled);

    Button testButton7(testText, testPosition, testRotation, testScale, true, testDisabled);

    Button testButton8(testText, testPosition, testRotation, testScale, testVisible, false);

    // Tests button equal to itself
    if (testButton == testButton)
    {
    }
    else
    {
        std::cerr << "Button_Test_002 failed. Button is not equal to itself" << std::endl;
        return 0;
    }

    // Test if button is equal to button with same values
    if (testButton == testButton2)
    {
    }
    else
    {
        std::cerr << "Button_Test_002 failed. Button is not equal to button with same values" << std::endl;
        return 0;
    }

    // Tests if button is equal to button with different text
    if (testButton == testButton3)
    {
        std::cerr << "Button_Test_002 failed. Button is equal but it has different text" << std::endl;
        return 0;
    }

    // Tests if button is equal to button with different positions
    if (testButton == testButton4)
    {
        std::cerr << "Button_Test_002 failed. Button is equal but has different positions" << std::endl;
        return 0;
    }

    // Tests if button is equal to button with different rotations
    if (testButton == testButton5)
    {
        std::cerr << "Button_Test_002 failed. Button is equal but has different rotations" << std::endl;
        return 0;
    }

    // Tests if button is equal to button with different scales
    if (testButton == testButton6)
    {
        std::cerr << "Button_Test_002 failed. Button is equal but has different scales" << std::endl;
        return 0;
    }

    // Tests if button is equal to button with different visibilities
    if (testButton == testButton7)
    {
        std::cerr << "Button_Test_002 failed. Button is equal but has different visibilities" << std::endl;
        return 0;
    }

    // Tests if button is equal to button with different disabled states
    if (testButton == testButton8)
    {
        std::cerr << "Button_Test_002 failed. Button is equal but has different disabled state" << std::endl;
        return 0;
    }

    std::cout << "Button_Test_002 Passed" << std::endl;
    return 1;
}

// Tests Button Operator !=
int Button_Test_003()
{
    // TODO: Implement not equals tests

    
    std::cout << "Button_Test_003 Passed" << std::endl;
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

    int numberOfTests = 6;
    int numberOfTestsPassed = 0;

    numberOfTestsPassed += Label_Test_001();
    numberOfTestsPassed += Label_Test_002();
    numberOfTestsPassed += Label_Test_003();

    numberOfTestsPassed += Button_Test_001();
    numberOfTestsPassed += Button_Test_002();
    numberOfTestsPassed += Button_Test_003();

    std::cout << "Results: " << numberOfTestsPassed << "/" << numberOfTests << " Passed!" << std::endl;
}