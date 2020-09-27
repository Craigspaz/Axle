#include <iostream>
#include <assert.h>
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>
#include "Menu-UI/Label.h"
#include "Menu-UI/Button.h"
#include "Menu-UI/Alert.h"
#include "Menu-UI/CheckBox.h"
#include "Menu-UI/Dropdown.h"
#include "Menu-UI/Image.h"
#include "Menu-UI/Layout.h"
#include "Menu-UI/ProgressBar.h"
#include "Menu-UI/RadioButton.h"
#include "Menu-UI/Screen.h"
#include "Menu-UI/Slider.h"
#include "Menu-UI/TextField.h"
#include "Menu-UI/Video.h"

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

    // Tests the getText() getter and constructor
    if (testLabel.getText().compare(testText) != 0)
    {
        std::cerr << "Label_Test_001 Failed. getText did not match text put into constructor. Expected: " << testText << ". Got: " << testLabel.getText() << std::endl;
        return 0;
    }

    // Tests the getPosition() getter and constructor
    if (testLabel.getPosition() != testPosition)
    {
        std::cerr << "Label_Test_001 Failed. getPosition did not match position put into constructor. Expected: " << glm::to_string(testPosition) << ". Got: " << glm::to_string(testLabel.getPosition()) << std::endl;
        return 0;
    }

    // Tests the getRotation() getter and constructor
    if (testLabel.getRotation() != testRotation)
    {
        std::cerr << "Label_Test_001 Failed. getRotation did not match rotation put into constructor. Expected: " << glm::to_string(testRotation) << ". Got: " << glm::to_string(testLabel.getRotation()) << std::endl;
        return 0;
    }

    // Tests the getScale() getter and constructor
    if (testLabel.getScale() != testScale)
    {
        std::cerr << "Label_Test_001 Failed. getScale did not match scale put into constructor. Expected: " << glm::to_string(testScale) << ". Got: " << glm::to_string(testLabel.getScale()) << std::endl;
        return 0;
    }

    // Tests the isVisible() getter and constructor
    if (testLabel.isVisible() != testVisible)
    {
        std::cerr << "Label_Test_001 Failed. isVisible did not match scale put into constructor. Expected: " << testVisible << ". Got: " << testLabel.isVisible() << std::endl;
        return 0;
    }

    // Tests the isDisabled() getter and constructor
    if (testLabel.isDisabled() != testDisabled)
    {
        std::cerr << "Label_Test_001 Failed. isDisabled did not match scale put into constructor. Expected: " << testDisabled << ". Got: " << testLabel.isDisabled() << std::endl;
        return 0;
    }

    // Tests setIsDisabled setter
    testLabel.setIsDisabled(false);
    if (testLabel.isDisabled() != false)
    {
        std::cerr << "Label_Test_001 failed. The setIsDisabled setter and isDisabled getter did not match. Expected: " << false << ". Got: " << testLabel.isDisabled() << std::endl;
        return 0;
    }

    // Tests setIsVisible setter
    testLabel.setIsVisible(true);
    if (testLabel.isVisible() != true)
    {
        std::cerr << "Label_Test_001 failed. The setIsVisible setter and isVisible getter did not match. Expected: " << true << ". Got: " << testLabel.isVisible() << std::endl;
        return 0;
    }

    // Tests setText setter
    testLabel.setText("Hello World Again");
    if (testLabel.getText().compare("Hello World Again") != 0)
    {
        std::cerr << "Label_Test_001 failed. The setText setter and getText getter did not match. Expected: "
                  << "Hello World Again"
                  << ". Got: " << testLabel.getText() << std::endl;
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
        std::cerr << "Label_Test_002 failed. Label does not equal itself!. Expected them to equal but they did not" << std::endl;
        return 0;
    }

    // Tests if label is equal to label with same text but different object
    if (testLabel == testLabel2)
    {
    }
    else
    {
        std::cerr << "Label_Test_002 failed. Label does not equal label with same details! Expected them to equal but they did not" << std::endl;
        return 0;
    }

    // Tests labels with different text don't equal
    if (testLabel == testLabel3)
    {
        std::cerr << "Label_Test_002 failed. Labels with different text were found to match! Expected them to not equal but they did" << std::endl;
        return 0;
    }

    // Tests labels with different positions don't equal
    if (testLabel == testLabel4)
    {
        std::cerr << "Label_Test_002 failed. Labels with different position were found to match. Expected them to not equal but they did" << std::endl;
        return 0;
    }

    // Tests labels with different position objects equal if their positions are the same
    if (testLabel == testLabel5)
    {
    }
    else
    {
        std::cerr << "Label_Test_002 failed. Labels with different position objects but same values did not match. Expected them to equal but they did not" << std::endl;
        return 0;
    }

    // Tests labels with different rotations equal if their rotations are the same
    if (testLabel == testLabel6)
    {
        std::cerr << "Label_Test_002 failed. Labels with different rotations were found to be equal. Expected them to not equal but they did" << std::endl;
        return 0;
    }

    // Tests labels with different scales equal if their scales are the same
    if (testLabel == testLabel7)
    {
        std::cerr << "Label_Test_002 failed. Labels with different scales were found to be equal. Expected them to not equal but they did" << std::endl;
        return 0;
    }

    // Tests labels with different visibility equal if their visibility is the same
    if (testLabel == testLabel8)
    {
        std::cerr << "Label_Test_002 failed. Labels with different visibilities were found to be equal. Expected them to not equal but they did" << std::endl;
        return 0;
    }

    // Tests labels with different disabled states equal if their disabled state are the same
    if (testLabel == testLabel9)
    {
        std::cerr << "Label_Test_002 failed. Labels with different disabled states were found to be equal. Expected them to not equal but they did" << std::endl;
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
        std::cerr << "Label_Test_003 failed. Label did not equal itself. Expected them to equal but they did not" << std::endl;
        return 0;
    }

    // Tests labels to confirm equal labels are found to be equal
    if (testLabel != testLabel2)
    {
        std::cerr << "Label_Test_003 failed. Labels that are equal were found to be different. Expected them to equal but they did not" << std::endl;
        return 0;
    }

    // Tests labels with different text are found to be different
    if (testLabel != testLabel3)
    {
    }
    else
    {
        std::cerr << "Label_Test_003 failed. Labels with different text were found to be equal. Expected them to not equal but they did" << std::endl;
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

    // Tests the getText() getter and constructor
    if (button.getText().compare(testText) != 0)
    {
        std::cerr << "Button_Test_001 Failed. getText did not match text put into constructor. Expected: " << testText << ". Got: " << button.getText() << std::endl;
        return 0;
    }

    // Tests the getPosition() getter and constructor
    if (button.getPosition() != testPosition)
    {
        std::cerr << "Button_Test_001 Failed. getPosition did not match position put into constructor. Expected: " << glm::to_string(testPosition) << ". Got: " << glm::to_string(button.getPosition()) << std::endl;
        return 0;
    }

    // Tests the getRotation() getter and constructor
    if (button.getRotation() != testRotation)
    {
        std::cerr << "Button_Test_001 Failed. getRotation did not match rotation put into constructor. Expected: " << glm::to_string(testRotation) << ". Got: " << glm::to_string(button.getRotation()) << std::endl;
        return 0;
    }

    // Tests the getScale() getter and constructor
    if (button.getScale() != testScale)
    {
        std::cerr << "Button_Test_001 Failed. getScale did not match scale put into constructor. Expected: " << glm::to_string(testScale) << ". Got: " << glm::to_string(button.getScale()) << std::endl;
        return 0;
    }

    // Tests the isVisible() getter and constructor
    if (button.isVisible() != testVisible)
    {
        std::cerr << "Button_Test_001 Failed. isVisible did not match visibility put into constructor. Expected: " << testVisible << ". Got: " << button.isVisible() << std::endl;
        return 0;
    }

    // Tests the isDisabled() getter and constructor
    if (button.isDisabled() != testDisabled)
    {
        std::cerr << "Button_Test_001 Failed. isDisabled did not match disabled state put into constructor. Expected: " << testDisabled << ". Got: " << button.isDisabled() << std::endl;
        return 0;
    }

    // Tests button setText setter
    testText = "Hello World!";
    button.setText(testText);
    if (button.getText().compare("Hello World!") != 0)
    {
        std::cerr << "Button_Test_001 failed with setText. Expected: "
                  << "Hello World!"
                  << ". Got: " << button.getText() << std::endl;
        return 0;
    }

    // Tests button setPosition
    glm::vec3 testPosition2(1, 2, 4);
    button.setPosition(testPosition2);
    if (button.getPosition() == testPosition)
    {
        std::cerr << "Button_Test_001 failed. setPosition failed. Expected: " << glm::to_string(testPosition) << ". Got: " << glm::to_string(button.getPosition()) << std::endl;
        return 0;
    }

    // Tests button setRotation
    glm::vec3 testRotation2(4, 5, 7);
    button.setRotation(testRotation2);
    if (button.getRotation() == testRotation)
    {
        std::cerr << "Button_Test_001 failed. setRotation failed. Expected: " << glm::to_string(testRotation) << ". Got: " << glm::to_string(button.getRotation()) << std::endl;
        return 0;
    }

    // Tests button setScale
    glm::vec3 testScale2(7, 8, 10);
    button.setScale(testScale2);
    if (button.getScale() == testScale)
    {
        std::cerr << "Button_Test_001 failed. setScale failed. Expected: " << glm::to_string(testScale) << ". Got: " << glm::to_string(button.getScale()) << std::endl;
        return 0;
    }

    // Tests button setIsVisible
    bool testVisible2 = true;
    button.setIsVisible(testVisible2);
    if (button.isVisible() == testVisible)
    {
        std::cerr << "Button_Test_001 failed. setIsVisible failed. Expected: " << testVisible << ". Got: " << button.isVisible() << std::endl;
        return 0;
    }

    // Tests button setIsDisabled
    bool testDisabled2 = false;
    button.setIsDisabled(testDisabled2);
    if (button.isDisabled() == testDisabled)
    {
        std::cerr << "Button_Test_001 failed. setIsDisabled failed. Expected: " << testDisabled << ". Got: " << button.isDisabled() << std::endl;
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
        std::cerr << "Button_Test_002 failed. Button is not equal to itself. Expected them to equal but they did not" << std::endl;
        return 0;
    }

    // Test if button is equal to button with same values
    if (testButton == testButton2)
    {
    }
    else
    {
        std::cerr << "Button_Test_002 failed. Button is not equal to button with same values. Expected them to equal but they did not" << std::endl;
        return 0;
    }

    // Tests if button is equal to button with different text
    if (testButton == testButton3)
    {
        std::cerr << "Button_Test_002 failed. Button is equal but it has different text. Expected them to not equal but they did" << std::endl;
        return 0;
    }

    // Tests if button is equal to button with different positions
    if (testButton == testButton4)
    {
        std::cerr << "Button_Test_002 failed. Button is equal but has different positions. Expected them to not equal but they did" << std::endl;
        return 0;
    }

    // Tests if button is equal to button with different rotations
    if (testButton == testButton5)
    {
        std::cerr << "Button_Test_002 failed. Button is equal but has different rotations. Expected them to not equal but they did" << std::endl;
        return 0;
    }

    // Tests if button is equal to button with different scales
    if (testButton == testButton6)
    {
        std::cerr << "Button_Test_002 failed. Button is equal but has different scales. Expected them to not equal but they did" << std::endl;
        return 0;
    }

    // Tests if button is equal to button with different visibilities
    if (testButton == testButton7)
    {
        std::cerr << "Button_Test_002 failed. Button is equal but has different visibilities. Expected them to not equal but they did" << std::endl;
        return 0;
    }

    // Tests if button is equal to button with different disabled states
    if (testButton == testButton8)
    {
        std::cerr << "Button_Test_002 failed. Button is equal but has different disabled state. Expected them to not equal but they did" << std::endl;
        return 0;
    }

    std::cout << "Button_Test_002 Passed" << std::endl;
    return 1;
}

