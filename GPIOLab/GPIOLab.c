#include <stdio.h>
#include <stdlib.h>    // atoi �Լ��� ����� ��� ����
#include <string.h>    // strchr �Լ��� ����� ��� ����

#define LED1    21  // #101
#define LED2    22  // #10
#define LED3    23  // #108
#define LED4    24  // #97 
#define LED5    10  // CE0
#define LED6    11  // #118
#define LED7    26  // #99

// SubStr �����Լ� ( err check�� ) 
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


int main(int argc, char* argv[])      // �ɼ��� ������ �ɼ� ���ڿ��� �迭�� ����
{
    // ���޵� ���ڰ� ������ �ǽ�
    if (argc < 2) {
        printf("1�� �̻��� ���ڸ� �־��ּ���.");
    }

    else {
        if (atoi(argv[1]) < 1 || atoi(argv[1]) > 2) {
            printf("���� �ɼ����δ� 1 Ȥ�� 2�� �����մϴ�.");
        }
        // ���޹��� ���ڰ� 1�Ͻ� �ǽ� ./App 1
        else if (atoi(argv[1]) == 1) {
            if (argc == 2) {
                printf("App 1 Blink!");
            }
            else {
                printf("���ڼ��� ������ �ֽ��ϴ�.");
            }
        }
        // ���޹��� ���ڰ� 2�Ͻ� �ǽ� ./App 0xXX
        else if (atoi(argv[1]) == 2) {
            if (argc == 3){ 
                printf("App 2 Blink!\n");
                if (strcmp(SubStr(argv[2], 0, 2), "0x") == 0) {
                    int number = (int)strtol(argv[2], NULL, 0);
                    printf("%d\n", number);
                }
                else {
                    printf("�Է¹��� ���� ������ �ֽ��ϴ� 16���� ǥ��� 0x�� �����ּ���");
                }
            }
            else {
                printf("���ڼ��� ������ �ֽ��ϴ�.");
            }
        }
    }

    return 0;
}

