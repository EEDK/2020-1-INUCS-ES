#include <stdio.h>
#include <stdlib.h>    // atoi 함수가 선언된 헤더 파일

int main(int argc, char* argv[])      // 옵션의 개수와 옵션 문자열을 배열로 받음
{
    if (argc < 2) {
        printf("more than 1 arg plz");
    }
    else {
        if (atoi(argv[1]) < 1 || atoi(argv[1]) > 2) {
            printf("Only 1 and 2 are available for options");
        }
        // 전달받은 인자가 1일시 실시될 함수 ./App 1
        else if (atoi(argv[1]) == 1) {
            printf("안녕!");
        }
        else if (atoi(argv[1]) == 2) {
            printf("두번째 안녕!");
        }
    }



    return 0;
}