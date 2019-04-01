#ifndef UARTPS_H
#define UARTPS_H
#include "UARTDev.h"
//#include <iostream>
#include <string>
  using namespace std;

//宏定义
#define WAIT_RES_TIME 0.01
class UartPS:public UARTDev
{
public:
    UartPS();

    unsigned char bytDevType;
    unsigned char bytDevInfo;

    int StartTrans(unsigned char  acData[],string &strErr);
    int ReadDevInfo(unsigned char  acData[],string & strErr);
    int Reboot(unsigned char  acData[],string &strErr);
    int ReadVersion(unsigned char  acData[],string &strErr);
    int ReadStatus(unsigned char  acData[],string &strErr);
    int OpenUp(unsigned char  acData[],string &strErr);
    int CloseDown(unsigned char  acData[],string &strErr);
    int ReadRawData(unsigned char  acData[],string &strErr);
    int ReadTransData(unsigned char  acData[],string &strErr);
    int EnableUartData(unsigned char  acData[],string &strErr);
    int DisableUartData(unsigned char  acData[],string &strErr);


};

#endif // UARTPS_H