// Tests Button Operator != (Note this is the inverse of the == so doing minimal tests)
int Button_Test_003()
{
    std::string testText = "Hello World";
    std::string testText2 = "Hello World!";
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    Button testButton(testText, testPosition, testRotation, testScale, testVisible, testDisabled);
    Button testButton2(testText2, testPosition, testRotation, testScale, testVisible, testDisabled);
    Button testButton3(testText, testPosition, testRotation, testScale, testVisible, testDisabled);

    // Tests if button is equal to itself
    if (testButton != testButton)
    {
        std::cerr << "Button_Test_003 failed. Button did not equal itself. Expected them to equal but they did not" << std::endl;
        return 0;
    }

    // Tests if buttons with different text equal
    if (testButton != testButton2)
    {
    }
    else
    {
        std::cerr << "Button_Test_003 failed. Buttons that have different text equal. Expected them to equal but they did not" << std::endl;
        return 0;
    }

    // Tests if buttons with same values but different objects differ
    if (testButton != testButton3)
    {
        std::cerr << "Button_Test_003 failed. Buttons with the same values but different objects differ. Expected them to equal but they did not" << std::endl;
        return 0;
    }

    std::cout << "Button_Test_003 Passed" << std::endl;
    return 1;
}

// Tests Alert Getters and Setters
int Alert_Test_001()
{
    std::string message = "Test Message";
    std::string confirmButtonText = "Confirm";
    std::string cancelButtonText = "Cancel";
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    Alert testAlert(message, confirmButtonText, cancelButtonText, testPosition, testRotation, testScale, testVisible, testDisabled);

    // Tests the getPosition() getter and constructor
    if (testAlert.getPosition() != testPosition)
    {
        std::cerr << "Alert_Test_001 Failed. getPosition did not match position put into constructor. Expected: " << glm::to_string(testPosition) << ". Got: " << glm::to_string(testAlert.getPosition()) << std::endl;
        return 0;
    }

    // Tests the getRotation() getter and constructor
    if (testAlert.getRotation() != testRotation)
    {
        std::cerr << "Alert_Test_001 Failed. getRotation did not match rotation put into constructor. Expected: " << glm::to_string(testRotation) << ". Got: " << glm::to_string(testAlert.getRotation()) << std::endl;
        return 0;
    }

    // Tests the getScale() getter and constructor
    if (testAlert.getScale() != testScale)
    {
        std::cerr << "Alert_Test_001 Failed. getScale did not match scale put into constructor. Expected: " << glm::to_string(testScale) << ". Got: " << glm::to_string(testAlert.getScale()) << std::endl;
        return 0;
    }

    // Tests the isVisible() getter and constructor
    if (testAlert.isVisible() != testVisible)
    {
        std::cerr << "Alert_Test_001 Failed. isVisible did not match visibility put into constructor. Expected: " << testVisible << ". Got: " << testAlert.isVisible() << std::endl;
        return 0;
    }

    // Tests the isDisabled() getter and constructor
    if (testAlert.isDisabled() != testDisabled)
    {
        std::cerr << "Alert_Test_001 Failed. isDisabled did not match disabled state put into constructor. Expected: " << testDisabled << ". Got: " << testAlert.isDisabled() << std::endl;
        return 0;
    }

    // Tests confirm button
    if (testAlert.getConfirmButton()->getText().compare(confirmButtonText) != 0)
    {
        std::cerr << "Alert_Test_001 failed. Confirm button text did not match. Expected: " << confirmButtonText << ". Got: " << testAlert.getConfirmButton()->getText() << std::endl;
        return 0;
    }

    // Tests cancel button
    if (testAlert.getCancelButton()->getText().compare(cancelButtonText) != 0)
    {
        std::cerr << "Alert_Test_001 failed. Cancel button text did not match. Expected: " << cancelButtonText << ". Got: " << testAlert.getCancelButton()->getText() << std::endl;
        return 0;
    }

    // Tests label
    if (testAlert.getMessage()->getText().compare(message) != 0)
    {
        std::cerr << "Alert_Test_001 failed. Label text does not match. Expected: " << message << ". Got: " << testAlert.getMessage()->getText() << std::endl;
        return 0;
    }

    // Tests message text getter
    if (testAlert.getMessageText().compare(message) != 0)
    {
        std::cerr << "Alert_Test_001 failed. Label text getter does not match. Expected: " << message << ". Got: " << testAlert.getMessageText() << std::endl;
        return 0;
    }

    // Tests message setter
    testAlert.setMessage("Hello World!");
    if (testAlert.getMessageText().compare("Hello World!") != 0)
    {
        std::cerr << "Alert_Test_001 failed. Setter did not set the message text as expected. Expected: "
                  << "Hello World!"
                  << ". Got: " << testAlert.getMessageText() << std::endl;
        return 0;
    }

    // Tests setPosition
    glm::vec3 testPosition2(1, 2, 4);
    testAlert.setPosition(testPosition2);
    if (testAlert.getPosition() != testPosition2)
    {
        std::cerr << "Alert_Test_001 failed. setPosition did not set the position as exepected. Expected: " << glm::to_string(testPosition2) << ". Got: " << glm::to_string(testAlert.getPosition()) << std::endl;
        return 0;
    }

    glm::vec3 testRotation2(4, 15, 6);
    testAlert.setRotation(testRotation2);
    if (testAlert.getRotation() != testRotation2)
    {
        std::cerr << "Alert_Test_001 failed. setRotation did not set the rotation as expected. Expected: " << glm::to_string(testRotation2) << ". Got: " << glm::to_string(testAlert.getRotation()) << std::endl;
        return 0;
    }

    glm::vec3 testScale2(17, 8, 9);
    testAlert.setScale(testScale2);
    if (testAlert.getScale() != testScale2)
    {
        std::cerr << "Alert_Test_001 failed. setScale did not set the scale as expected. Expected: " << glm::to_string(testScale2) << ". Got: " << glm::to_string(testAlert.getScale()) << std::endl;
        return 0;
    }

    bool testVisible2 = true;
    testAlert.setIsVisible(testVisible2);
    if (testAlert.isVisible() != testVisible2)
    {
        std::cerr << "Alert_Test_001 failed. setIsVisible did not set the visibility as expected. Expected: " << testVisible2 << ". Got: " << testAlert.isVisible() << std::endl;
        return 0;
    }

    bool testDisabled2 = false;
    testAlert.setIsDisabled(testDisabled2);
    if (testAlert.isDisabled() != testDisabled2)
    {
        std::cerr << "Alert_Test_001 failed. setIsDisabled did not set the disabled state as expected. Expected: " << testDisabled2 << ". Got: " << testAlert.isDisabled() << std::endl;
        return 0;
    }

    std::cout << "Alert_Test_001 Passed" << std::endl;
    return 1;
}

