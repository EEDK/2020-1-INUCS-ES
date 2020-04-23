#include <stdio.h>
#include <stdlib.h>    // atoi 함수가 선언된 헤더 파일
#include <string.h>    // strchr 함수가 선언된 헤더 파일

#define LED1    21  // #101
#define LED2    22  // #10
#define LED3    23  // #108
#define LED4    24  // #97 
#define LED5    10  // CE0
#define LED6    11  // #118
#define LED7    26  // #99

// SubStr 구현함수 ( err check용 ) 
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


int main(int argc, char* argv[])      // 옵션의 개수와 옵션 문자열을 배열로 받음
{
    // 전달된 인자가 없을시 실시
    if (argc < 2) {
        printf("1개 이상의 인자를 넣어주세요.");
    }

    else {
        if (atoi(argv[1]) < 1 || atoi(argv[1]) > 2) {
            printf("시작 옵션으로는 1 혹은 2만 가능합니다.");
        }
        // 전달받은 인자가 1일시 실시 ./App 1
        else if (atoi(argv[1]) == 1) {
            if (argc == 2) {
                printf("App 1 Blink!");
            }
            else {
                printf("인자수에 오류가 있습니다.");
            }
        }
        // 전달받은 인자가 2일시 실시 ./App 0xXX
        else if (atoi(argv[1]) == 2) {
            if (argc == 3){ 
                printf("App 2 Blink!\n");
                if (strcmp(SubStr(argv[2], 0, 2), "0x") == 0) {
                    int number = (int)strtol(argv[2], NULL, 0);
                    printf("%d\n", number);
                }
                else {
                    printf("입력받은 수에 오류가 있습니다 16진법 표기로 0x를 붙혀주세요");
                }
            }
            else {
                printf("인자수에 오류가 있습니다.");
            }
        }
    }

    return 0;
}

