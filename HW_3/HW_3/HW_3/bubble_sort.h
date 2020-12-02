#ifndef __BUBBLE_SORT__
#define __BUBBLE_SORT__

#include "swap.h"

// [bubble_sort]
// 버블 정렬 알고리즘
// @param (int data[]) -> 정렬 해야 할 데이터 리스트
// @param (int n) -> 데이터의 개수
void bubble_sort( int data[], int n ) {
    
    // 반복문을 위한 변수
    int i,j;
    
    for( i=n;i>0;i-- ) {
        
        for( j=1;j<i;j++ ) {
            
            if( data[j]>data[j+1] ) {
                swap(data[j],data[j+1]);
            }
            
        }
        
    }
}

#endif