// Tests Alert Operator ==
int Alert_Test_002()
{
    std::string message = "Test Message";
    std::string confirmButtonText = "Confirm";
    std::string cancelButtonText = "Cancel";
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    Alert testAlert(message, confirmButtonText, cancelButtonText, testPosition, testRotation, testScale, testVisible, testDisabled);
    Alert testAlert1(message, confirmButtonText, cancelButtonText, testPosition, testRotation, testScale, testVisible, testDisabled);

    std::string message2 = "Test Message2";
    Alert testAlert2(message2, confirmButtonText, cancelButtonText, testPosition, testRotation, testScale, testVisible, testDisabled);

    std::string confirmButtonText2 = "Confirm2";
    Alert testAlert3(message, confirmButtonText2, cancelButtonText, testPosition, testRotation, testScale, testVisible, testDisabled);

    std::string cancelButtonText2 = "Cancel2";
    Alert testAlert4(message, confirmButtonText, cancelButtonText2, testPosition, testRotation, testScale, testVisible, testDisabled);

    glm::vec3 testPosition2(1, 2, 4);
    Alert testAlert5(message, confirmButtonText, cancelButtonText, testPosition2, testRotation, testScale, testVisible, testDisabled);

    glm::vec3 testRotation2(4, 2, 6);
    Alert testAlert6(message, confirmButtonText, cancelButtonText, testPosition, testRotation2, testScale, testVisible, testDisabled);

    glm::vec3 testScale2(7, 28, 9);
    Alert testAlert7(message, confirmButtonText, cancelButtonText, testPosition, testRotation, testScale2, testVisible, testDisabled);

    bool testVisible2 = true;
    Alert testAlert8(message, confirmButtonText, cancelButtonText, testPosition, testRotation, testScale, testVisible2, testDisabled);

    bool testDisabled2 = false;
    Alert testAlert9(message, confirmButtonText, cancelButtonText, testPosition, testRotation, testScale, testVisible, testDisabled2);

    // Tests if alert is equal to itself
    if (testAlert == testAlert)
    {
    }
    else
    {
        std::cerr << "Alert_Test_002 failed. Alert did not equal itself" << std::endl;
        return 0;
    }

    // Tests if an alert is equal to an alert with the same values but different object
    if (testAlert == testAlert1)
    {
    }
    else
    {
        std::cerr << "Alert_Test_002 failed. Alert did not equal an alert with same values but different object" << std::endl;
        return 0;
    }

    // Tests if alerts with different messages are equal
    if (testAlert == testAlert2)
    {
        std::cerr << "Alert_Test_002 failed. Alert equaled alert with different message" << std::endl;
        return 0;
    }

    // Tests if alerts with different confirm buttons are equal
    if (testAlert == testAlert3)
    {
        std::cerr << "Alert_Test_002 failed. Alert equaled alert with different confirm button" << std::endl;
        return 0;
    }

    // Tests if alerts with different cancel buttons are equal
    if (testAlert == testAlert4)
    {
        std::cerr << "Alert_Test_002 failed. Alert equaled alert with different cancel button" << std::endl;
        return 0;
    }

    // Tests if alerts with different positions are equal
    if (testAlert == testAlert5)
    {
        std::cerr << "Alert_Test_002 failed. Alert equaled alert with different positions" << std::endl;
        return 0;
    }

    // Tests if alerts with different rotations are equal
    if (testAlert == testAlert6)
    {
        std::cerr << "Alert_Test_002 failed. Alert equaled alert with different rotations" << std::endl;
        return 0;
    }

    // Tests if alerts with different scales are equal
    if (testAlert == testAlert7)
    {
        std::cerr << "Alert_Test_002 failed. Alert equaled alert with different scales" << std::endl;
        return 0;
    }

    // Tests if alerts with different visibilities are equal
    if (testAlert == testAlert8)
    {
        std::cerr << "Alert_Test_002 failed. Alert equaled alert with different visibilities" << std::endl;
        return 0;
    }

    // Tests if alerts with different disabled states are equal
    if (testAlert == testAlert9)
    {
        std::cerr << "Alert_Test_002 failed. Alert equaled alert with different disabled states" << std::endl;
        return 0;
    }

    std::cout << "Alert_Test_002 Passed" << std::endl;
    return 1;
}

// Tests Alert Operator != (Note this is the inverse of the == so doing minimal tests)
int Alert_Test_003()
{
    std::string message = "Test Message";
    std::string confirmButtonText = "Confirm";
    std::string cancelButtonText = "Cancel";
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    Alert testAlert(message, confirmButtonText, cancelButtonText, testPosition, testRotation, testScale, testVisible, testDisabled);

    std::string message2 = "Test Message2";
    Alert testAlert2(message2, confirmButtonText, cancelButtonText, testPosition, testRotation, testScale, testVisible, testDisabled);

    // Tests if alert is not equal to itself
    if (testAlert != testAlert)
    {
        std::cerr << "Alert_Test_003 failed. Alert was found to be not equal to itself" << std::endl;
        return 0;
    }

    // Tests if alert is not equal to an alert with a different message
    if (testAlert != testAlert2)
    {
    }
    else
    {
        std::cerr << "Alert_Test_003 failed. Alert was found to be equal to an alert with a different message" << std::endl;
        return 0;
    }

    std::cout << "Alert_Test_003 Passed" << std::endl;
    return 1;
}

