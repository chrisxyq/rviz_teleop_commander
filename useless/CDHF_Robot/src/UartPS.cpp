#include "UartPS.h"
#include "Project.h"
#include "stdio.h"
#include "UART.h"
#include <unistd.h> //sleep()
#include "Algorithm.h"

UartPS::UartPS()
{
    printf("creatting UartPS\n");

    bytDevType=0x10;
    bytDevInfo=0x10;
}
int UartPS::StartTrans(unsigned char  acData[],string &strErr){
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
    acSendBuf[1]=0x01;
    acSendBuf[2]=0x01;
    acSendBuf[3]=0x28;
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
int UartPS::ReadDevInfo(unsigned char  acData[],string &strErr){
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
#ifdef PROJ_DEBUG
        printf("receive data length:%d.The effective data: ",nLen);
#endif
        nBufStartIndex=nLen-nRcvLenEx>0?nLen-nRcvLenEx:0;
        while( (acUartRcvBuf[nBufStartIndex]&0xff)!=0xAA && nRcvLen==0){
            if(++nBufStartIndex>nLen-1) break;
        }
        int j;
        for(j=nBufStartIndex;(j<nLen)&&(nRcvLen<nRcvLenEx);j++){
            acRcvBuf[nRcvLen++]=acUartRcvBuf[j];
#ifdef PROJ_DEBUG
            printf("%02hhx ",acUartRcvBuf[j]);
#endif
        }
#ifdef PROJ_DEBUG
        printf(".effective data length:%d\n",j-nBufStartIndex);
#endif
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
int UartPS::ReadVersion(unsigned char  acData[],string &strErr){
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
int UartPS::Reboot(unsigned char  acData[],string &strErr){
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
int UartPS::ReadStatus(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=8;
    const int nRcvLenEx=16;
    char acSendBuf[8];
    char acRcvBuf[16];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x28;
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
int UartPS::OpenUp(unsigned char  acData[],string &strErr){
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
    acSendBuf[3]=0x29;
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
int UartPS::CloseDown(unsigned char  acData[],string &strErr){
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
    acSendBuf[3]=0x2A;
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
int UartPS::ReadRawData(unsigned char  acData[],string &strErr){
    strErr="";
    int nLen;
    int nSendLen;
    int nRcvLen;
    const int nSendLenEx=8;
    const int nRcvLenEx=16;
    char acSendBuf[8];
    char acRcvBuf[16];
    unsigned short wCRC;
    unsigned int nBufStartIndex;
    //
    acSendBuf[0]=0xAA;
    acSendBuf[1]=bytDevType;
    acSendBuf[2]=bytDevInfo;
    acSendBuf[3]=0x2B;
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
int UartPS::ReadTransData(unsigned char  acData[],string &strErr){
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
    acSendBuf[3]=0x2C;
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

int UartPS::EnableUartData(unsigned char  acData[],string &strErr){
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
    acSendBuf[3]=0x2D;
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
int UartPS::DisableUartData(unsigned char  acData[],string &strErr){
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
