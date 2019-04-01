#ifndef UARTOFPS1_H
#define UARTOFPS1_H
#include "UARTDev.h"
//#include <iostream>
#include <string>
  using namespace std;


class UartOFPS1:public UARTDev{
public:
    UartOFPS1();
    ~UartOFPS1();

    unsigned char bytDevType;
    unsigned char bytDevInfo;

    int ReadDevInfo(unsigned char  acData[],string & strErr);
    int Reboot(unsigned char  acData[],string &strErr);
    int ReadVersion(unsigned char  acData[],string &strErr);
    int ZeroOdometry(unsigned char  acData[],string &strErr);
    int StartCalc(unsigned char  acData[],string &strErr);
    int StopCalc(unsigned char  acData[],string &strErr);
    int ReadEncoder(unsigned char  acData[],string &strErr);
    int ReadPosition(unsigned char  acData[],string &strErr);
    int SetPosition(unsigned char  acData[],string &strErr);
};

#endif // UARTOFPS1_H
