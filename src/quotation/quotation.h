#ifndef MARKETDATA_H
#define MARKETDATA_H

#include <QObject>

class Quotation : public QObject
{
    Q_OBJECT
public:
    explicit Quotation(QObject *parent = nullptr);
    virtual ~Quotation();

    virtual void connect()=0;
    virtual void close()=0;
    virtual void subscribe()=0;
    virtual void unsubscribe()=0;
    virtual void onTick()=0;

protected:
    bool isConnected;


signals:

public slots:
};

#endif // MARKETDATA_H
