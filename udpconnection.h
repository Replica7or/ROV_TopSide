#ifndef UDPCONNECTION_H
#define UDPCONNECTION_H

#include <QObject>
#include <QDebug>
#include <QUdpSocket>

class UDPconnection : public QObject
{
    Q_OBJECT
public:
    explicit UDPconnection(QObject *parent = nullptr);
    QUdpSocket *socket;
    void udpRead();

private:
    const quint16 m_port = 10006;
       const QHostAddress m_rovIp;
       const quint16 m_rovPort = 10006;
       QScopedPointer<QUdpSocket> m_socket;

signals:
    void dataReceived(QByteArray datagram);
    void singnalExample(QString str);


public slots:
    void transmitDatagram(QByteArray datagram);

};

#endif // UDPCONNECTION_H
