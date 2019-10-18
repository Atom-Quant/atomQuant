#ifndef MARKETDATA_H
#define MARKETDATA_H

#include <QObject>
#include <QSettings>

#include "global.h"

struct Tick
{
    QString dateTime;
    QString symbol;
    EXCHANGE exchange;
    int volume;
    double openInterest;
    double lastPrice;
    double limitUp;
    double limitDown;
    double openPrice;
    double highPrice;
    double lowPrice;
    double preClose;
    double bidPrice1;
    double askPrice1;
    int bidVolume1;
    int askVolume1;
};

class TickEvent : public QEvent {
public:
    static const QEvent::Type  eventType = static_cast<QEvent::Type>(TICKEVENT);
    TickEvent(Tick* tick) : QEvent(TickEvent::type()), tick(tick){
    }
    ~TickEvent(){
        delete tick;
    }

    Tick* tick;
};



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
