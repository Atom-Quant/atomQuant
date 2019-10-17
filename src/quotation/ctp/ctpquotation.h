#ifndef CTPQUOTATION_H
#define CTPQUOTATION_H

#include "quotation.h"
#include "ThostFtdcMdApi.h"

class CtpQuotation : public Quotation
{
public:
    CtpQuotation();
    virtual ~CtpQuotation();


    virtual void connect();
    virtual void close();
    virtual void subscribe();
    virtual void unsubscribe();
    virtual void onTick();


private:
    CThostFtdcMdApi *mdApi;
};

#endif // CTPQUOTATION_H
