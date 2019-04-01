#ifndef UARTPBUTTING_H
#define UARTPBUTTING_H
#include "UARTDev.h"
//#include <iostream>
#include <string>
  using namespace std;

//宏定义
#define WAIT_RES_TIME 0.01
class UartPBUTTING:public UARTDev
{
public:
    UartPBUTTING();

    unsigned char bytDevType;
    unsigned char bytDevInfo;

    int ReadDevInfo(unsigned char  acData[],string & strErr);
    int Reboot(unsigned char  acData[],string &strErr);
    int ReadVersion(unsigned char  acData[],string &strErr);
    int ReadStatus(unsigned char  acData[],string &strErr);


};

#endif // UARTPBUTTING_H
