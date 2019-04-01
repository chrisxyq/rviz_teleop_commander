#include "stdio.h"
#include "UART.h"
#include "UartNMotion.h"
#include <unistd.h> //sleep()
#include "Algorithm.h"

//宏定义
#define WAIT_RES_TIME 0.01

//
UartNMotion::UartNMotion(){
    printf("creatting UartNMotion\n");

    bytDevType=0x20;
    bytDevInfo=0x20;
}
UartNMotion::~UartNMotion(){
}

int UartNMotion::ReadDevInfo(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=8;
    const int nRcvLenEx=12;
    char acSendBuf[8];
    char acRcvBuf[12];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=0xFF;
    acSendBuf[2]=0xFF;
    acSendBuf[3]=0x16;
    acSendBuf[4]=0x00;
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[5]=(char)(wCRC&0x00ff);
    acSendBuf[6]=(char)(wCRC>>8);
    acSendBuf[7]=0x0D;
    //clear buff
    //ClearRcvBuf();
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    bytDevType=acRcvBuf[1];
    bytDevInfo=acRcvBuf[2];
    acData[0]=acRcvBuf[1];
    acData[1]=acRcvBuf[2];
    for(int i=0;i<4;i++){
        acData[2+i]=acRcvBuf[5+i];
    }
    //
    return 0;
}
int UartNMotion::ReadVersion(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=8;
    const int nRcvLenEx=14;
    char acSendBuf[8];
    char acRcvBuf[14];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x15;
    acSendBuf[4]=0x00;
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[5]=(char)(wCRC&0x00ff);
    acSendBuf[6]=(char)(wCRC>>8);
    acSendBuf[7]=0x0D;
    //clear buff
    //ClearRcvBuf();
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    for(int i=0;i<nRcvLenEx-8;i++){
        acData[i]=acRcvBuf[5+i];
    }
    //
    return 0;
}
int UartNMotion::Reboot(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=8;
    const int nRcvLenEx=8;
    char acSendBuf[8];
    char acRcvBuf[8];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x19;
    acSendBuf[4]=0x00;
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[5]=(char)(wCRC&0x00ff);
    acSendBuf[6]=(char)(wCRC>>8);
    acSendBuf[7]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    acData[0]=acRcvBuf[3];
    //
    return 0;
}
int UartNMotion::ReadMotionStatus(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=8;
    const int nRcvLenEx=15;
    char acSendBuf[8];
    char acRcvBuf[15];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x2A;
    acSendBuf[4]=0x00;
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[5]=(char)(wCRC&0x00ff);
    acSendBuf[6]=(char)(wCRC>>8);
    acSendBuf[7]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    for(int i=0;i<7;i++){
        acData[i]=acRcvBuf[5+i];
    }
    //
    return 0;
}
int UartNMotion::ResetAllMotorDriver(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=8;
    const int nRcvLenEx=8;
    char acSendBuf[8];
    char acRcvBuf[8];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x2B;
    acSendBuf[4]=0x00;
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[5]=(char)(wCRC&0x00ff);
    acSendBuf[6]=(char)(wCRC>>8);
    acSendBuf[7]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    acData[0]=acRcvBuf[3];
    //
    return 0;
}

int UartNMotion::ClearMotionBuff(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=8;
    const int nRcvLenEx=8;
    char acSendBuf[8];
    char acRcvBuf[8];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x2C;
    acSendBuf[4]=0x00;
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[5]=(char)(wCRC&0x00ff);
    acSendBuf[6]=(char)(wCRC>>8);
    acSendBuf[7]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    acData[0]=acRcvBuf[3];
    //
    return 0;
}

int UartNMotion::ClearErrFlag(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=8;
    const int nRcvLenEx=8;
    char acSendBuf[8];
    char acRcvBuf[8];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x2D;
    acSendBuf[4]=0x00;
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[5]=(char)(wCRC&0x00ff);
    acSendBuf[6]=(char)(wCRC>>8);
    acSendBuf[7]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    acData[0]=acRcvBuf[3];
    //
    return 0;
}

