#ifndef __SELECTION_SORT__
#define __SELECTION_SORT__

#include "swap.h"

// [selection_sort]
// 선택정렬 알고리즘
// @param (char** data) -> 정렬해야 할 문자열을 담은 리스트
// @param (int n) -> 데이터 개수
void selection_sort( char** data, int n ) {
    
    // 반복문에서 사용하는 변수
    int i,j;
    // 최소 인덱스를 저장하는 변수
    int least;
    
    for ( i=0;i<n-1;i++ ) {
        least = i;
        for ( j=i+1;j<n;j++ ) {
            // strcmp(data[j],data[least])<0
            if ( strcmp(data[j],data[least])<0 ) {
                least = j;
            }
            swap( data[i],data[least] );
        }
    }
    
//    for(i=0;i<n;i++) {
//        printf("%s " ,data[i]);
//    }
}

#endif

