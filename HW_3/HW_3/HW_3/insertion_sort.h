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
    
    for( i=0;i<n;i++ ) {
        key = data[i];
        
        for( j=i-1;j>=0 && strcmp(data[j],key)>0;j-- ) {
            data[j+1] = data[j];
        }
        
        data[j+1] = key;
    }
//
//    for(i=0;i<n;i++) {
//        printf("%s ",data[i]);
//    }
}


#endif

