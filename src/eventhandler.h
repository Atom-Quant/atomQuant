#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include <QEvent>

class EventHandler : public QObject
{
    Q_OBJECT
public:
    explicit EventHandler(QObject *parent = nullptr);

    bool event(QEvent* ev) override;

signals:

public slots:
};

#endif // EVENTHANDLER_H
