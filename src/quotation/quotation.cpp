#include "quotation.h"
#include <QCoreApplication>
#include "global.h"

Quotation::Quotation(QObject *parent) : QObject(parent)
{

}

void Quotation::onTick(Tick* tick)
{
    TickEvent* tickEvent = new TickEvent(tick);
    QCoreApplication::postEvent(g_eventHandler, tickEvent);
}