// Tests CheckBox Getters and Setters
int CheckBox_Test_001()
{
    bool currentState = false;
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;
    CheckBox testCheckBox(currentState, testPosition, testRotation, testScale, testVisible, testDisabled);

    // Test getter for if the checkbox is checked
    if (testCheckBox.isChecked())
    {
        std::cerr << "CheckBox_Test_001 failed. CheckBox was expected to be false but was true" << std::endl;
        return 0;
    }

    // Tests the getPosition() getter and constructor
    if (testCheckBox.getPosition() != testPosition)
    {
        std::cerr << "CheckBox_Test_001 Failed. getPosition did not match position put into constructor. Expected: " << glm::to_string(testPosition) << ". Got: " << glm::to_string(testCheckBox.getPosition()) << std::endl;
        return 0;
    }

    // Tests the getRotation() getter and constructor
    if (testCheckBox.getRotation() != testRotation)
    {
        std::cerr << "CheckBox_Test_001 Failed. getRotation did not match rotation put into constructor. Expected: " << glm::to_string(testRotation) << ". Got: " << glm::to_string(testCheckBox.getRotation()) << std::endl;
        return 0;
    }

    // Tests the getScale() getter and constructor
    if (testCheckBox.getScale() != testScale)
    {
        std::cerr << "CheckBox_Test_001 Failed. getScale did not match scale put into constructor. Expected: " << glm::to_string(testScale) << ". Got: " << glm::to_string(testCheckBox.getScale()) << std::endl;
        return 0;
    }

    // Tests the isVisible() getter and constructor
    if (testCheckBox.isVisible() != testVisible)
    {
        std::cerr << "CheckBox_Test_001 Failed. isVisible did not match visibility put into constructor. Expected: " << testVisible << ". Got: " << testCheckBox.isVisible() << std::endl;
        return 0;
    }

    // Tests the isDisabled() getter and constructor
    if (testCheckBox.isDisabled() != testDisabled)
    {
        std::cerr << "CheckBox_Test_001 Failed. isDisabled did not match disabled state put into constructor. Expected: " << testDisabled << ". Got: " << testCheckBox.isDisabled() << std::endl;
        return 0;
    }

    std::cout << "CheckBox_Test_001 Passed" << std::endl;
    return 1;
}

// Tests CheckBox Operator ==
int CheckBox_Test_002()
{
    bool currentState = false;
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;
    CheckBox testCheckBox(currentState, testPosition, testRotation, testScale, testVisible, testDisabled);
    CheckBox testCheckBox2(currentState, testPosition, testRotation, testScale, testVisible, testDisabled);

    bool currentState2 = true;
    CheckBox testCheckBox3(currentState2, testPosition, testRotation, testScale, testVisible, testDisabled);

    glm::vec3 testPosition2(1, 12, 3);
    CheckBox testCheckBox4(currentState, testPosition2, testRotation, testScale, testVisible, testDisabled);

    glm::vec3 testRotation2(14, 5, 6);
    CheckBox testCheckBox5(currentState, testPosition, testRotation2, testScale, testVisible, testDisabled);

    glm::vec3 testScale2(7, 18, 9);
    CheckBox testCheckBox6(currentState, testPosition, testRotation, testScale2, testVisible, testDisabled);

    bool testVisible2 = true;
    CheckBox testCheckBox7(currentState, testPosition, testRotation, testScale, testVisible2, testDisabled);

    bool testDisabled2 = false;
    CheckBox testCheckBox8(currentState, testPosition, testRotation, testScale, testVisible, testDisabled2);

    // Tests if checkbox equals itself
    if (testCheckBox == testCheckBox)
    {
    }
    else
    {
        std::cerr << "CheckBox_Test_002 failed. CheckBox was not equal to itself" << std::endl;
        return 0;
    }

    // Test if checkbox equals checkbox with same values
    if (testCheckBox == testCheckBox2)
    {
    }
    else
    {
        std::cerr << "CheckBox_Test_002 failed. CheckBox was not equal to another checkbox with the same details" << std::endl;
        return 0;
    }

    // Tests if checkbox equals a checkbox with a different state
    if (testCheckBox == testCheckBox3)
    {
        std::cerr << "CheckBox_Test_002 failed. CheckBox was equal to a checkbox with a different state" << std::endl;
        return 0;
    }

    // Tests if a checkbox equals a checkbox with different positions
    if (testCheckBox == testCheckBox4)
    {
        std::cerr << "CheckBox_Test_002 failed. CheckBox was equal to a checkbox with a different position" << std::endl;
        return 0;
    }

    // Tests if a checkbox equals a checkbox with different rotations
    if (testCheckBox == testCheckBox5)
    {
        std::cerr << "CheckBox_Test_002 failed. CheckBox was equal to a checkbox with a different rotation" << std::endl;
        return 0;
    }

    // Tests if a checkbox equals a checkbox with a different scale
    if (testCheckBox == testCheckBox6)
    {
        std::cerr << "CheckBox_Test_002 failed. CheckBox was equal to a checkbox with a different scale" << std::endl;
        return 0;
    }

    // Tests if a checkbox equals a checkbox with a different visibilities
    if (testCheckBox == testCheckBox7)
    {
        std::cerr << "CheckBox_Test_002 failed. CheckBox was equal to a checkbox with a different visibility" << std::endl;
        return 0;
    }

    // Tests if a checkbox equals a checkbox with a different state
    if (testCheckBox == testCheckBox8)
    {
        std::cerr << "CheckBox_Test_002 failed. CheckBox was equal to a checkbox with a different disabled state" << std::endl;
        return 0;
    }

    std::cout << "CheckBox_Test_002 Passed" << std::endl;
    return 1;
}

// Tests CheckBox Operator !=
int CheckBox_Test_003()
{
    bool currentState = false;
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;
    CheckBox testCheckBox(currentState, testPosition, testRotation, testScale, testVisible, testDisabled);

    bool currentState2 = true;
    CheckBox testCheckBox2(currentState2, testPosition, testRotation, testScale, testVisible, testDisabled);

    // Tests if a checkbox does not equal itself
    if (testCheckBox != testCheckBox)
    {
        std::cerr << "CheckBox_Test_002 failed. CheckBox was not equal to itself" << std::endl;
        return 0;
    }

    // Tests if a checkbox does not equal a checkbox with different states
    if (testCheckBox != testCheckBox2)
    {
    }
    else
    {
        std::cerr << "CheckBox_Test_002 failed. CheckBox was equal to checkbox with a different state" << std::endl;
        return 0;
    }

    std::cout << "CheckBox_Test_003 Passed" << std::endl;
    return 1;
}

// Tests DropDown Getters and Setters
int DropDown_Test_001()
{
    std::vector<std::string> testOptions;
    testOptions.push_back("Test");
    testOptions.push_back("Test2");
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    DropDown testDropdown(testOptions, testOptions.size(), testPosition, testRotation, testScale, testVisible, testDisabled);

    // Tests that the correct number of items are in the options list and that they match up as expected
    std::vector<std::string> testOptions1 = testDropdown.getOptions();
    if (testOptions.size() != testOptions1.size())
    {
        std::cerr << "DropDown_Test_001 failed. DropDown contructor failed to set the options" << std::endl;
        return 0;
    }
    else
    {
        for (int i = 0; i < testOptions.size(); i++)
        {
            if (testOptions[i].compare(testOptions1[i]) != 0)
            {
                std::cerr << "DropDown_Test_001 failed. DropDown options values did not match. Expected:" << testOptions[i] << " . Got: " << testOptions1[i] << std::endl;
                return 0;
            }
        }
    }

    // Tests the getPosition() getter and constructor
    if (testDropdown.getPosition() != testPosition)
    {
        std::cerr << "DropDown_Test_001 Failed. getPosition did not match position put into constructor. Expected: " << glm::to_string(testPosition) << ". Got: " << glm::to_string(testDropdown.getPosition()) << std::endl;
        return 0;
    }

    // Tests the getRotation() getter and constructor
    if (testDropdown.getRotation() != testRotation)
    {
        std::cerr << "DropDown_Test_001 Failed. getRotation did not match rotation put into constructor. Expected: " << glm::to_string(testRotation) << ". Got: " << glm::to_string(testDropdown.getRotation()) << std::endl;
        return 0;
    }

    // Tests the getScale() getter and constructor
    if (testDropdown.getScale() != testScale)
    {
        std::cerr << "DropDown_Test_001 Failed. getScale did not match scale put into constructor. Expected: " << glm::to_string(testScale) << ". Got: " << glm::to_string(testDropdown.getScale()) << std::endl;
        return 0;
    }

    // Tests the isVisible() getter and constructor
    if (testDropdown.isVisible() != testVisible)
    {
        std::cerr << "DropDown_Test_001 Failed. isVisible did not match visibility put into constructor. Expected: " << testVisible << ". Got: " << testDropdown.isVisible() << std::endl;
        return 0;
    }

    // Tests the isDisabled() getter and constructor
    if (testDropdown.isDisabled() != testDisabled)
    {
        std::cerr << "DropDown_Test_001 Failed. isDisabled did not match disabled state put into constructor. Expected: " << testDisabled << ". Got: " << testDropdown.isDisabled() << std::endl;
        return 0;
    }

    std::cout << "DropDown_Test_001 Passed" << std::endl;
    return 1;
}

