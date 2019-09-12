#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "singletonrxtx.h"
#include "udpconnection.h"
#include "joystickcontrol.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    Ui::MainWindow *ui;
    ~MainWindow();
    UDPconnection *UDPconnect;
    JoystickControl *JoyControl;
    QByteArray Datagram;
    QTimer *Tim;
    QTimer *TimBaraban;


public slots:
    void on_pushButton_clicked();
    void SendData();

private:
    SingletonRxTx *rxtx;

};

#endif // MAINWINDOW_H
