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
    
    // 피봇을 배열의 맨 왼쪽 인덱스로 초기화
    pivot = data[left];
    
    do {
        
        do {
            low++;
        } while ( low<=right && ( strcmp(data[low],pivot) < 0 ) );
        
        do {
            high--;
        } while ( high>=left && ( strcmp(data[high],pivot) > 0 ) );
        
        if( low<high ) {
            swap( data[low],data[high] );
        }
        
    } while( low<high );
    
    swap( data[left],data[high] );
    
    return high;
    
}

// [quick_sort]
// 퀵정렬 알고리즘
// @param (char** data) -> 정렬 전 데이터
// @param (int left) -> 배열의 맨 왼쪽 인덱스
// @param (int right) -> 배열의 맨 오른쪽 인덱스
void quick_sort( char** data,int left,int right ) {
    
    if( left<right ) {
        int q = partition(data,left,right);
        quick_sort(data,left,q-1);
        quick_sort(data,q+1,right);
    }
    
}

#endif
