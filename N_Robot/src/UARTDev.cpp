#include "stdio.h"
#include "UART.h"
#include "UARTDev.h"
//#include <unistd.h> //sleep()
//#include "Algorithm.h"
//宏定义
//#define NULL 0
//
UARTDev::UARTDev(){
#ifdef PROJ_DEBUG
    printf("creatting UARTDev\n");
#endif
    //
    pcPortName=NULL;
    nUartSpeed=38400;
    nUartFlowCtrl=0;
    nUartDatabits=8;
    nUartStopbits=1;
    nParity='N';
    //
    fd=NULL;
    err=0;
}
UARTDev::~UARTDev(){
    //**close serial port
    ClosePort();
    printf("\nclosed %s.\n",pcPortName);
    //**
#ifdef PROJ_DEBUG
    printf("deleting UARTDev\n");
#endif
    //printf("UartInfo:%x%s\n",pcPortName,pcPortName);
    //if(pcPortName) delete[] pcPortName;
}
int UARTDev::InitPort(){
    fd = UART0_Open(pcPortName); //打开串口，返回文件描述符
    printf("uart fd=%d\n",fd);
    if(fd>=0){
        err = UART0_Set(fd,nUartSpeed,nUartFlowCtrl,nUartDatabits,nUartStopbits,nParity);
        if(err==0){
            printf("Set Port Exactly!\n");
        }
    }else{
        err=1;
    }
    //
    return err;
}

int UARTDev::ClearRcvBuf(){
    printf("clear uart rcv buffer:");
    printf("%d\n",UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN));

    return 0;
}

int UARTDev::ClosePort(){
    if(fd){
        UART0_Close(fd);
    }
    //
    return 0;
}
