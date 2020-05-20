#include <stdio.h>
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


    digitalWrite(LCD_RS, 0);
    digitalWrite(LCD_EN, 0);
    digitalWrite(LCD_D4, 0);
    digitalWrite(LCD_D5, 0);
    digitalWrite(LCD_D6, 0);
    digitalWrite(LCD_D7, 0);
    delay(35);


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

int atoi(char* cdata) {
    int sign = 1, data = 0;

    if (*cdata == '\n')
        return 0;

    if (*cdata == '-')
        sign = -1;

    while (*cdata)
    {
        if (*cdata >= '0' && *cdata <= '9')
        {
            data = data * 10 + *cdata - '0';
        }
        cdata++;
    }

    return data * sign;
}


void itoa(int num, char* str) {
    int i = 0;
    int radix = 10;  // 진수
    int deg = 1;
    int cnt = 0;

    if (num < 0) {
        *str = '-';
        str++;
        num *= -1;
    }

    while (1) {    // 자리수의 수를 뽑는다
        if ((num / deg) > 0)
            cnt++;
        else
            break;
        deg *= radix;
    }
    deg /= radix;    // deg가 기존 자리수보다 한자리 높게 카운트 되어서 한번 나누어줌 
    // EX) 1241 ->    cnt = 4; deg = 1000;
    for (i = 0; i < cnt; i++) {    // 자리수만큼 순회
        *(str + i) = num / deg + '0';    // 가장 큰 자리수의 수부터 뽑음
        num -= ((num / deg) * deg);        // 뽑은 자리수의 수를 없엠
        deg /= radix;    // 자리수 줄임
    }
    *(str + i) = '\0';  // 문자열끝널..
}

void printCLCD(char str[]) {
    initialize_textlcd();

    int i, len;
    len = strlen(str);

    if (len >= 32) {
        printCLCD("OVERFLOW");  //OVERFLOW 에러처리
        delay(2000);
        putCmd4(0x01); // 표시 클리어
    }

    else {
        for (i = 0; i < len; i++) {
            if (i == 16) {
                putCmd4(0xC0);
            }
            putChar(str[i]);
        }
    }
}


void WhichBtn() {
    int len;
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
        len = strlen(calc);
        if (calc[len - 1] == '+' || calc[len - 1] == '-') {
            printCLCD("Invalid operation");  //Invalid operation 에러처리
            delay(2000);
            putCmd4(0x01); // 표시 클리어
        }
        else {
            if (len != 0) {
                append(calc, '+');
            }
        }
    }
    else if (!digitalRead(MINUS) == 1) {
        if (calc[len - 1] == '+' || calc[len - 1] == '-') {
            printCLCD("Invalid operation");  //Invalid operation 에러처리
            delay(2000);
            putCmd4(0x01); // 표시 클리어
        }
        else {
            append(calc, '-');
        }
    }
}


void calcCulator(char* dst) {

    int sum, i, len, param1, flag;

    char* c = dst;

    char s1[50] = "";
    char sumStr[50];

    len = strlen(c);

    sum = 0;
    flag = 0;       // 처음 항인가?

    for (i = 0; i < len; i++) {
        if (i == 0 && c[i] == '-') {
            append(s1, c[i]);
        }

        else if (i != 0 && (c[i] == '+' || c[i] == '-')) {
            if (flag == 0) {
                sum = atoi(s1);
                flag = 1;
            }
            else if (flag == 1) {
                sum += atoi(s1);
            }

            s1[0] = '\0';
            if (c[i] == '-') {
                append(s1, c[i]);
            }
        }

        else if (i == len - 1) {
            append(s1, c[i]);
            sum += atoi(s1);
        }

        else {
            append(s1, c[i]);
        }
    }


    while (*c != '\0') c++;

    *c = '=';
    c += 1;

    itoa(sum, sumStr);
    len = strlen(sumStr);

    for (i = 0; i < len; i++) {
        *c = sumStr[i];
        c += 1;
    }
    *(c + 1) = '\0';

    printf("%s\n", c);
}

int main(int argc, char** argv) {
    int i, len, state;

    wiringPiSetup();

    initialize_textlcd();
    state = 0;

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
                len = strlen(calc);
                if (len == 16) {
                    putCmd4(0xC0);
                }
                else if (len >= 32) {
                    printCLCD("OVERFLOW");          //OVERFLOW 에러처리
                    delay(2000);
                    putCmd4(0x01); // 표시 클리어
                }
                WhichBtn();
                delay(10);
                state = 1;

                printCLCD(calc);
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
    calcCulator(calc);

    printCLCD(calc);
}
