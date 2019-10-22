#ifndef STRATEGY_H
#define STRATEGY_H

#include <QObject>

#include "quotation.h"
#include "events.h"


class Strategy
{
public:
    Strategy(int sid);
    virtual ~Strategy();

    virtual void init();
    virtual void onTick(Tick* tick);

    void start();
    void stop();

protected:
    void buy(QString exchange, QString symbol);
    void sell(QString exchange, QString symbol);

private:
    int sid;

};

#endif // STRATEGY_H
