#ifndef SINGLETONRXTX_H
#define SINGLETONRXTX_H
#include <QString>

class SingletonRxTx
{
private:
    SingletonRxTx() {}
    SingletonRxTx( const SingletonRxTx&);
    SingletonRxTx& operator = ( SingletonRxTx&);
public:

    QString RecievedString;

    static SingletonRxTx& getInstance()
    {
        static SingletonRxTx instance;
        return instance;
    }
};

#endif // SINGLETONRXTX_H
