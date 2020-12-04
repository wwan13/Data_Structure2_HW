// 작성자 : 20194059 김태완
// 작성일 : 2020.11.29
// 프로그램명 : 다양한 정렬 방법들의 실행 시간을 비교하는 프로그램

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sort_methods.h"

void error(char *str);
void copy_array(char **data, char **temp, int n);
void display_format( char *str, int count, double time );

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
    char **temp;
    
    
    // 시간을 측정하는데 사용할 clock_t 타입 변수 선언
    clock_t start, finish;
    // 측정한 시간을 저장할 변수 선언
    double time;
    
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
        data[i] = (char *)malloc(sizeof(char) * (length+1));
        strcpy(data[i], tmp);
        i++;
    }
    
    // 원본 데이터 저장
    temp = data;
    
    // 파일 닫기
    fclose(fp);
    
    // 삽입 정렬 시간 계산
    start = clock();
    insertion_sort(data, count);
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
    display_format("삽입정렬", count, time);
    // 다시 원본 배열로 돌리기
    copy_array(data, temp, count);
    
    // 선택정렬 시간 계산
    start = clock();
    selection_sort(data, count);
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
    display_format("선택정렬", count, time);
    copy_array(data, temp, count);
    
    // 버블 정렬 시간 계산
    start = clock();
    bubble_sort(data, count);
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
    copy_array(data, temp, count);
    display_format("버블정렬", count, time);

    // 쉘 정렬 시간 계산
    start = clock();
    shell_sort(data, count);
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
    copy_array(data, temp, count);
    display_format("쉘정렬 ", count, time);
    
    // 합병 정렬 시간 계산
    start = clock();
    merge_sort(data, 0, count-1);
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
    copy_array(data, temp, count);
    display_format("합병정렬", count, time);
    
    // 퀵 정렬 시간 계산
    start = clock();
    quick_sort(data, 0, count-1);
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
    copy_array(data, temp, count);
    display_format("퀵정렬", count, time);
    
    // 힢 정렬 시간 계산
    start = clock();
    heap_sort(data, count);
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
    display_format("힢정렬", count, time);
    
    // 사용한 데이터 해제
    for(i=0;i<count;i++) {
        free(data[i]);
    }
    
    return 0;
}

// 에러를 내용을 출력하고 프로그램을 종료하는 함수
void error(char *str) {
    printf("%s",str);
    exit(1);
}

// 데이터를 복사하는 함수
void copy_array(char **data, char **temp, int n) {
    
    int i;
    
    for(i=0;i<n;i++) {
        data[i] = temp[i];
    }
    
}

void display_format( char *str, int count, double time ) {
    printf("----------< %10s >----------\n",str);
    printf("   - 데이터 갯수 >> %d -\n",count);
    printf("   - 걸린 시간 >> %.4lf -\n",time);
    printf("------------------------------\n\n");
}
