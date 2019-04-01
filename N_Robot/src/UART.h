#ifndef UART_H
#define UART_H

int UART0_Open(char* port);
int UART0_Set(int fd,int speed,int flow_ctrl,int databits,int stopbits,int parity);
int UART0_Recv(int fd, char *rcv_buf,int data_len);
int UART0_Send(int fd, char *send_buf,int data_len);
void UART0_Close(int fd);

#endif // UART_H
