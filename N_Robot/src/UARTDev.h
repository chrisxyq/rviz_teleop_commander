#ifndef UARTDev_H
#define UARTDev_H

#define RCVBUF_LEN 20000

class UARTDev{
public:
    UARTDev();
    ~UARTDev();
    int InitPort();
    int ClearRcvBuf();
    int ClosePort();
    //
    char * pcPortName;
    int nUartSpeed;
    int nUartFlowCtrl;
    int nUartDatabits;
    int nUartStopbits;
    int nParity;

    int fd;                            //文件描述符
    int err;                           //返回调用函数的状态
    char acUartRcvBuf[RCVBUF_LEN];
};

#endif // UARTDev_H
