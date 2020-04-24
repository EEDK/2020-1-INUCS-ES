#include <stdio.h>
#include <stdlib.h>    
#include <time.h>  
#include <string.h>    
#include <wiringPi.h>

#define LED0    21  // #101
#define LED1    22  // #10
#define LED2    23  // #108
#define LED3    24  // #97 
#define LED4    10  // CE0
#define LED5    11  // #118
#define LED6    26  // #99


char* SubStr(char* pnInput, int nStart, int nLen) {
    int nLoop;
    int nLength;
    char* pszOutPut;

    if (pnInput == NULL) {
        return NULL;
    }

    pszOutPut = (char*)malloc(sizeof(char) * nLen + 1);

    nLength = strlen(pnInput);

    if (nLength > nStart + nLen) {
        nLength = nStart + nLen;
    }

    for (nLoop = nStart; nLoop < nLength; nLoop++) {
        pszOutPut[nLoop - nStart] = pnInput[nLoop];
    }

    pszOutPut[nLoop - nStart] = '\0';

    return pszOutPut;
}

void FuncApp(int i) {
    switch (i)
    {
    case 0 :
        digitalWrite(LED0, HIGH);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);
        digitalWrite(LED5, HIGH);
        delay(500);
        digitalWrite(LED0, LOW);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
        delay(500);

        break;
    case 1 :
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        delay(500);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        delay(500);

        break;
    case 2 :
        digitalWrite(LED0, HIGH);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED6, HIGH);
        digitalWrite(LED4, HIGH);
        digitalWrite(LED3, HIGH);
        delay(500);
        digitalWrite(LED0, LOW);
        digitalWrite(LED1, LOW);
        digitalWrite(LED6, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(LED3, LOW);
        delay(500);
        break;
    case 3 :
        digitalWrite(LED0, HIGH);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED6, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        delay(500);
        digitalWrite(LED0, LOW);
        digitalWrite(LED1, LOW);
        digitalWrite(LED6, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        delay(500);

    case 4 :
        digitalWrite(LED5, HIGH);
        digitalWrite(LED6, HIGH);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        delay(500);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, LOW);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        delay(500);
        break;
    case 5 :
        digitalWrite(LED0, HIGH);
        digitalWrite(LED5, HIGH);
        digitalWrite(LED6, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        delay(500);
        digitalWrite(LED0, LOW);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        delay(500);
        break;
    case 6 :
        digitalWrite(LED0, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);
        digitalWrite(LED5, HIGH);
        digitalWrite(LED6, HIGH);
        delay(500);
        digitalWrite(LED0, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, LOW);
        delay(500);
        break;
    case 7 :
        digitalWrite(LED0, HIGH);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        delay(500);
        digitalWrite(LED0, LOW);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        delay(500);
        break;
    case 8 : 
        digitalWrite(LED0, HIGH);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);
        digitalWrite(LED5, HIGH);
        digitalWrite(LED6, HIGH);
        delay(500);
        digitalWrite(LED0, LOW);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, LOW);
        delay(500);
        break;
    case 9 :
        digitalWrite(LED0, HIGH);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED5, HIGH);
        digitalWrite(LED6, HIGH);
        delay(500);
        digitalWrite(LED0, LOW);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, LOW);
        delay(500);
        break;
    case 10 :
        digitalWrite(LED0, HIGH);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);
        digitalWrite(LED6, HIGH);
        delay(500);
        digitalWrite(LED0, LOW);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(LED6, LOW);
        delay(500);
        break;
    case 11 :
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);
        digitalWrite(LED5, HIGH);
        digitalWrite(LED6, HIGH);
        delay(500);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, LOW);
        delay(500);
        break;
    case 12 :
        digitalWrite(LED0, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);
        digitalWrite(LED5, HIGH);
        delay(500);
        digitalWrite(LED0, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
        delay(500);
        break;
    case 13 :
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);
        digitalWrite(LED6, HIGH);
        delay(500);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(LED6, LOW);
        delay(500);
        break;
    case 14 :
        digitalWrite(LED0, HIGH);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);
        digitalWrite(LED5, HIGH);
        digitalWrite(LED6, HIGH);
        delay(500);
        digitalWrite(LED0, LOW);
        digitalWrite(LED1, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, LOW);
        delay(500);
        break;
    case 15 :
        digitalWrite(LED0, HIGH);
        digitalWrite(LED4, HIGH);
        digitalWrite(LED5, HIGH);
        digitalWrite(LED6, HIGH);
        delay(500);
        digitalWrite(LED0, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, LOW);
        delay(500);
        break;
    default:
        break;
    }
}


