#include <stdio.h>
#include <stdlib.h>    // atoi �Լ��� ����� ��� ����

int main(int argc, char* argv[])      // �ɼ��� ������ �ɼ� ���ڿ��� �迭�� ����
{
    if (argc < 2) {
        printf("more than 1 arg plz");
    }
    else {
        if (atoi(argv[1]) < 1 || atoi(argv[1]) > 2) {
            printf("Only 1 and 2 are available for options");
        }
        // ���޹��� ���ڰ� 1�Ͻ� �ǽõ� �Լ� ./App 1
        else if (atoi(argv[1]) == 1) {
            printf("�ȳ�!");
        }
        else if (atoi(argv[1]) == 2) {
            printf("�ι�° �ȳ�!");
        }
    }



    return 0;
}