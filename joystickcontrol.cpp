#include "joystickcontrol.h"

JoystickControl::JoystickControl(QObject *parent) : QObject(parent)
{

}


int JoystickControl::GetAxisX()
{
    int AxisValue = sf::Joystick::getAxisPosition(0,sf::Joystick::X)+100;
    return AxisValue;
}

int JoystickControl::GetAxisY()
{
    int AxisValue = sf::Joystick::getAxisPosition(0,sf::Joystick::Y)+100;
    return AxisValue;
}

int JoystickControl::GetAxisR()
{
    int AxisValue = sf::Joystick::getAxisPosition(0,sf::Joystick::R)+100;
    return AxisValue;
}

int JoystickControl::GetAxisZ()
{
    int AxisValue = sf::Joystick::getAxisPosition(0,sf::Joystick::Z)+100;
}

int JoystickControl::GetAXisU()
{
    int AxisValue = sf::Joystick::getAxisPosition(0,sf::Joystick::U)+100;
    return AxisValue;
}
int JoystickControl::GetButton_1()
{

    int ButtonValue;
    if(sf::Joystick::isButtonPressed(0,1))
    {
        return 1;
    }
    else return 0;
}

int JoystickControl::GetButton_5()
{

    int ButtonValue;
    if(sf::Joystick::isButtonPressed(0,5))
    {
        return 1;
    }
    else return 0;
}


int JoystickControl::GetButton_6()
{
    if(sf::Joystick::isButtonPressed(0,6))
    {
        return 1;
    }
    else return 0;
}
