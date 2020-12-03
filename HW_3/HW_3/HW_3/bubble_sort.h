#ifndef __BUBBLE_SORT__
#define __BUBBLE_SORT__

#include <string.h>

#include "swap.h"

// [bubble_sort]
// 버블 정렬 알고리즘
// @param (char** data) -> 정렬 해야 할 데이터 리스트
// @param (int n) -> 데이터의 개수
void bubble_sort( char** data, int n ) {
    
    // 반복문을 위한 변수
    int i,j;
    
    for( i=n-1;i>0;i-- ) {
        
        for( j=0;j<i;j++ ) {
            
            if( strcmp(data[j],data[j+1])>0 ) {
                swap(data[j],data[j+1]);
            }
            
        }
        
    }
}

#endif