int UartNMotion::StartMotion(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=8;
    const int nRcvLenEx=9;
    char acSendBuf[8];
    char acRcvBuf[9];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x2E;
    acSendBuf[4]=0x00;
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[5]=(char)(wCRC&0x00ff);
    acSendBuf[6]=(char)(wCRC>>8);
    acSendBuf[7]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    acData[0]=acRcvBuf[5];
    //
    return 0;
}
int UartNMotion::SuspendMotion(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=8;
    const int nRcvLenEx=9;
    char acSendBuf[8];
    char acRcvBuf[9];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x2F;
    acSendBuf[4]=0x00;
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[5]=(char)(wCRC&0x00ff);
    acSendBuf[6]=(char)(wCRC>>8);
    acSendBuf[7]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    acData[0]=acRcvBuf[5];
    //
    return 0;
}
int UartNMotion::ContinueMotion(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=8;
    const int nRcvLenEx=9;
    char acSendBuf[8];
    char acRcvBuf[9];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x30;
    acSendBuf[4]=0x00;
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[5]=(char)(wCRC&0x00ff);
    acSendBuf[6]=(char)(wCRC>>8);
    acSendBuf[7]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    acData[0]=acRcvBuf[5];
    //
    return 0;
}

int UartNMotion::StopMotion(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=8;
    const int nRcvLenEx=10;
    char acSendBuf[8];
    char acRcvBuf[10];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x31;
    acSendBuf[4]=0x00;
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[5]=(char)(wCRC&0x00ff);
    acSendBuf[6]=(char)(wCRC>>8);
    acSendBuf[7]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    acData[0]=acRcvBuf[5];
    acData[1]=acRcvBuf[6];
    //
    return 0;
}
int UartNMotion::JumpToNextCmd(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=8;
    const int nRcvLenEx=10;
    char acSendBuf[8];
    char acRcvBuf[10];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x32;
    acSendBuf[4]=0x00;
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[5]=(char)(wCRC&0x00ff);
    acSendBuf[6]=(char)(wCRC>>8);
    acSendBuf[7]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    acData[0]=acRcvBuf[5];
    acData[1]=acRcvBuf[6];
    //
    return 0;
}
int UartNMotion::StopMotionAndSetDir(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=12;
    const int nRcvLenEx=9;
    char acSendBuf[12];
    char acRcvBuf[9];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x33;
    acSendBuf[4]=nSendLenEx-8;
    for(int i=0;i<nSendLenEx-8;i++){
        acSendBuf[5+i]=acData[i];
    }
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[nSendLenEx-3]=(char)(wCRC&0x00ff);
    acSendBuf[nSendLenEx-2]=(char)(wCRC>>8);
    acSendBuf[nSendLenEx-1]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    for(int i=0;i<nRcvLenEx-8;i++){
        acData[i]=acRcvBuf[5+i];
    }
    //
    return 0;
}
int UartNMotion::SetDirAfterMotion(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=12;
    const int nRcvLenEx=9;
    char acSendBuf[12];
    char acRcvBuf[9];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x34;
    acSendBuf[4]=nSendLenEx-8;
    for(int i=0;i<nSendLenEx-8;i++){
        acSendBuf[5+i]=acData[i];
    }
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[nSendLenEx-3]=(char)(wCRC&0x00ff);
    acSendBuf[nSendLenEx-2]=(char)(wCRC>>8);
    acSendBuf[nSendLenEx-1]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    for(int i=0;i<nRcvLenEx-8;i++){
        acData[i]=acRcvBuf[5+i];
    }
    //
    return 0;
}
int UartNMotion::WaitTime(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=10;
    const int nRcvLenEx=9;
    char acSendBuf[10];
    char acRcvBuf[9];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x35;
    acSendBuf[4]=nSendLenEx-8;
    for(int i=0;i<nSendLenEx-8;i++){
        acSendBuf[5+i]=acData[i];
    }
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[nSendLenEx-3]=(char)(wCRC&0x00ff);
    acSendBuf[nSendLenEx-2]=(char)(wCRC>>8);
    acSendBuf[nSendLenEx-1]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    for(int i=0;i<nRcvLenEx-8;i++){
        acData[i]=acRcvBuf[5+i];
    }
    //
    return 0;
}
int UartNMotion::SetInstantVelocity(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=14;
    const int nRcvLenEx=9;
    char acSendBuf[14];
    char acRcvBuf[9];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x36;
    acSendBuf[4]=0x06;
    for(int i=0;i<6;i++){
        acSendBuf[5+i]=acData[i];
    }
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[11]=(char)(wCRC&0x00ff);
    acSendBuf[12]=(char)(wCRC>>8);
    acSendBuf[13]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    acData[0]=acRcvBuf[5];
    //
    return 0;
}
int UartNMotion::SMATSpeedMode(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=14;
    const int nRcvLenEx=9;
    char acSendBuf[14];
    char acRcvBuf[9];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x37;
    acSendBuf[4]=0x06;
    for(int i=0;i<6;i++){
        acSendBuf[5+i]=acData[i];
    }
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[11]=(char)(wCRC&0x00ff);
    acSendBuf[12]=(char)(wCRC>>8);
    acSendBuf[13]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    acData[0]=acRcvBuf[5];
    //
    return 0;
}
int UartNMotion::CMATSpeedMode(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=16;
    const int nRcvLenEx=9;
    char acSendBuf[16];
    char acRcvBuf[9];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x38;
    acSendBuf[4]=nSendLenEx-8;
    for(int i=0;i<nSendLenEx-8;i++){
        acSendBuf[5+i]=acData[i];
    }
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[nSendLenEx-3]=(char)(wCRC&0x00ff);
    acSendBuf[nSendLenEx-2]=(char)(wCRC>>8);
    acSendBuf[nSendLenEx-1]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    for(int i=0;i<nRcvLenEx-8;i++){
        acData[i]=acRcvBuf[5+i];
    }
    //
    return 0;
}
int UartNMotion::CAATSpeedMode(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=16;
    const int nRcvLenEx=9;
    char acSendBuf[16];
    char acRcvBuf[9];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x39;
    acSendBuf[4]=nSendLenEx-8;
    for(int i=0;i<nSendLenEx-8;i++){
        acSendBuf[5+i]=acData[i];
    }
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[nSendLenEx-3]=(char)(wCRC&0x00ff);
    acSendBuf[nSendLenEx-2]=(char)(wCRC>>8);
    acSendBuf[nSendLenEx-1]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    for(int i=0;i<nRcvLenEx-8;i++){
        acData[i]=acRcvBuf[5+i];
    }
    //
    return 0;
}
int UartNMotion::DefineMotorSpeed(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=16;
    const int nRcvLenEx=9;
    char acSendBuf[16];
    char acRcvBuf[9];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x3A;
    acSendBuf[4]=0x08;
    for(int i=0;i<8;i++){
        acSendBuf[5+i]=acData[i];
    }
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[13]=(char)(wCRC&0x00ff);
    acSendBuf[14]=(char)(wCRC>>8);
    acSendBuf[15]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    acData[0]=acRcvBuf[5];
    //
    return 0;
}
int UartNMotion::SMATPositionMode(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=16;
    const int nRcvLenEx=9;
    char acSendBuf[16];
    char acRcvBuf[9];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x3C;
    acSendBuf[4]=nSendLenEx-8;
    for(int i=0;i<8;i++){
        acSendBuf[5+i]=acData[i];
    }
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[nSendLenEx-3]=(char)(wCRC&0x00ff);
    acSendBuf[nSendLenEx-2]=(char)(wCRC>>8);
    acSendBuf[nSendLenEx-1]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    for(int i=0;i<nRcvLenEx-8;i++){
        acData[i]=acRcvBuf[5+i];
    }
    //
    return 0;
}
int UartNMotion::STATPositionMode(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=16;
    const int nRcvLenEx=9;
    char acSendBuf[16];
    char acRcvBuf[9];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x3D;
    acSendBuf[4]=nSendLenEx-8;
    for(int i=0;i<8;i++){
        acSendBuf[5+i]=acData[i];
    }
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[nSendLenEx-3]=(char)(wCRC&0x00ff);
    acSendBuf[nSendLenEx-2]=(char)(wCRC>>8);
    acSendBuf[nSendLenEx-1]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    for(int i=0;i<nRcvLenEx-8;i++){
        acData[i]=acRcvBuf[5+i];
    }
    //
    return 0;
}
int UartNMotion::CMATPositionMode(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=18;
    const int nRcvLenEx=9;
    char acSendBuf[18];
    char acRcvBuf[9];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x3E;
    acSendBuf[4]=nSendLenEx-8;
    for(int i=0;i<8;i++){
        acSendBuf[5+i]=acData[i];
    }
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[nSendLenEx-3]=(char)(wCRC&0x00ff);
    acSendBuf[nSendLenEx-2]=(char)(wCRC>>8);
    acSendBuf[nSendLenEx-1]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    for(int i=0;i<nRcvLenEx-8;i++){
        acData[i]=acRcvBuf[5+i];
    }
    //
    return 0;
}
int UartNMotion::CAATPositionMode(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=18;
    const int nRcvLenEx=9;
    char acSendBuf[18];
    char acRcvBuf[9];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x3F;
    acSendBuf[4]=nSendLenEx-8;
    for(int i=0;i<8;i++){
        acSendBuf[5+i]=acData[i];
    }
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[nSendLenEx-3]=(char)(wCRC&0x00ff);
    acSendBuf[nSendLenEx-2]=(char)(wCRC>>8);
    acSendBuf[nSendLenEx-1]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        printf("send data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    for(int i=0;i<nRcvLenEx-8;i++){
        acData[i]=acRcvBuf[5+i];
    }
    //
    return 0;
}
int UartNMotion::JoyCmdMotion(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=14;
    const int nRcvLenEx=9;
    char acSendBuf[14];
    char acRcvBuf[9];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x42;
    acSendBuf[4]=0x06;
    for(int i=0;i<6;i++){
        acSendBuf[5+i]=acData[i];
    }
    wCRC=do_crc_MSB((unsigned char *)acSendBuf, nSendLenEx-3);//CRC verify
    acSendBuf[11]=(char)(wCRC&0x00ff);
    acSendBuf[12]=(char)(wCRC>>8);
    acSendBuf[13]=0x0D;
    //send data
    nSendLen = UART0_Send(fd,acSendBuf,nSendLenEx);
    if(nSendLen ==nSendLenEx){
        for(int i=0;i<nSendLen;i++){
            printf("%02hhx ",acSendBuf[i]);
        }
        printf("\nsend data success:%d\n",nSendLen);
    }else{
        strErr="send data fail!";
        return 1;
    }
    //receive data
    nRcvLen=0;
    for(int i=0;i<40;i++){
        usleep(1000000*WAIT_RES_TIME);
        nLen = UART0_Recv(fd, acUartRcvBuf,RCVBUF_LEN);
        if(nLen<=0) continue;
        printf("receive data length:%d.The effective data: ",nLen);
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
            printf("%02hhx ",acUartRcvBuf[j]);
        }
        printf(".effective data length:%d\n",j-nBufStartIndex);
        if(nRcvLen>=nRcvLenEx && acRcvBuf[nRcvLen-1]==0x0D) break;
    }
    if(nRcvLen<nRcvLenEx){
        printf("receive data less than expected:%d<%d\n",nRcvLen,nRcvLenEx);
        strErr="receive data fail!";
        return 2;
    }else{
        printf("receive data success:%d\n",nRcvLen);
    }
    //check crc
    wCRC=do_crc_MSB((unsigned char *)acRcvBuf, nRcvLenEx-3);//CRC verify
    if(acRcvBuf[nRcvLenEx-3]!=(char)(wCRC&0x00ff)||acRcvBuf[nRcvLenEx-2]!=(char)(wCRC>>8)){
        strErr="crc check failed!";
        return 3;
    }
    //
    acData[0]=acRcvBuf[5];
    //
    return 0;
}
