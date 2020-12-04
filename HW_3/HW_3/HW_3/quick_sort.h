#ifndef __QUICK_SORT__
#define __QUICK_SORT__

#include <string.h>

#include "swap.h"

// [partition]
// 파티션을 설정하는 함수
// @param (char** data) -> 정렬할 데이터를 담고있는 이중포인터
// @param (int left) -> 배열의 맨 왼쪽 인덱스
// @param (int right) -> 배열의 맨 오른쪽 인덱스
// @return -> 파티션의 맨 오른쪽 인덱스
int partition( char** data, int left, int right ) {
    
    // 피봇
    char* pivot;
    // low -> 맨 왼쪽 , high -> 맨 오른쪽 + 1
    int low = left;
    int high = right+1;
    
    // 피봇을 배열의 중간 인덱스로 초기화
    pivot = data[left];
    
    // low가 high보다 작을떄까지 반복
    do {
        
        // data[low] 가 피봇값보다 작아질때가지 low값 증가
        do {
            low++;
        } while ( low<=right && ( strcmp(data[low],pivot) < 0 ) );
        
        // data[low] 가 피봇값보다 커질때가지 low값 증가
        do {
            high--;
        } while ( high>=left && ( strcmp(data[high],pivot) > 0 ) );
        
        // low<high 이면 두 값 을 바꿈
        if( low<high ) {
            swap( data[low],data[high] );
        }
        
    } while( low<high );
    
    // data[left], data[right] 교환
    swap( data[left],data[high] );
    
    // 맨 오른쪽 인덱스 반환
    return high;
    
}

// [quick_sort]
// 퀵정렬 알고리즘
// @param (char** data) -> 정렬 전 데이터
// @param (int left) -> 배열의 맨 왼쪽 인덱스
// @param (int right) -> 배열의 맨 오른쪽 인덱스
void quick_sort( char** data,int left,int right ) {
    
    // left가 right 보다 작을 경우
    if( left<right ) {
        
        // 파티션 구하기
        int q = partition(data,left,right);
        
        // quick_sort 순환 호출
        quick_sort(data,left,q-1);
        quick_sort(data,q+1,right);
    }
    
}

#endif
