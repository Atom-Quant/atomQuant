#include "ctpmdspi.h"
#include "ThostFtdcUserApiStruct.h"
#include <cassert>
#include <cstring>
#include <iostream>


CtpMdSpi::CtpMdSpi(CtpQuotation* ctpQuotation)
{
    this->ctpQuotation = ctpQuotation;
}

/*!
 * \brief CtpMdSpi::OnFrontConnected
 *
 */
void CtpMdSpi::OnFrontConnected()
{
    std::cout << "CtpMdSpi::OnFrontConnected" << std::endl;

    //登录
    CThostFtdcReqUserLoginField field;
    memset(&field, 0, sizeof(field));
    strcpy(field.BrokerID, BROKERID);
    strcpy(field.UserID, USERID);
    strcpy(field.Password, PASSWORD);
    int ret = mdApi->ReqUserLogin(&field, ++reqId);
}

/*!
 * \brief CtpMdSpi::OnFrontDisconnected
 *
 */
void CtpMdSpi::OnFrontDisconnected(int nReason)
{
    std::cout << "CtpMdSpi::OnFrontDisconnected  nReason:" << nReason << std::endl;
}

void CtpMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
    std::cout << "CtpMdSpi::OnHeartBeatWarning  nTimeLapse:" << nTimeLapse << std::endl;
}

/*!
 * \brief CtpMdSpi::OnRspUserLogin
 *
 */
void CtpMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    std::cout << "CtpMdSpi::OnRspUserLogin"
              << "ErrorID:" << pRspInfo->ErrorID << "  "
              << "ErrorMsg:" << pRspInfo->ErrorMsg << "  "
              << "LoginTime:" << pRspUserLogin->LoginTime << "  "
              << "UserID:" << pRspUserLogin->UserID << "  "
              << "TradingDay:" << pRspUserLogin->TradingDay << "  "
              << std::endl;


    //订阅行情
    char *ppInstrumentID[] = { "au1906", "ag1906", "al1905", NULL };
    int count = 3;
    mdApi->SubscribeMarketData(ppInstrumentID, count);
}

/*!
 * \brief CtpMdSpi::OnRspUserLogout
 *
 */
void CtpMdSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    std::cout << "OnRspUserLogout" << std::endl;
}

/*!
 * \brief CtpMdSpi::OnRspSubMarketData
 *
 */
void CtpMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    std::cout << "CtpMdSpi::OnRspSubMarketData "
              << pSpecificInstrument->InstrumentID
              << std::endl;
}

/*!
 * \brief CtpMdSpi::OnRspUnSubMarketData
 *
 */
void CtpMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    std::cout << "OnRspUnSubMarketData" << std::endl;
}

/*!
 * \brief CtpMdSpi::OnRtnDepthMarketData
 *
 */
void CtpMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
    std::cout << "CtpMdSpi::OnRtnDepthMarketData"
              << "TradingDay:" << pDepthMarketData->TradingDay << " "
              << "InstrumentID:" << pDepthMarketData->InstrumentID << " "
              << "LastPrice:" << pDepthMarketData->LastPrice << " "
              << std::endl;
}

