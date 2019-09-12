#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QChar>
#include <QByteArray>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    UDPconnect = new UDPconnection();
    Tim = new QTimer(this);
    Tim->setInterval(25);
    Tim->start();
    Datagram.resize(11);

    connect(UDPconnect,SIGNAL(singnalExample(QString)),this,SLOT(on_pushButton_clicked()));
    //connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(SendData()) );
    connect(Tim,SIGNAL(timeout()),this,SLOT(SendData()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Tim;
    delete TimBaraban;
}

void MainWindow::on_pushButton_clicked()
{
    //ui->TextEdit->append(rxtx->getInstance().RecievedString);
    //QChar C = rxtx->getInstance().RecievedString.data()[0];
    //int num = rxtx->getInstance().RecievedString.data()[0].unicode();
    //ui->TextEdit->append(QString::number(rxtx->getInstance().RecievedString.data()[0].unicode())
      //      +" "+QString::number(rxtx->getInstance().RecievedString.data()[1].unicode())
        //    +" "+QString::number(rxtx->getInstance().RecievedString.data()[2].unicode()));
    //ui->TextEdit->append(QString::number(rxtx->getInstance().RecievedString.data()[1].unicode()));
    //ui->TextEdit->append(QString::number(rxtx->getInstance().RecievedString.data()[2].unicode()));
}

void MainWindow::SendData()
{
    sf::Joystick::update();
    Datagram[0]=0xAB;
    Datagram[1]=0xAB;
    Datagram[2]=JoyControl->GetAxisX()+7;
    Datagram[3]=JoyControl->GetAxisY()+7;
    Datagram[4]=JoyControl->GetAxisR()+7;
    Datagram[5]=JoyControl->GetAxisZ()+7;

    //
    //Joystick open close
    //
    if(sf::Joystick::isButtonPressed(0,0))
    {
        Datagram[6]=1;
    }
    else
        if (sf::Joystick::isButtonPressed(0,1))
            Datagram[6]=2;
        else
            Datagram[6]=0;

    //
    //Joystick turn
    //
    if(JoyControl->GetAXisU()==0)
        Datagram[7]=1;
    else
        if (JoyControl->GetAXisU()==200)
            Datagram[7]=2;
        else
            Datagram[7]=0;

    if(sf::Joystick::isButtonPressed(0,5))
    {
        if(ui->DiafragmSwitch->isChecked())
            Datagram[8]=2;
        else
            Datagram[8]=1;
    }
    else Datagram[8]=0;


    if(sf::Joystick::isButtonPressed(0,6))
    {
        if(ui->WireSwitch->isChecked())
            Datagram[9]=2;
        else
            Datagram[9]=1;
    }
    else Datagram[9]=0;



    if(ui->MiniROV->isChecked())
        Datagram[10]= 1;
    else
        Datagram[10]= 0;

    UDPconnect->transmitDatagram(Datagram);
    qDebug()<<JoyControl->GetAxisX()<<JoyControl->GetAxisY()<<sf::Joystick::getAxisPosition(0,sf::Joystick::R)<<JoyControl->GetAxisZ()<<JoyControl->GetAXisU()<<JoyControl->GetButton_5()<<JoyControl->GetButton_6()<<sf::Joystick::isButtonPressed(0,10);
}
