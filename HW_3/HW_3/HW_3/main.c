// 작성자 : 20194059 김태완
// 작성일 : 2020.11.29
// 프로그램명 : 다양한 정렬 방법들의 실행 시간을 비교하는 프로그램

// 삽입정렬-
// 선택정렬-
// 버블정렬-
// 쉘정렬-
// 퀵정렬
// 히프정렬
// 합병정렬

#define _CRT_SECURE_NO_WARININGS
#include <stdio.h>
#include <stdlib.h>

#include "sort_methods.h"

void error(char *str);

int main()
{
    FILE *fp;
    char tmp[100];
    
    fp = fopen("data.txt","r");
    
    if(fp==NULL) {
        error("file open error");
    }
    
    while(!feof(fp)) {
        fscanf(fp, "%s", tmp);
        printf("%s ",tmp);
    }
    
    
}

// 에러를 내용을 출력하고 프로그램을 종료하는 함수
void error(char *str) {
    printf("%s",str);
    exit(1);
}
