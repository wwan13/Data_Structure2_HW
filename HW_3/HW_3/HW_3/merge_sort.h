#ifndef __MERGE_SORT__
#define __MERGE_SORT__

#include <string.h>
#include <stdlib.h>

// [merge]
// 두 부분 리스트를 합치는 함수
// @param (char** data) -> 정렬 해야 할 문자열을 갖고 있는 이중 포인터
// @param (int left, int right) -> 정렬 해야 할 리스트의 왼쪽 끝과 오른쪽 끝 인덱스를 담은 변수
// @param (int mid) -> 가운데 인덱스를 담은 변수
void merge( char** data, int left, int mid, int right ) {
    
    // 반복을 위한 변수 선언
    int i,j,k,l;
    // 정렬된 배열을 담을 임시 메모리
    char **sorted_list;
    // i -> 왼쪽 리스트에 대한 인덱스, k -> 전체 리스트에 대한 인덱스
    i = k = left;
    // j-> 오른쪽 리스트에 대한 인덱스
    j = mid + 1;
    
    // 정렬된 결과를 담을 임시 배열 메모리 할당
    sorted_list = (char **)malloc(sizeof(char *) * right+1);
    
    // 분할 정렬된 두 리스트 합병
    while ( i<=mid && j<=right ) {
        
        if( strcmp(data[i],data[j]) <= 0 ) {
            sorted_list[k++] = data[i++];
        }
        
        else {
            sorted_list[k++] = data[j++];
        }
        
    }
    // 오른쪽에 남아있는 데이터 복사
    if( i>mid ) {
        for( l=j;l<=right;l++ ) {
            sorted_list[k++] = data[l];
        }
    }
    // 왼쪽에 남아있는 데이터 복사
    else {
        for( l=i;l<=mid;l++ ) {
            sorted_list[k++] = data[l];
        }
    }
    
    // 정렬된 결과 복사 & 메모리 해제
    for( l=left;l<=right;l++ ) {
        data[l] = sorted_list[l];
    }
    
    
    free(sorted_list);
    
}

// [merge_sort]
// 합병정렬 알고리즘
// @param (char** data) -> 정렬 해야 할 문자열을 갖고 있는 이중포인터
// @param (int left) -> 제일 왼쪽 인덱스 번호를 가르키는 변수
// @param (int right) -> 제일 오른쪽 인덱스 번호를 가르키는 변수
void merge_sort( char** data, int left, int right ) {
    
    // 중앙 인덱스의 번호를 갖고 있는 변수
    int mid;
    
//    char** sorted_list = (char **)malloc(sizeof(char *) * right+1);
    
    if( left < right ) {
        // 가운데를 기준으로 리스트 분할
        mid = (left + right) / 2;
        
        // 분할된 리스트 각각 정렬
        merge_sort(data, left, mid);
        merge_sort(data, mid+1, right);
        
        // 분할되어 정렬된 리스트들 합병
        merge(data, left, mid, right);
    }
}

#endif 
