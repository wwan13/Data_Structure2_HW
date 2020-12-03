#ifndef __HEAP_SORT__
#define __HEAP_SORT__

#include <string.h>

// [HeapType]
// 힙타입 구조체
// @member (char** heap) -> 힙의 데이터가 들어가는 이중포인터
// @member (char** heap_size) -> 힙의 크기
typedef struct
{
    char **heap;
    int heap_size;
} HeapType;

// [heap_create]
// 힙에 메모리를 할당하는 함수
// @prarm (int n) -> 전체 데이터의 개수를 담은 변수
// @return -> 메모리가 할당된 힙
HeapType *heap_create( int n )
{
    
    // 반복문을 위한 변수
    int i=0;
    
    // 힙타입 h 메모리 할당
    HeapType *h = (HeapType *)malloc(sizeof(HeapType));
    
    // h->heap 의 동적 메모리 할당
    h->heap = (char **)malloc(sizeof(char *) * n);
    for( i=0;i<n;i++ ) {
        h->heap[i] = (char *)malloc(sizeof(char) * 100);
    }
    
    return h;
    
}

// [heap_init]
// 힙을 초기화시키는 함수
// @param (HeapType *h) -> 힙
void heap_init(HeapType *h)
{
    h->heap_size = 0;
}

// [insert_max_heap]
// max_heap에 데이터를 삽입하는 함수
// @param (HeapType *h) -> 힙
// @param (char* item) -> 삽입 할 데이터
void insert_max_heap( HeapType *h, char* item ) {
    
    // 반복을 위한 변수 -> 힙의 크기 + 1 로 초기화
    int i = ++(h->heap_size);
    
    while( (i!=1) && (strcmp(item , h->heap[i/2]) > 0) ) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    
    h->heap[i] = item;
    
}

// [delete_max_heap]
// max_heap에서 데이터를 삭제하며 반환하는 함수
// @param (HeapThpe *h) -> 힙
// @return -> 삭제된 데이터
char* delete_max_heap( HeapType *h ) {
    
    int parent, child;
    
    char *item, *temp;
    
    item = h->heap[1];
    temp = h->heap[h->heap_size--];
    
    parent = 1;
    child = 2;
    
    while ( child<=h->heap_size ) {
        
        if ( (child<h->heap_size) && (strcmp(h->heap[child], h->heap[child+1])) ) {
            child++;
        }
        if ( strcmp(temp, h->heap[child]) )
            break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

// [heap_sort]
// 힙 정렬 알고리즘
// @param (char** data) -> 정렬해야할 데이터
// @param (int n) -> 전체 데이터의 개수
void heap_sort( char** data, int n ) {
    
    int i;
    
    HeapType *h = heap_create(n);
    heap_init(h);
    
    // 힙에 데이터 삽입
    for( i=0;i<n;i++ ) {
        insert_max_heap( h, data[i] );
    }
    
    // 힙에서 데이터를 뺴낸 후 원본 배열에 저장
    for( i=0;i<n;i++ ) {
        data[i] = delete_max_heap(h);
    }
    
}

#endif
