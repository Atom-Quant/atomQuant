#ifndef CTPQUOTATION_H
#define CTPQUOTATION_H

#include "quotation.h"
#include "ThostFtdcMdApi.h"

class CtpQuotation : public Quotation, CThostFtdcMdSpi
{
public:
    CtpQuotation();
    virtual ~CtpQuotation();

    //quotation overload
    virtual void connect();
    virtual void close();
    virtual void subscribe(char** pInstrumentID, int count);
    virtual void unsubscribe(char** pInstrumentID, int count);
//    virtual void onTick();

    //mdspi overload
    virtual void OnFrontConnected();
    virtual void OnFrontDisconnected(int nReason);
    virtual void OnHeartBeatWarning(int nTimeLapse);
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);


private:
    CThostFtdcMdApi* mdApi;
    QSettings* settings;
};

#endif // CTPQUOTATION_H