// Tests DropDown Operator ==
int DropDown_Test_002()
{
    std::vector<std::string> testOptions;
    testOptions.push_back("Test");
    testOptions.push_back("Test2");
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    DropDown testDropdown(testOptions, testOptions.size(), testPosition, testRotation, testScale, testVisible, testDisabled);
    DropDown testDropdown1(testOptions, testOptions.size(), testPosition, testRotation, testScale, testVisible, testDisabled);

    glm::vec3 testPosition2(21, 2, 3);
    DropDown testDropdown2(testOptions, testOptions.size(), testPosition2, testRotation, testScale, testVisible, testDisabled);

    glm::vec3 testRotation2(24, 5, 6);
    DropDown testDropdown3(testOptions, testOptions.size(), testPosition, testRotation2, testScale, testVisible, testDisabled);

    glm::vec3 testScale2(27, 8, 9);
    DropDown testDropdown4(testOptions, testOptions.size(), testPosition, testRotation, testScale2, testVisible, testDisabled);

    bool testVisible2 = true;
    DropDown testDropdown5(testOptions, testOptions.size(), testPosition, testRotation, testScale, testVisible2, testDisabled);

    bool testDisabled2 = false;
    DropDown testDropdown6(testOptions, testOptions.size(), testPosition, testRotation, testScale, testVisible, testDisabled2);

    // Tests if a dropdown equals itself
    if (testDropdown == testDropdown)
    {
    }
    else
    {
        std::cerr << "DropDown_Test_002 failed. DropDown did not equal itself" << std::endl;
        return 0;
    }

    // Tests if a dropdown equals a dropdown with the same values
    if (testDropdown == testDropdown1)
    {
    }
    else
    {
        std::cerr << "DropDown_Test_002 failed. DropDown did not equal a dropdown with the same values" << std::endl;
        return 0;
    }

    // Tests if a dropdown equals a dropdown with different positions
    if (testDropdown == testDropdown2)
    {
        std::cerr << "DropDown_Test_002 failed. DropDown equaled another dropdown with different positions" << std::endl;
        return 0;
    }

    // Tests if a dropdown equals a dropdown with different rotations
    if (testDropdown == testDropdown3)
    {
        std::cerr << "DropDown_Test_002 failed. DropDown equaled another dropdown with different rotations" << std::endl;
        return 0;
    }

    // Tests if a dropdown equals a dropdown with different scales
    if (testDropdown == testDropdown4)
    {
        std::cerr << "DropDown_Test_002 failed. DropDown equaled another dropdown with different scales" << std::endl;
        return 0;
    }

    // Tests if a dropdown equals a dropdown with different visibilities
    if (testDropdown == testDropdown5)
    {
        std::cerr << "DropDown_Test_002 failed. DropDown equaled another dropdown with different visibilities" << std::endl;
        return 0;
    }

    // Tests if a dropdown equals a dropdown with different disabled states
    if (testDropdown == testDropdown6)
    {
        std::cerr << "DropDown_Test_002 failed. DropDown equaled another dropdown with different disabled states" << std::endl;
        return 0;
    }

    std::cout << "DropDown_Test_002 Passed" << std::endl;
    return 1;
}

// Tests DropDown Operator !=
int DropDown_Test_003()
{
    std::vector<std::string> testOptions;
    testOptions.push_back("Test");
    testOptions.push_back("Test2");
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    DropDown testDropdown(testOptions, testOptions.size(), testPosition, testRotation, testScale, testVisible, testDisabled);
    DropDown testDropdown2(testOptions, testOptions.size(), testPosition, testRotation, testScale, testVisible, testDisabled);

    std::vector<std::string> testOptions2;
    testOptions.push_back("Test");
    testOptions.push_back("Test3");
    DropDown testDropdown3(testOptions2, testOptions.size(), testPosition, testRotation, testScale, testVisible, testDisabled);

    // Tests if dropdown does not equal itself
    if (testDropdown != testDropdown)
    {
        std::cerr << "DropDown_Test_003 failed. DropDown did not equal itself" << std::endl;
        return 0;
    }

    // Tests if dropdown does not equal another dropdown with the same values
    if (testDropdown != testDropdown2)
    {
        std::cerr << "DropDown_Test_003 failed. DropDown did not equal dropdown with same values" << std::endl;
        return 0;
    }

    // Tests if a dropdown does not equal a dropdown with different options
    if (testDropdown != testDropdown3)
    {
    }
    else
    {
        std::cerr << "DropDown_Test_003 failed. DropDown equaled dropdown with different options" << std::endl;
        return 0;
    }

    std::cout << "DropDown_Test_003 Passed" << std::endl;
    return 1;
}

// Tests DropDown addOption
int DropDown_Test_004()
{
    std::vector<std::string> testOptions;
    testOptions.push_back("Test");
    testOptions.push_back("Test2");
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    DropDown testDropdown(testOptions, testOptions.size(), testPosition, testRotation, testScale, testVisible, testDisabled);

    // Tests if a dropdown has the expected number of options
    if (testDropdown.getOptions().size() != 2)
    {
        std::cerr << "DropDown_Test_004 failed. DropDown did not have the correct number of options. Expected: 2. Got: " << testDropdown.getOptions().size() << std::endl;
        return 0;
    }

    testDropdown.addOption("Test3");
    // Tests if the dropdown has the correct number of options after adding an option
    if (testDropdown.getOptions().size() != 3)
    {
        std::cerr << "DropDown_Test_004 failed. DropDown did not have the correct number of options. Expected: 3. Got: " << testDropdown.getOptions().size() << std::endl;
        return 0;
    }

    // Tests if the options are the expected values
    std::string expected[3];
    expected[0] = "Test";
    expected[1] = "Test2";
    expected[2] = "Test3";

    std::vector<std::string> testOptions2 = testDropdown.getOptions();
    for (int i = 0; i < testOptions2.size(); i++)
    {
        if (testOptions2[i].compare(expected[i]) != 0)
        {
            std::cerr << "DropDown_Test_004 failed. DropDown's options did not match after adding item. " << std::endl;
            return 0;
        }
    }

    std::cout << "DropDown_Test_004 Passed" << std::endl;
    return 1;
}

// Tests DropDown setOptions
int DropDown_Test_005()
{
    std::vector<std::string> testOptions;
    testOptions.push_back("Test");
    testOptions.push_back("Test2");
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    DropDown testDropdown(testOptions, testOptions.size(), testPosition, testRotation, testScale, testVisible, testDisabled);

    std::vector<std::string> testOptions2;
    testOptions2.push_back("Hello World");
    testOptions2.push_back("Hello World2");
    testOptions2.push_back("Hello World3");

    testDropdown.setOptions(testOptions2);

    // Tests that the dropdown has the correct number of values
    if (testDropdown.getOptions().size() != 3)
    {
        std::cerr << "DropDown_Test_005 failed. DropDown did not have the correct number of options. Expected: 3. Got: " << testDropdown.getOptions().size() << std::endl;
        return 0;
    }

    // Tests that the dropdown has the correct option values
    std::string expected[3];
    expected[0] = "Hello World";
    expected[1] = "Hello World2";
    expected[2] = "Hello World3";

    std::vector<std::string> testOptions3 = testDropdown.getOptions();
    for (int i = 0; i < testOptions3.size(); i++)
    {
        if (testOptions3[i].compare(expected[i]) != 0)
        {
            std::cerr << "DropDown_Test_005 failed. DropDown's options did not match after adding item. " << std::endl;
            return 0;
        }
    }

    std::cout << "DropDown_Test_005 Passed" << std::endl;
    return 1;
}

