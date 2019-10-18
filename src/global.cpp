#include "global.h"

int g_ctpReqId = 0;

//EXCHANGE g_exchange = CFFEX;

QMap<QString, EXCHANGE> g_exchangeMap = {
    std::pair<QString, EXCHANGE>("CFFEX", CFFEX),
    std::pair<QString, EXCHANGE>("SHFE", SHFE),
    std::pair<QString, EXCHANGE>("CZCE", CZCE),
    std::pair<QString, EXCHANGE>("DCE", DCE),
};
