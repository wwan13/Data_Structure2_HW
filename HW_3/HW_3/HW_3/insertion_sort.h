#ifndef __INSERTION_SORT__
#define __INSERTION_SORT__

#include <string.h>

// [insrtion_sort]
// 삽입정렬 알고리즘
// @param (char** data) -> 정렬할 리스트
// @param (int n) -> 데이터의 개수
void insertion_sort( char** data,int n ) {
    
    // 반복문을 위한 변수
    int i,j;
    // 삽입할 데이터인 key값을 저장하는 변수
    char* key;
    
    
    // n만큼 반복
    for( i=0;i<n;i++ ) {
        
        // key 에 data의 맨 첫값 저장
        key = data[i];
        
        // j>0 이고 data[j] 의 문자열이 key의 문자열보다 커질때 까지 반복
        for( j=i-1;j>=0 && strcmp(data[j],key)>0;j-- ) {
            
            // data[j+1] 에 data[j] 값 저장
            data[j+1] = data[j];
        }
        
        // data[j+1] 에는 key 값 저장
        data[j+1] = key;
    }

}

#endif