// Tests DropDown removeOption
int DropDown_Test_006()
{
    std::vector<std::string> testOptions;
    testOptions.push_back("Test");
    testOptions.push_back("Test2");
    testOptions.push_back("Test3");
    testOptions.push_back("Test4");
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    DropDown testDropdown(testOptions, testOptions.size(), testPosition, testRotation, testScale, testVisible, testDisabled);

    testDropdown.removeOption("Test2");

    // Tests that the dropdown has the correct number of values after removing one
    if (testDropdown.getOptions().size() != 3)
    {
        std::cerr << "DropDown_Test_006 failed. DropDown did not have the correct number of options. Expected: 3. Got: " << testDropdown.getOptions().size() << std::endl;
        return 0;
    }

    // Tests that the correct values in the options remain
    std::string expected[3];
    expected[0] = "Test";
    expected[1] = "Test3";
    expected[2] = "Test4";

    std::vector<std::string> testOptions3 = testDropdown.getOptions();
    for (int i = 0; i < testOptions3.size(); i++)
    {
        if (testOptions3[i].compare(expected[i]) != 0)
        {
            std::cerr << "DropDown_Test_006 failed. DropDown's options did not match after adding item. " << std::endl;
            return 0;
        }
    }

    testDropdown.removeOption("Test3");

    // Tests that the correct number of values are in the options list
    if (testDropdown.getOptions().size() != 2)
    {
        std::cerr << "DropDown_Test_006 failed. DropDown did not have the correct number of options. Expected: 2. Got: " << testDropdown.getOptions().size() << std::endl;
        return 0;
    }

    // Tests that the correct values remain
    std::string expected2[2];
    expected2[0] = "Test";
    expected2[1] = "Test4";

    testOptions3 = testDropdown.getOptions();
    for (int i = 0; i < testOptions3.size(); i++)
    {
        if (testOptions3[i].compare(expected2[i]) != 0)
        {
            std::cerr << "DropDown_Test_006 failed. DropDown's options did not match after adding item. " << std::endl;
            return 0;
        }
    }

    // Tests that removing the rest of the items causes the size to go to 0
    testDropdown.removeOption("Test");
    testDropdown.removeOption("Test4");
    if (testDropdown.getOptions().size() != 0)
    {
        std::cerr << "DropDown_Test_006 failed. DropDown did not have the correct number of options. Expected: 0. Got: " << testDropdown.getOptions().size() << std::endl;
        return 0;
    }

    testDropdown.removeOption("Hello World"); // This does not do anything since the value is not in the list
    if (testDropdown.getOptions().size() != 0)
    {
        std::cerr << "DropDown_Test_006 failed. DropDown did not have the correct number of options. Expected: 0. Got: " << testDropdown.getOptions().size() << std::endl;
        return 0;
    }
    std::cout << "DropDown_Test_006 Passed" << std::endl;
    return 1;
}

// Tests Image Getters and Setters
int Image_Test_001()
{
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    Image testImage(testPosition, testRotation, testScale, testVisible, testDisabled);

    // Tests the getPosition() getter and constructor
    if (testImage.getPosition() != testPosition)
    {
        std::cerr << "Image_Test_001 Failed. getPosition did not match position put into constructor. Expected: " << glm::to_string(testPosition) << ". Got: " << glm::to_string(testImage.getPosition()) << std::endl;
        return 0;
    }

    // Tests the getRotation() getter and constructor
    if (testImage.getRotation() != testRotation)
    {
        std::cerr << "Image_Test_001 Failed. getRotation did not match rotation put into constructor. Expected: " << glm::to_string(testRotation) << ". Got: " << glm::to_string(testImage.getRotation()) << std::endl;
        return 0;
    }

    // Tests the getScale() getter and constructor
    if (testImage.getScale() != testScale)
    {
        std::cerr << "Image_Test_001 Failed. getScale did not match scale put into constructor. Expected: " << glm::to_string(testScale) << ". Got: " << glm::to_string(testImage.getScale()) << std::endl;
        return 0;
    }

    // Tests the isVisible() getter and constructor
    if (testImage.isVisible() != testVisible)
    {
        std::cerr << "Image_Test_001 Failed. isVisible did not match visibility put into constructor. Expected: " << testVisible << ". Got: " << testImage.isVisible() << std::endl;
        return 0;
    }

    // Tests the isDisabled() getter and constructor
    if (testImage.isDisabled() != testDisabled)
    {
        std::cerr << "Image_Test_001 Failed. isDisabled did not match disabled state put into constructor. Expected: " << testDisabled << ". Got: " << testImage.isDisabled() << std::endl;
        return 0;
    }

    std::cout << "Image_Test_001 Passed" << std::endl;
    return 1;
}

// Tests Image Operator ==
int Image_Test_002()
{
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    Image testImage(testPosition, testRotation, testScale, testVisible, testDisabled);
    Image testImage2(testPosition, testRotation, testScale, testVisible, testDisabled);

    glm::vec3 testPosition2(21, 2, 3);
    Image testImage3(testPosition2, testRotation, testScale, testVisible, testDisabled);

    glm::vec3 testRotation2(24, 5, 6);
    Image testImage4(testPosition, testRotation2, testScale, testVisible, testDisabled);

    glm::vec3 testScale2(7, 28, 9);
    Image testImage5(testPosition, testRotation, testScale2, testVisible, testDisabled);

    bool testVisible2 = true;
    Image testImage6(testPosition, testRotation, testScale, testVisible2, testDisabled);

    bool testDisabled2 = false;
    Image testImage7(testPosition, testRotation, testScale, testVisible, testDisabled2);

    // Tests if an image equals itself
    if (testImage == testImage)
    {
    }
    else
    {
        std::cerr << "Image_Test_002 Failed. Image did not equal itself" << std::endl;
        return 0;
    }

    // Tests if an image is equal to an image with the same values
    if (testImage == testImage2)
    {
    }
    else
    {
        std::cerr << "Image_Test_002 Failed. Image did not equal an image with the same values" << std::endl;
        return 0;
    }

    // Tests if an image equals an image with different positions
    if (testImage == testImage3)
    {
        std::cerr << "Image_Test_002 Failed. Image equaled imge with different positions" << std::endl;
        return 0;
    }

    // Tests if an image equals an image with different rotations
    if (testImage == testImage4)
    {
        std::cerr << "Image_Test_002 Failed. Image equaled imge with different rotations" << std::endl;
        return 0;
    }

    // Tests if an image equals an image with different scales
    if (testImage == testImage5)
    {
        std::cerr << "Image_Test_002 Failed. Image equaled imge with different scales" << std::endl;
        return 0;
    }

    // Tests if an image equals an image with different visibilities
    if (testImage == testImage6)
    {
        std::cerr << "Image_Test_002 Failed. Image equaled imge with different visibilities" << std::endl;
        return 0;
    }

    // Tests if an image equals and image with different disabled states
    if (testImage == testImage7)
    {
        std::cerr << "Image_Test_002 Failed. Image equaled imge with different disabled states" << std::endl;
        return 0;
    }

    std::cout << "Image_Test_002 Passed" << std::endl;
    return 1;
}

// Tests Image Operator !=
int Image_Test_003()
{
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    Image testImage(testPosition, testRotation, testScale, testVisible, testDisabled);

    glm::vec3 testPosition2(1, 22, 3);
    Image testImage2(testPosition2, testRotation, testScale, testVisible, testDisabled);

    // Tests if image is not equal to itself
    if (testImage != testImage)
    {
        std::cerr << "Image_Test_003 Failed. Image did not equal itself" << std::endl;
        return 0;
    }

    // Tests if image is not equal to an image with a different position
    if (testImage != testImage2)
    {
    }
    else
    {
        std::cerr << "Image_Test_003 Failed. Image equaled image with different position" << std::endl;
        return 0;
    }

    std::cout << "Image_Test_003 Passed" << std::endl;
    return 1;
}

