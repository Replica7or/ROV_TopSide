#include "udpconnection.h"
#include "mainwindow.h"


UDPconnection::UDPconnection(QObject *parent) : QObject(parent), m_rovIp("192.168.0.7"), m_socket(new QUdpSocket(this))
{
   connect(m_socket.data(), &QUdpSocket::readyRead, this,&UDPconnection::udpRead);

    bool conect = m_socket->bind(QHostAddress("192.168.0.200"),10006);
    qDebug()<<conect;
}


void UDPconnection::udpRead()
{
    QByteArray datagram;
       do {
           datagram.resize(m_socket->pendingDatagramSize());
           m_socket->readDatagram(datagram.data(), datagram.size());

          SingletonRxTx *rxtx;
          rxtx->getInstance().RecievedString = datagram.operator const char *();

          emit singnalExample(datagram.data());
       } while (m_socket->hasPendingDatagrams());
       emit dataReceived(datagram);
    //transmitDatagram("MATE_FINISH");
}

void UDPconnection::transmitDatagram(QByteArray datagram)
{
    m_socket->writeDatagram(datagram,QHostAddress("192.168.0.7"),10006);
}
