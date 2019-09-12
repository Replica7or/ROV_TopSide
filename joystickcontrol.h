#ifndef JOYSTICKCONTROL_H
#define JOYSTICKCONTROL_H

#include <QObject>
#include <QDebug>
#include "singletonrxtx.h"
#include "SFML/Graphics.hpp"

class JoystickControl : public QObject
{
    Q_OBJECT
public:
    explicit JoystickControl(QObject *parent = nullptr);
    int GetAxisX();
    int GetAxisY();
    int GetAxisR();
    int GetAxisZ();
    int GetAXisU();
    int GetButton_1();
    int GetButton_2();
    int GetButton_3();
    int GetButton_4();
    int GetButton_5();
    int GetButton_6();
    int GetButton_7();
    int GetButton_8();
    int GetButton_9();

signals:

public slots:

private:
    SingletonRxTx *rxtx;

};

#endif // JOYSTICKCONTROL_H
