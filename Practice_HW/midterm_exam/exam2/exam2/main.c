// 자료구조 2 실습 중간고사 문제 2
// 20194059 김태완

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

typedef struct
{
    int num;
    char name[50];
    int eng_score;
    int math_score;
    int kor_score;
    int total_score;
    double average;
}student;

typedef struct
{
    student heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

void error(char *str);
HeapType *create(void);
void init(HeapType *h);
void insert_max_heap(HeapType *h, student item);
void heap_sort(HeapType *h, int n);

int main()
{
    FILE *fp = NULL;
    student tmp;
    HeapType *heap;
    int n=0;
    
    fp = fopen("data02.txt","r");
    if(fp==NULL) error("file open error");
    
    heap = create();
    init(heap);
    
    printf("<< 정렬 전 >>\n\n");
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %d %d %d",&tmp.num,tmp.name,&tmp.kor_score,&tmp.eng_score,&tmp.math_score);
        tmp.total_score = tmp.kor_score + tmp.eng_score + tmp.math_score;
        tmp.average = tmp.total_score / 3;
        printf("%d %s %3d %3d %3d %3d %.2lf\n",tmp.num,tmp.name,tmp.kor_score,tmp.eng_score,tmp.math_score,tmp.total_score,tmp.average);
        insert_max_heap(heap, tmp);
        n++;
    }
    printf("\n\n");
    printf("<< 정렬 후 >>\n\n");
    heap_sort(heap, n);
    
    fclose(fp);
    free(heap);
}

void error(char *str)
{
    printf("%s",str);
    exit(1);
}

HeapType *create()
{
    return (HeapType *)malloc(sizeof(HeapType));
}

void init(HeapType *h)
{
    h->heap_size = 0;
}

void insert_max_heap(HeapType *h, student item)
{
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item.total_score > h->heap[i / 2].total_score))
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

student delete_max_heap(HeapType *h)
{
    int parent, child;
    student item, temp;

    item = h->heap[1];
    temp = h->heap[h->heap_size--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size)
    {
        if ((child < h->heap_size) && h->heap[child].total_score < h->heap[child + 1].total_score)
        {
            child++;
        }
        if (temp.total_score >= h->heap[child].total_score)
            break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void heap_sort(HeapType *h, int n)
{
    int i;
    student a[n+1];
    for (i = n; i > 0; i--)
    {
        a[i] = delete_max_heap(h);
        printf("%d %s %3d %3d %3d %3d %.2lf\n",a[i].num,a[i].name,a[i].kor_score,a[i].eng_score,a[i].math_score,a[i].total_score,a[i].average);
    }
}
