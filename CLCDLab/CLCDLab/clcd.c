#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>

#define LCD_D4 2
#define LCD_D5 3
#define LCD_D6 1
#define LCD_D7 4
#define LCD_RS 7
#define LCD_EN 0

#define BT7 12
#define BT8 13
#define BT9 10 
#define BT4 14
#define BT5 11
#define BT6 26
#define BT1 21
#define BT2 22
#define BT3 27
#define BT0 23

#define EQL 24

#define PLUS 5
#define MINUS 6

void write4bits(unsigned char command)
{
    digitalWrite(LCD_D4, (command & 1));
    command >>= 1;
    digitalWrite(LCD_D5, (command & 1));
    command >>= 1;
    digitalWrite(LCD_D6, (command & 1));
    command >>= 1;
    digitalWrite(LCD_D7, (command & 1));
    digitalWrite(LCD_EN, 1);
    delayMicroseconds(10);
    digitalWrite(LCD_EN, 0);
    delayMicroseconds(10);
}

void sendDataCmd4(unsigned char data)
{
    write4bits(((data >> 4) & 0x0f));
    write4bits((data & 0x0f));
    delayMicroseconds(100);
}

void putCmd4(unsigned char cmd)
{
    digitalWrite(LCD_RS, 0);
    sendDataCmd4(cmd);
}

void putChar(char c) {

    digitalWrite(LCD_RS, 1);

    sendDataCmd4(c);
}

void initialize_textlcd() {	//CLCD 초기화
    pinMode(LCD_RS, OUTPUT); 
    pinMode(LCD_EN, OUTPUT);
    pinMode(LCD_D4, OUTPUT); 
    pinMode(LCD_D5, OUTPUT);
    pinMode(LCD_D6, OUTPUT); 
    pinMode(LCD_D7, OUTPUT);

    pinMode(BT7, INPUT);
    pinMode(BT8, INPUT);
    pinMode(BT9, INPUT);
    pinMode(BT4, INPUT);
    pinMode(BT5, INPUT);
    pinMode(BT6, INPUT);
    pinMode(BT1, INPUT);
    pinMode(BT2, INPUT);
    pinMode(BT3, INPUT);
    pinMode(BT0, INPUT);
    pinMode(EQL, INPUT);
    pinMode(PLUS, INPUT);
    pinMode(MINUS, INPUT);

    pullUpDnControl(BT7, PUD_DOWN);
    pullUpDnControl(BT8, PUD_DOWN);
    pullUpDnControl(BT9, PUD_DOWN);
    pullUpDnControl(BT4, PUD_DOWN);
    pullUpDnControl(BT5, PUD_DOWN);
    pullUpDnControl(BT6, PUD_DOWN);
    pullUpDnControl(BT1, PUD_DOWN);
    pullUpDnControl(BT2, PUD_DOWN);
    pullUpDnControl(BT3, PUD_DOWN);
    pullUpDnControl(BT0, PUD_DOWN);
    pullUpDnControl(EQL, PUD_DOWN);
    pullUpDnControl(PLUS, PUD_UP);
    pullUpDnControl(MINUS, PUD_UP);

    digitalWrite(LCD_RS, 0); 
    digitalWrite(LCD_EN, 0);
    digitalWrite(LCD_D4, 0); 
    digitalWrite(LCD_D5, 0);
    digitalWrite(LCD_D6, 0); 
    digitalWrite(LCD_D7, 0);
    delay(35);

    putCmd4(0x28);  // 4비트 2줄
    putCmd4(0x28); putCmd4(0x28);
    putCmd4(0x0e); // 디스플레이온 커서 온 
    putCmd4(0x02); // 커서 홈 
    delay(2);
    putCmd4(0x01); // 표시 클리어 
    delay(2);
}

char calc[100] = "";

void append(char* dst, char c) {
    char* p = dst;
    while (*p != '\0') p++;
    *p = c;
    *(p + 1) = '\0';
}

void WhichBtn() {
    if (digitalRead(BT0) == 1) {
        append(calc, '0');
    }
    else if (digitalRead(BT1) == 1) {
        append(calc, '1');
    }
    else if (digitalRead(BT2) == 1) {
        append(calc, '2');
    }
    else if (digitalRead(BT3) == 1) {
        append(calc, '3');
    }
    else if (digitalRead(BT4) == 1) {
        append(calc, '4');
    }
    else if (digitalRead(BT5) == 1) {
        append(calc, '5');
    }
    else if (digitalRead(BT6) == 1) {
        append(calc, '6');
    }
    else if (digitalRead(BT7) == 1) {
        append(calc, '7');
    }
    else if (digitalRead(BT8) == 1) {
        append(calc, '8');
    }
    else if (digitalRead(BT9) == 1) {
        append(calc, '9');
    }
    else if (!digitalRead(PLUS) == 1) {
        append(calc, '+');
    }
    else if (!digitalRead(MINUS) == 1) {
        append(calc, '-');
    }
}


int main(int argc, char** argv) {

    int i , len , state; 

    wiringPiSetup();

    initialize_textlcd();
    state = 0;
    /*printf("BT7 IS %d\n", digitalRead(BT7));
    printf("BT8 IS %d\n", digitalRead(BT8));
    printf("BT9 IS %d\n", digitalRead(BT9));
    printf("BT4 IS %d\n", digitalRead(BT4));
    printf("BT5 IS %d\n", digitalRead(BT5));
    printf("BT6 IS %d\n", digitalRead(BT6));
    printf("BT1 IS %d\n", digitalRead(BT1));
    printf("BT2 IS %d\n", digitalRead(BT2));
    printf("BT3 IS %d\n", digitalRead(BT3));
    printf("BT0 IS %d\n", digitalRead(BT0));
    printf("EQL IS %d\n", digitalRead(EQL));

    printf("PLUS IS %d\n", digitalRead(PLUS));
    printf("MINUS IS %d\n", digitalRead(MINUS));*/
    for (;;) {
        if (digitalRead(BT0) ||
            digitalRead(BT1) ||
            digitalRead(BT2) ||
            digitalRead(BT3) ||
            digitalRead(BT4) ||
            digitalRead(BT5) ||
            digitalRead(BT6) ||
            digitalRead(BT7) ||
            digitalRead(BT8) ||
            digitalRead(BT9) ||
            !digitalRead(PLUS) ||
            !digitalRead(MINUS)) {
            if (state == 0) {
                WhichBtn();
                delay(10);
                state = 1;

                len = strlen(calc);
                printf("%c\n", calc[len - 1]);
                //for (i = 0; i < len; i++) putChar(calc[i]);
                putChar(calc[len - 1]);
            }
        }
        else if (digitalRead(BT0) == 0 &&
            digitalRead(BT1) == 0 &&
            digitalRead(BT2) == 0 &&
            digitalRead(BT3) == 0 &&
            digitalRead(BT4) == 0 &&
            digitalRead(BT5) == 0 &&
            digitalRead(BT6) == 0 &&
            digitalRead(BT7) == 0 &&
            digitalRead(BT8) == 0 &&
            digitalRead(BT9) == 0 &&
            !digitalRead(PLUS) == 0 &&
            !digitalRead(MINUS) == 0) {
            if (state == 1) {
                delay(10);
                state = 0;
            }
        }
        if (digitalRead(EQL)) {
            break;
        }

    }
    printf("%s\n", calc);
}
