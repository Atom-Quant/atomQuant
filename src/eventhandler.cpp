#include "eventhandler.h"
#include "global.h"
#include <iostream>
#include "quotation.h"

using namespace std;

EventHandler::EventHandler(QObject *parent) : QObject(parent)
{

}

bool EventHandler::event(QEvent* ev)
{
    if (ev->type() == (QEvent::Type)TICKEVENT) {
        std::cout << "on tick event handler" << std::endl;
        TickEvent* tickEvent = (TickEvent*)ev;
        Tick* tick = tickEvent->tick;
        //TODO: send to strategy

        return true;
     } else  if (ev->type() == QEvent::Show) {

        return true;
     }
     // Make sure the rest of events are handled
     return QObject::event(ev);
}
