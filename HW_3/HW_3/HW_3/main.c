// 작성자 : 20194059 김태완
// 작성일 : 2020.11.29
// 프로그램명 : 다양한 정렬 방법들의 실행 시간을 비교하는 프로그램

// 삽입정렬--
// 선택정렬--
// 버블정렬--
// 쉘정렬-
// 퀵정렬
// 히프정렬
// 합병정렬

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort_methods.h"

void error(char *str);

int main()
{
    // 파일포인터
    FILE *fp;
    // 반복문을 위한 변수
    int i=0;
    // 임시로 문자열을 받기 위한 tmp 변수
    char tmp[100];
    // 각 문자열 하나의 길이를 담은 변수
    int length=0;
    // 데이터의 갯수를 저정할 변수
    int count=0;
    
    // 데이터 (문자열들) 를 담은 이중 포인터
    char **data;
    
    // 파일 오픈 && 예외 처리
    fp = fopen("data.txt","r");
    if(fp==NULL) {
        error("file open error");
    }
    
    // 파일 전체에 저장된 문자열의 개수 카운트
    while (!feof(fp)) {
        fscanf(fp, "%s", tmp);
        count++;
    }
    
    // 문자열의 개수만큼 2중 포인터로 메모리 할당
    data = (char **)malloc(sizeof(char *) * count);
    
    // 파일 리와인드
    rewind(fp);
    
    // 문자열을 이중 포인터에 저장하는 부분
    i=0;
    while (!feof(fp)) {
        fscanf(fp, "%s", tmp);
        // 문자열 하나마다의 크기를 계산하여 그 크기만큼 메모리 할당
        length = 0;
        while(tmp[length]!='\0') {
            length++;
        }
        // length = strlen(tmp);
        data[i] = (char *)malloc(sizeof(char) * (length+1));
        strcpy(data[i], tmp);
        printf("%s\n\n",data[i]);
        i++;
    }
    
    printf("-------\n");
//    insertion_sort(data, count);
//    selection_sort(data, count);
    bubble_sort(data, count);
//    shell_sort(data, count);

}

// 에러를 내용을 출력하고 프로그램을 종료하는 함수
void error(char *str) {
    printf("%s",str);
    exit(1);
}
