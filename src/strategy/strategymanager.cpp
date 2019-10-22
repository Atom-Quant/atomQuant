#include "strategymanager.h"
#include "twinmovingaverage.h"

StrategyManager* StrategyManager::pInstance = nullptr;

StrategyManager::StrategyManager(QObject *parent) : QObject(parent), _sid(1)
{

}

StrategyManager* StrategyManager::instance()
{
    if(pInstance == nullptr)
    {
        pInstance = new StrategyManager();
    }
    return pInstance;
}

void StrategyManager::destroy()
{
    delete pInstance;
    pInstance = nullptr;
}

void StrategyManager::initTwinMovingAverage()
{
    Strategy* strategy = new TwinMovingAverage(_sid++);
}
