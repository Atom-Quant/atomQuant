#ifndef STRATEGYMANAGER_H
#define STRATEGYMANAGER_H

#include <QObject>
#include <QMap>
#include "strategy.h"

class StrategyManager : public QObject
{
    Q_OBJECT
public:
     static StrategyManager* instance();
     static void destroy();

     void initTwinMovingAverage();

private:
    static StrategyManager* pInstance;
    StrategyManager(QObject *parent = nullptr);

    QMap<int, Strategy*> _sid2strategyMap;
    int _sid;
};

#endif // STRATEGYMANAGER_H