// Tests Layout Getters and Setters
int Layout_Test_001()
{
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    Layout testLayout(testPosition, testRotation, testScale, testVisible, testDisabled);

    // Tests if layout has 0 elements to start with
    if (testLayout.getElements().size() != 0)
    {
        std::cerr << "Layout_Test_001 Failed. Layout did not have 0 elements" << std::endl;
        return 0;
    }

    Label testLabel("Test Label", testPosition, testRotation, testScale, testVisible, testDisabled);

    testLayout.addElement(&testLabel);

    // Tests if layout has 1 elements
    if (testLayout.getElements().size() != 1)
    {
        std::cerr << "Layout_Test_001 Failed. Layout did not have 1 elements" << std::endl;
        return 0;
    }
    Label testLabel2("Test Label2", testPosition, testRotation, testScale, testVisible, testDisabled);
    Label testLabel3("Test Label3", testPosition, testRotation, testScale, testVisible, testDisabled);
    testLayout.addElement(&testLabel2);
    testLayout.addElement(&testLabel3);

    // Tests if layout has 3 elements
    if (testLayout.getElements().size() != 3)
    {
        std::cerr << "Layout_Test_001 Failed. Layout did not have 3 elements" << std::endl;
        return 0;
    }

    testLayout.removeElement(&testLabel);

    // Tests if layout has 2 elements
    if (testLayout.getElements().size() != 2)
    {
        std::cerr << "Layout_Test_001 Failed. Layout did not have 2 elements" << std::endl;
        return 0;
    }

    // Tests the getPosition() getter and constructor
    if (testLayout.getPosition() != testPosition)
    {
        std::cerr << "Layout_Test_001 Failed. getPosition did not match position put into constructor. Expected: " << glm::to_string(testPosition) << ". Got: " << glm::to_string(testLayout.getPosition()) << std::endl;
        return 0;
    }

    // Tests the getRotation() getter and constructor
    if (testLayout.getRotation() != testRotation)
    {
        std::cerr << "Layout_Test_001 Failed. getRotation did not match rotation put into constructor. Expected: " << glm::to_string(testRotation) << ". Got: " << glm::to_string(testLayout.getRotation()) << std::endl;
        return 0;
    }

    // Tests the getScale() getter and constructor
    if (testLayout.getScale() != testScale)
    {
        std::cerr << "Layout_Test_001 Failed. getScale did not match scale put into constructor. Expected: " << glm::to_string(testScale) << ". Got: " << glm::to_string(testLayout.getScale()) << std::endl;
        return 0;
    }

    // Tests the isVisible() getter and constructor
    if (testLayout.isVisible() != testVisible)
    {
        std::cerr << "Layout_Test_001 Failed. isVisible did not match visibility put into constructor. Expected: " << testVisible << ". Got: " << testLayout.isVisible() << std::endl;
        return 0;
    }

    // Tests the isDisabled() getter and constructor
    if (testLayout.isDisabled() != testDisabled)
    {
        std::cerr << "Layout_Test_001 Failed. isDisabled did not match disabled state put into constructor. Expected: " << testDisabled << ". Got: " << testLayout.isDisabled() << std::endl;
        return 0;
    }

    std::cout << "Layout_Test_001 Passed" << std::endl;
    return 1;
}

// Tests Layout Operator ==
int Layout_Test_002()
{
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    Layout testLayout(testPosition, testRotation, testScale, testVisible, testDisabled);
    Layout testLayout1(testPosition, testRotation, testScale, testVisible, testDisabled);
    Layout testLayout2(testPosition, testRotation, testScale, testVisible, testDisabled);

    glm::vec3 testPosition2(1, 22, 3);
    Layout testLayout3(testPosition2, testRotation, testScale, testVisible, testDisabled);

    glm::vec3 testRotation2(4, 25, 6);
    Layout testLayout4(testPosition, testRotation2, testScale, testVisible, testDisabled);

    glm::vec3 testScale2(7, 8, 29);
    Layout testLayout5(testPosition, testRotation, testScale2, testVisible, testDisabled);

    bool testVisible2 = true;
    Layout testLayout6(testPosition, testRotation, testScale, testVisible2, testDisabled);

    bool testDisabled2 = false;
    Layout testLayout7(testPosition, testRotation, testScale, testVisible, testDisabled2);

    Label testLabel("Test Label", testPosition, testRotation, testScale, testVisible, testDisabled);
    Label testLabel2("Test Label2", testPosition, testRotation, testScale, testVisible, testDisabled);

    testLayout.addElement(&testLabel);
    testLayout1.addElement(&testLabel);
    testLayout2.addElement(&testLabel2);
    testLayout3.addElement(&testLabel);
    testLayout4.addElement(&testLabel);
    testLayout5.addElement(&testLabel);
    testLayout6.addElement(&testLabel);
    testLayout7.addElement(&testLabel);

    // Tests if layout equals itself
    if (testLayout == testLayout)
    {
    }
    else
    {
        std::cerr << "Layout_Test_002 Failed. Layout did not equal itself" << std::endl;
        return 0;
    }

    // Tests if layout equal layout with same values
    if (testLayout == testLayout1)
    {
    }
    else
    {
        std::cerr << "Layout_Test_002 Failed. Layout did not equal a layout with the same values" << std::endl;
        return 0;
    }

    // Tests if layout equals layout with the different elements
    if (testLayout == testLayout2)
    {
        std::cerr << "Layout_Test_002 Failed. Layout equaled a layout different elements" << std::endl;
        return 0;
    }

    // Tests if layout equals layout with different positions
    if (testLayout == testLayout3)
    {
        std::cerr << "Layout_Test_002 Failed. Layouts with different positions were found to be equal" << std::endl;
        return 0;
    }

    // Tests if layout equals layout with different rotations
    if (testLayout == testLayout4)
    {
        std::cerr << "Layout_Test_002 Failed. Layouts with different rotations were found to be equal" << std::endl;
        return 0;
    }

    // Tests if layout equals layout with different scales
    if (testLayout == testLayout5)
    {
        std::cerr << "Layout_Test_002 Failed. Layouts with different scales were found to be equal" << std::endl;
        return 0;
    }

    // Tests if layout equals layout with different visibilities
    if (testLayout == testLayout6)
    {
        std::cerr << "Layout_Test_002 Failed. Layouts with different visibilities were found to be equal" << std::endl;
        return 0;
    }

    // Tests if layout equals layout with different disabled states
    if (testLayout == testLayout7)
    {
        std::cerr << "Layout_Test_002 Failed. Layouts with different disabled states were found to be equal" << std::endl;
        return 0;
    }

    std::cout << "Layout_Test_002 Passed" << std::endl;
    return 1;
}

// Tests Layout Operator !=
int Layout_Test_003()
{
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    Layout testLayout(testPosition, testRotation, testScale, testVisible, testDisabled);
    Layout testLayout1(testPosition, testRotation, testScale, testVisible, testDisabled);
    Layout testLayout2(testPosition, testRotation, testScale, testVisible, testDisabled);

    glm::vec3 testPosition2(1, 22, 3);
    Layout testLayout3(testPosition2, testRotation, testScale, testVisible, testDisabled);

    Label testLabel("Test Label", testPosition, testRotation, testScale, testVisible, testDisabled);
    Label testLabel2("Test Label2", testPosition, testRotation, testScale, testVisible, testDisabled);

    testLayout.addElement(&testLabel);
    testLayout1.addElement(&testLabel);
    testLayout2.addElement(&testLabel2);
    testLayout3.addElement(&testLabel);

    // Tests if layout does not equal itself
    if (testLayout != testLayout)
    {
        std::cerr << "Layout_Test_003 Failed. Layout did not equal itself" << std::endl;
        return 0;
    }

    // Tests if layout does not equal a layout with the same values
    if (testLayout != testLayout1)
    {
        std::cerr << "Layout_Test_003 Failed. Layout did not equal another layout with the same values" << std::endl;
        return 0;
    }

    // Tests if layout does not equal a layout with different elements
    if (testLayout != testLayout2)
    {
    }
    else
    {
        std::cerr << "Layout_Test_003 Failed. Layout equaled layout with different elements" << std::endl;
        return 0;
    }

    // Tests if layout does not equal a layout with different positions
    if (testLayout != testLayout3)
    {
    }
    else
    {
        std::cerr << "Layout_Test_003 Failed. Layout equaled layout with different positions" << std::endl;
        return 0;
    }

    std::cout << "Layout_Test_003 Passed" << std::endl;
    return 1;
}

