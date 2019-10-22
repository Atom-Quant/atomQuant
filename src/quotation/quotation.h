#ifndef MARKETDATA_H
#define MARKETDATA_H

#include <QObject>
#include <QSettings>

#include "global.h"


class Quotation : public QObject
{
    Q_OBJECT
public:
    explicit Quotation(QObject *parent = nullptr);
    virtual ~Quotation();

    virtual void connect()=0;
    virtual void close()=0;
    virtual void subscribe(char** pInstrumentID, int count)=0;
    virtual void unsubscribe(char** pInstrumentID, int count)=0;
    void onTick(Tick* tick);

protected:
    bool isConnected;

signals:

public slots:
};

#endif // MARKETDATA_H
