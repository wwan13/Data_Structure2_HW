#ifndef __SHELL_SORT__
#define __SHELL_SORT__

// [gap_insertion_sort]
// gap 의 범위만큼의 요소들에 대해 삽입 정렬 하는 알고리즘
// @param (int data[]) -> 정렬 해야 할 데이터를 담은 리스트
// @param (int first, int last) -> 정렬 해야할 리스트의 처음과 끝 인덱스를 담은 변수
// @param (int gap) -> 두 인덱스의 차이
void gap_insertion_sort( int data[],int first,int last, int gap ) {
    
    // 반복문을 위한 변수
    int i,j;
    // 삽입할 데이터인 key값을 저장하는 변수
    int key;
    
    for( i=first+gap;i<last;i+=gap ) {
        key = data[i];
        
        for( j=i-gap;j>=first && data[j]>key;j-=gap ) {
            data[j+gap] = data[j];
        }
        
        data[j+gap] = key;
    }

}

// [shell_sort]
// 쉘 정렬 알고리즘
// @param (int data[]) -> 정렬할 데이터를 담은 리스트
// @param (int n) -> 데이터의 개수
void shell_sort( int data[],int n ) {
    
    // 반복문을 위한 변수
    int i;
    // 두 인덱스의 차이를 담고 있는 변수
    int gap;
    
    for( gap=n/2;gap>0;gap/=2 ) {
        
        if( gap%2==0 ) {
            gap ++;
        }
        
        for( i=0;i<gap;i++ ) {
            gap_insertion_sort(data,i,n-1,gap);
        }
    }
}

#endif
