#include "ctpquotation.h"
#include "ctpmdspi.h"

CtpQuotation::CtpQuotation()
{
    mdApi = CThostFtdcMdApi::CreateFtdcMdApi();
    CtpMdSpi* mdSpi = new CtpMdSpi(mdApi);
    mdApi->RegisterSpi(mdSpi);
    mdApi->RegisterFront(Market_FRONT_1);
    mdApi->Init();
}

CtpQuotation::~CtpQuotation()
{
    mdApi->Release();
}