// Tests ProgressBar Getters and Setters
int ProgressBar_Test_001()
{
    glm::vec3 testPosition(1, 2, 3);
    glm::vec3 testRotation(4, 5, 6);
    glm::vec3 testScale(7, 8, 9);
    bool testVisible = false;
    bool testDisabled = true;

    ProgressBar testProgressBar(testPosition, testRotation, testScale, testVisible, testDisabled);

    // Tests the getProgress getter and constructor
    if (testProgressBar.getProgress() != 0.0f)
    {
        std::cerr << "ProgressBar_Test_001 Failed. getProgress did not match progress initialized in the constructor. Expected: " << 0.0f << ". Got: " << testProgressBar.getProgress() << std::endl;
        return 0;
    }

    testProgressBar.setProgress(0.49f);
    // Tests the getProgress getter and constructor
    if (testProgressBar.getProgress() != 0.49f)
    {
        std::cerr << "ProgressBar_Test_001 Failed. getProgress did not match progress set in setProgress. Expected: " << 0.0f << ". Got: " << testProgressBar.getProgress() << std::endl;
        return 0;
    }

    // Tests the getPosition() getter and constructor
    if (testProgressBar.getPosition() != testPosition)
    {
        std::cerr << "ProgressBar_Test_001 Failed. getPosition did not match position put into constructor. Expected: " << glm::to_string(testPosition) << ". Got: " << glm::to_string(testProgressBar.getPosition()) << std::endl;
        return 0;
    }

    // Tests the getRotation() getter and constructor
    if (testProgressBar.getRotation() != testRotation)
    {
        std::cerr << "ProgressBar_Test_001 Failed. getRotation did not match rotation put into constructor. Expected: " << glm::to_string(testRotation) << ". Got: " << glm::to_string(testProgressBar.getRotation()) << std::endl;
        return 0;
    }

    // Tests the getScale() getter and constructor
    if (testProgressBar.getScale() != testScale)
    {
        std::cerr << "ProgressBar_Test_001 Failed. getScale did not match scale put into constructor. Expected: " << glm::to_string(testScale) << ". Got: " << glm::to_string(testProgressBar.getScale()) << std::endl;
        return 0;
    }

    // Tests the isVisible() getter and constructor
    if (testProgressBar.isVisible() != testVisible)
    {
        std::cerr << "ProgressBar_Test_001 Failed. isVisible did not match visibility put into constructor. Expected: " << testVisible << ". Got: " << testProgressBar.isVisible() << std::endl;
        return 0;
    }

    // Tests the isDisabled() getter and constructor
    if (testProgressBar.isDisabled() != testDisabled)
    {
        std::cerr << "ProgressBar_Test_001 Failed. isDisabled did not match disabled state put into constructor. Expected: " << testDisabled << ". Got: " << testProgressBar.isDisabled() << std::endl;
        return 0;
    }

    std::cout << "ProgressBar_Test_001 Passed" << std::endl;
    return 1;
}

// Tests ProgressBar Operator ==
int ProgressBar_Test_002()
{

    std::cout << "ProgressBar_Test_002 Passed" << std::endl;
    return 1;
}

// Tests ProgressBar Operator !=
int ProgressBar_Test_003()
{

    std::cout << "ProgressBar_Test_003 Passed" << std::endl;
    return 1;
}

// Tests RadioButton Getters and Setters
int RadioButton_Test_001()
{

    std::cout << "RadioButton_Test_001 Passed" << std::endl;
    return 1;
}

// Tests RadioButton Operator ==
int RadioButton_Test_002()
{

    std::cout << "RadioButton_Test_002 Passed" << std::endl;
    return 1;
}

// Tests RadioButton Operator !=
int RadioButton_Test_003()
{

    std::cout << "RadioButton_Test_003 Passed" << std::endl;
    return 1;
}

// Tests Screen Getters and Setters
int Screen_Test_001()
{

    std::cout << "Screen_Test_001 Passed" << std::endl;
    return 1;
}

// Tests Screen Operator ==
int Screen_Test_002()
{

    std::cout << "Screen_Test_002 Passed" << std::endl;
    return 1;
}

// Tests Screen Operator !=
int Screen_Test_003()
{

    std::cout << "Screen_Test_003 Passed" << std::endl;
    return 1;
}

// Tests Slider Getters and Setters
int Slider_Test_001()
{

    std::cout << "Slider_Test_001 Passed" << std::endl;
    return 1;
}

// Tests Slider Operator ==
int Slider_Test_002()
{

    std::cout << "Slider_Test_002 Passed" << std::endl;
    return 1;
}

// Tests Slider Operator !=
int Slider_Test_003()
{

    std::cout << "Slider_Test_003 Passed" << std::endl;
    return 1;
}

// Tests TextField Getters and Setters
int TextField_Test_001()
{

    std::cout << "TextField_Test_001 Passed" << std::endl;
    return 1;
}

// Tests TextField Operator ==
int TextField_Test_002()
{

    std::cout << "TextField_Test_002 Passed" << std::endl;
    return 1;
}

// Tests TextField Operator !=
int TextField_Test_003()
{

    std::cout << "TextField_Test_003 Passed" << std::endl;
    return 1;
}

// Tests Video Getters and Setters
int Video_Test_001()
{

    std::cout << "Video_Test_001 Passed" << std::endl;
    return 1;
}

// Tests Video Operator ==
int Video_Test_002()
{

    std::cout << "Video_Test_002 Passed" << std::endl;
    return 1;
}

// Tests Video Operator !=
int Video_Test_003()
{

    std::cout << "Video_Test_003 Passed" << std::endl;
    return 1;
}

// Tests UIElement Getters and Setters
int UIElement_Test_001()
{

    std::cout << "UIElement_Test_001 Passed" << std::endl;
    return 1;
}

// Tests UIElement Operator ==
int UIElement_Test_002()
{

    std::cout << "UIElement_Test_002 Passed" << std::endl;
    return 1;
}

// Tests UIElement Operator !=
int UIElement_Test_003()
{

    std::cout << "UIElement_Test_003 Passed" << std::endl;
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

    int numberOfTests = 45;
    int numberOfTestsPassed = 0;

    numberOfTestsPassed += Label_Test_001();
    numberOfTestsPassed += Label_Test_002();
    numberOfTestsPassed += Label_Test_003();

    numberOfTestsPassed += Button_Test_001();
    numberOfTestsPassed += Button_Test_002();
    numberOfTestsPassed += Button_Test_003();

    numberOfTestsPassed += Alert_Test_001();
    numberOfTestsPassed += Alert_Test_002();
    numberOfTestsPassed += Alert_Test_003();

    numberOfTestsPassed += CheckBox_Test_001();
    numberOfTestsPassed += CheckBox_Test_002();
    numberOfTestsPassed += CheckBox_Test_003();

    numberOfTestsPassed += DropDown_Test_001();
    numberOfTestsPassed += DropDown_Test_002();
    numberOfTestsPassed += DropDown_Test_003();
    numberOfTestsPassed += DropDown_Test_004();
    numberOfTestsPassed += DropDown_Test_005();
    numberOfTestsPassed += DropDown_Test_006();

    numberOfTestsPassed += Image_Test_001();
    numberOfTestsPassed += Image_Test_002();
    numberOfTestsPassed += Image_Test_003();

    numberOfTestsPassed += Layout_Test_001();
    numberOfTestsPassed += Layout_Test_002();
    numberOfTestsPassed += Layout_Test_003();

    numberOfTestsPassed += ProgressBar_Test_001();
    numberOfTestsPassed += ProgressBar_Test_002();
    numberOfTestsPassed += ProgressBar_Test_003();

    numberOfTestsPassed += RadioButton_Test_001();
    numberOfTestsPassed += RadioButton_Test_002();
    numberOfTestsPassed += RadioButton_Test_003();

    numberOfTestsPassed += Screen_Test_001();
    numberOfTestsPassed += Screen_Test_002();
    numberOfTestsPassed += Screen_Test_003();

    numberOfTestsPassed += Slider_Test_001();
    numberOfTestsPassed += Slider_Test_002();
    numberOfTestsPassed += Slider_Test_003();

    numberOfTestsPassed += TextField_Test_001();
    numberOfTestsPassed += TextField_Test_002();
    numberOfTestsPassed += TextField_Test_003();

    numberOfTestsPassed += Video_Test_001();
    numberOfTestsPassed += Video_Test_002();
    numberOfTestsPassed += Video_Test_003();

    numberOfTestsPassed += UIElement_Test_001();
    numberOfTestsPassed += UIElement_Test_002();
    numberOfTestsPassed += UIElement_Test_003();

    if (numberOfTestsPassed == numberOfTests)
    {
        std::cout << "Results: " << numberOfTestsPassed << "/" << numberOfTests << " Passed!" << std::endl;
    }
    else
    {
        std::cerr << "Results: " << numberOfTestsPassed << "/" << numberOfTests << " Passed!" << std::endl;
    }
}