#ifndef CTPQUOTATION_H
#define CTPQUOTATION_H

#include "quotation.h"
#include "ThostFtdcMdApi.h"

class CtpQuotation : public Quotation
{
public:
    CtpQuotation();

    virtual void connect();
    virtual void close();
    virtual void subscribe();
    virtual void unsubscribe();
};

#endif // CTPQUOTATION_H
