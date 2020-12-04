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
    
    // n-1 까지 반복
    for ( i=0;i<n-1;i++ ) {
        
        // 시작 값 저장
        least = i;
        
        for ( j=i+1;j<n;j++ ) {
            // 해당 데이터가 더 작을 경우
            if ( strcmp(data[j],data[least])<0 ) {
                // j를 최소값으로 저장
                least = j;
            }
            
            // data[i] 와 data[least] 값 교환
            swap( data[i],data[least] );
        }
    }
    
}

#endif

