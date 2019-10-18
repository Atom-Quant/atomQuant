#ifndef GLOBAL_H
#define GLOBAL_H

#include <QMap>
#include "eventhandler.h"

extern int g_ctpReqId;

enum EXCHANGE {
    CFFEX,
    SHFE,
    CZCE,
    DCE,
};

extern QMap<QString, EXCHANGE> g_exchangeMap;

extern EventHandler* g_eventHandler;

enum EventType {
    TICKEVENT=2000,
};




#endif // GLOBAL_H