void SwitchEachNumber(int i) {
    switch (i)
    {
    case 0 :
        digitalWrite(LED0, HIGH);
        break;
    case 1 :
        digitalWrite(LED1, HIGH);
        break;
    case 2 :
        digitalWrite(LED2, HIGH);
        break;
    case 3 :
        digitalWrite(LED3, HIGH);
        break;
    case 4 : 
        digitalWrite(LED4, HIGH);
        break;
    case 5 :
        digitalWrite(LED5, HIGH);
        break;
    case 6 :
        digitalWrite(LED6, HIGH);
        break;
    default:
        break;
    }
}

void ShutDown() {
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
}

int main(int argc, char* argv[])      
{
    if (argc < 2) {
        printf("choice option 1 or 2.\n");
    }

    else {
        if (atoi(argv[1]) < 1 || atoi(argv[1]) > 2) {
            printf("choice option 1 or 2.\n");
        }
        else if (atoi(argv[1]) == 1) {
            if (argc == 2) {
                printf("App 1 Blink!\n");
                int num[16];    
                int j;
                int i;

                for (j = 0; j < 16; j++) {     
                    num[j] = j;
                }

                srand(time(NULL));    

                for (i = 0; i < 30; i++) {   

                    int randNum1 = rand() % 16;    
                    int randNum2 = rand() % 16;

                    int temp;
                    temp = num[randNum1];
                    num[randNum1] = num[randNum2];
                    num[randNum2] = temp;
                }

                wiringPiSetup();                      
                pinMode(LED0, OUTPUT);
                pinMode(LED1, OUTPUT);
                pinMode(LED2, OUTPUT);
                pinMode(LED3, OUTPUT);
                pinMode(LED4, OUTPUT);
                pinMode(LED5, OUTPUT);
                pinMode(LED6, OUTPUT);
                

                for (i = 0; i <= 15; i++) {
                    FuncApp(i);
                }
                for (i = 0; i <= 15; i++) {
                    FuncApp(num[i]);
                }
            }
            else {
                printf("arguemnt must Be 1 or 2.\n");
            }
        }
        else if (atoi(argv[1]) == 2) {
            if (argc == 3){ 
                printf("App 2 Blink!\n");
                if (strcmp(SubStr(argv[2], 0, 2), "0x") == 0) {
                    int number = (int)strtol(argv[2], NULL, 0);

                    if (number > 0x7f) {
                        printf("Input must be less than 0x7f\n");
                    }
                    else {
                        wiringPiSetup();
                        pinMode(LED0, OUTPUT);
                        pinMode(LED1, OUTPUT);
                        pinMode(LED2, OUTPUT);
                        pinMode(LED3, OUTPUT);
                        pinMode(LED4, OUTPUT);
                        pinMode(LED5, OUTPUT);
                        pinMode(LED6, OUTPUT);
                        int i;
                        for (i = 0; i < 8; i++) {
                            if (number % 2 != 0) {
                                SwitchEachNumber(i);
                            }
                            number >>= 1;
                        }
                        delay(5000);
                        ShutDown();
                    }
                }
                else {
                    printf("The first letter of the input value must start with 0x\n");
                }
            }
            else {
                printf("argment must be 2.\n");
            }
        }
    }

    return 0;
}

