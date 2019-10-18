#include "ctpquotation.h"
#include <iostream>
#include "global.h"

CtpQuotation::CtpQuotation()
{
    settings = new QSettings("settings.ini", QSettings::IniFormat);
    mdApi = CThostFtdcMdApi::CreateFtdcMdApi();
    mdApi->RegisterSpi(this);
    mdApi->Init();
}

CtpQuotation::~CtpQuotation()
{
    mdApi->Release();
}

void CtpQuotation::connect()
{
    settings->beginGroup("ctpQuotation");
    QString frontAddress = settings->value("frontAddress").toString();
    settings->endGroup();

    mdApi->RegisterFront((char*)frontAddress.toStdString().c_str());
}

void CtpQuotation::close()
{

}

void CtpQuotation::subscribe(char** pInstrumentID, int count)
{
    mdApi->SubscribeMarketData(pInstrumentID, count);
}

void CtpQuotation::unsubscribe(char** pInstrumentID, int count)
{
    mdApi->UnSubscribeMarketData(pInstrumentID, count);
}

void CtpQuotation::OnFrontConnected()
{
    std::cout << "CtpQuotation::OnFrontConnected" << std::endl;

    isConnected = true;

    settings->beginGroup("ctpQuotation");
    QString brokerId = settings->value("brokerId").toString();
    QString userId = settings->value("userId").toString();
    QString password = settings->value("password").toString();
    settings->endGroup();

    //login
    CThostFtdcReqUserLoginField field;
    memset(&field, 0, sizeof(field));
    strcpy(field.BrokerID, brokerId.toStdString().c_str());
    strcpy(field.UserID, userId.toStdString().c_str());
    strcpy(field.Password, password.toStdString().c_str());
    int ret = mdApi->ReqUserLogin(&field, ++g_ctpReqId);

    std::cout << "CtpQuotation::OnFrontConnected ret" << ret <<  std::endl;
}

void CtpQuotation::OnFrontDisconnected(int nReason)
{
    std::cout << "CtpQuotation::OnFrontDisconnected  nReason:" << nReason << std::endl;
    isConnected = false;
}

void CtpQuotation::OnHeartBeatWarning(int nTimeLapse)
{
    std::cout << "CtpQuotation::OnHeartBeatWarning  nTimeLapse:" << nTimeLapse << std::endl;
}

void CtpQuotation::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    std::cout << "CtpQuotation::OnRspUserLogin"
              << "ErrorID:" << pRspInfo->ErrorID << "  "
              << "ErrorMsg:" << pRspInfo->ErrorMsg << "  "
              << "LoginTime:" << pRspUserLogin->LoginTime << "  "
              << "UserID:" << pRspUserLogin->UserID << "  "
              << "TradingDay:" << pRspUserLogin->TradingDay << "  "
              << std::endl;
}


void CtpQuotation::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    std::cout << "OnRspUserLogout" << std::endl;
}


void CtpQuotation::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    std::cout << "CtpQuotation::OnRspSubMarketData "
              << pSpecificInstrument->InstrumentID
              << std::endl;
}

void CtpQuotation::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    std::cout << "OnRspUnSubMarketData" << std::endl;
}


void CtpQuotation::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
    std::cout << "CtpQuotation::OnRtnDepthMarketData"
              << "TradingDay:" << pDepthMarketData->TradingDay << " "
              << "InstrumentID:" << pDepthMarketData->InstrumentID << " "
              << "LastPrice:" << pDepthMarketData->LastPrice << " "
              << std::endl;

    Tick* tick = new Tick;;
    tick->dateTime = QString("%1 %2.%3").arg(pDepthMarketData->ActionDay).arg(pDepthMarketData->UpdateTime).arg(pDepthMarketData->UpdateMillisec);
    tick->symbol = pDepthMarketData->InstrumentID;
    tick->exchange = g_exchangeMap[pDepthMarketData->ExchangeID];
    tick->volume = pDepthMarketData->Volume;
    tick->openInterest = pDepthMarketData->OpenInterest;
    tick->lastPrice = pDepthMarketData->LastPrice;
    tick->limitUp = pDepthMarketData->UpperLimitPrice;
    tick->limitDown = pDepthMarketData->LowerLimitPrice;
    tick->openPrice = pDepthMarketData->OpenPrice;
    tick->highPrice = pDepthMarketData->HighestPrice;
    tick->lowPrice = pDepthMarketData->LowestPrice;
    tick->preClose = pDepthMarketData->PreClosePrice;
    tick->bidPrice1 = pDepthMarketData->BidPrice1;
    tick->askPrice1 = pDepthMarketData->AskPrice1;
    tick->bidVolume1 = pDepthMarketData->BidVolume1;
    tick->askVolume1 = pDepthMarketData->BidVolume1;

    onTick(tick);
}
