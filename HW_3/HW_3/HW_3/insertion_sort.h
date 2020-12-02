#ifndef __INSERTION_SORT__
#define __INSERTION_SORT__

// [insrtion_sort]
// 삽입정렬 알고리즘
// @param (int list) -> 정렬할 리스트
// @param (int n) -> 데이터의 개수
void insertion_sort( int data[],int n ) {
    
    // 반복문을 위한 변수
    int i,j;
    // 삽입할 데이터인 key값을 저장하는 변수
    int key;
    
    for( i=0;i<n;i++ ) {
        key = data[i];
        
        for( j=i-1;j<=0 && data[j]>key;j-- ) {
            data[j+1] = data[j];
        }
        
        data[j+1] = key;
    }
}


#endif

