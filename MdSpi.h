#pragma once
#include "include/ThostFtdcMdApi.h"

class MdSpi : public CThostFtdcMdSpi
{
  public:
    MdSpi(CThostFtdcMdApi *api_) : api(api_) {}
    ~MdSpi() {}
    virtual void OnFrontConnected();
    virtual void OnFrontDisconnected(int nReason);
    virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo,
                            int nRequestID, bool bIsLast);
    virtual void OnHeartBeatWarning(int nTimeLapse);
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
                                CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                                bool bIsLast);
    virtual void OnRspSubscribeMarketData(
        CThostFtdcSpecificInstrumentField *pSpecificInstrument,
        CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void
    OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);
    virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

  private:
    CThostFtdcMdApi *api;
    int requestId = 0;
    void ReqUserLogin();
    void SubscribeMarketData();
    bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);
};