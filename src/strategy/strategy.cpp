#include "strategy.h"
#include "events.h"
#include <QCoreApplication>

Strategy::Strategy(int sid)
{
    this->sid = sid;
}

void Strategy::buy(QString exchange, QString symbol)
{
    Order* order = new Order;
    order->exchange = exchange;
    order->symbol = symbol;
    order->direction = OrderDirection::BUY;
    OrderEvent* orderEvent = new OrderEvent(order);
    QCoreApplication::postEvent(g_eventHandler, orderEvent);
}

void Strategy::sell(QString exchange, QString symbol)
{
    Order* order = new Order;
    order->exchange = exchange;
    order->symbol = symbol;
    order->direction = OrderDirection::SELL;
    OrderEvent* orderEvent = new OrderEvent(order);
    QCoreApplication::postEvent(g_eventHandler, orderEvent);
}
