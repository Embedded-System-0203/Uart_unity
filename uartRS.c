#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringSerial.h>

#define _CRT_SECURE_NO_WARNINGS
#define BAUD_RATE 115200
static const char* UART2_DEV = "/dev/ttyAMA1"; //UART2 연결을 위한 장치 파일
unsigned char serialRead(const int fd); //1Byte 데이터를 수신하는 함수
void serialWrite(const int fd, const unsigned char *c); //1Byte 데이터를 송신하는 함수

//1Byte 데이터를 수신하는 함수
unsigned char serialRead(const int fd)
{
    unsigned char x;
    if(read (fd, &x, 1) != 1) //read 함수를 통해 1바이트 읽어옴
        return -1;
    return x; //읽어온 데이터 반환
}

void serialWrite(const int fd, const unsigned char *c)
{
    write (fd, c, strlen(c));
}

int main ()     
{
    int fd_serial ; //UART2 파일 서술자
    unsigned char dat[100]; //데이터 임시 저장 변수
    unsigned char dat2;
    if (wiringPiSetup () < 0) return 1;
    if ((fd_serial = serialOpen (UART2_DEV, BAUD_RATE)) < 0){ //UART2 포트 오픈
        printf ("Unable to open serial device.\n");
        return 1;
    }
    int cnt = 0;
    int opt = 1;
    printf("1 : 받은 데이터를 출력하기\n");
    printf("2 : 데이터를 입력해 유니티로 데이터를 보내기\n");
    printf("옵션 입력 : ");
    scanf("%d", &opt);
    printf("%d번 기능이 동작\n", opt);
    while(1)
    {
        if (serialDataAvail(fd_serial) && opt == 1)
        {
            printf("읽을 데이터가 존재\n");
            dat2 = serialRead(fd_serial);
            printf("읽기 완료\n");
            printf("받은 데이터 : %c\n", dat2);
            fflush(stdout);
        }
        else if (opt == 2)
        {
            printf("입력 : ");
            scanf("%s", &dat);
            printf("보낸 문자 : %s\n", dat);
            serialWrite(fd_serial, dat);
        }
        // if (opt == 1)
        // {
        //     printf("나 있지");
        //     if (serialDataAvail(fd_serial))
        //     {
        //         printf("1");
        //         //sprintf(dat, "%s\n", serialRead(fd_serial));
        //         dat2 = serialRead(fd_serial);
        //         if (dat2 == '\0')
        //             continue;
        //         printf("받은 데이터 : %c\n", dat2);
        //         fflush(stdout);
        //         printf("입력 : ");
        //         scanf("%c", &dat);
        //         serialWrite(fd_serial, dat);
        //         printf("보낸 데이터 : %s\n", dat);
        //     }
        // }
        // else if (opt == 2)
        // {
        //     printf("입력 : ");
        //     scanf("%s", &dat);
        //     printf("보낸 문자 : %s\n", dat);
        //     serialWrite(fd_serial, dat);
        // }
        delay (1000);
    }
}