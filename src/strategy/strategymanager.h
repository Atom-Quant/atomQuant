#ifndef STRATEGYMANAGER_H
#define STRATEGYMANAGER_H

#include <QObject>

class StrategyManager : public QObject
{
    Q_OBJECT
public:
    explicit StrategyManager(QObject *parent = nullptr);

signals:

public slots:
};

#endif // STRATEGYMANAGER_H
