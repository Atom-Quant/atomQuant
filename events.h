#ifndef EVENTS_H
#define EVENTS_H

#include <QEvent>
#include "global.h"


enum EventType {
    TICKEVENT=2000,
    ORDEREVENT,
};

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


enum OrderDirection {
    BUY,
    SELL
};

struct Order
{
    QString exchange;
    QString symbol;
    OrderDirection direction;
};


class OrderEvent : public QEvent {
public:
    static const QEvent::Type  eventType = static_cast<QEvent::Type>(ORDEREVENT);
    OrderEvent(Order* order) : QEvent(OrderEvent::type()), order(order){
    }
    ~OrderEvent(){
        delete order;
    }

    Order* order;
};

#endif // EVENTS_H
