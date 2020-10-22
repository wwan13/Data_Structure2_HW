#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENT 200

typedef struct
{
    int score;
    char name[50];
    int grade;
} student;

typedef struct
{
    student heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType *create(void);
void init(HeapType *h);
void insert_max_heap_by_score(HeapType *h, student item);
void insert_max_heap_by_name(HeapType *h, student item);
student delete_max_heap_by_score(HeapType *h);
student delete_max_heap_by_name(HeapType *h);
void heap_sort_by_score(student a[], int n);
void heap_sort_by_name(student a[], int n);

int main()
{
    FILE *fp;
    int n=0;
    student tmp;
    
    fp = fopen("Student2.txt","r");
    if(fp==NULL){
        printf("file open error");
        exit(1);
    }
    HeapType *h = create();
    init(h);
    
    while(!feof(fp))
    {
        fscanf(fp,"%s %d",tmp.name,&tmp.score);
        //printf("%s %d\n",tmp.name,tmp.score);
        insert_max_heap_by_score(h, tmp);
        n++;
    }
    printf("----- 점수 기준 내림차순 -----\n");
    heap_sort_by_score(h->heap, n);
    printf("----- 이름 기준 오름차순 -----\n");
    heap_sort_by_name(h->heap, n);
}

HeapType *create()
{
    return (HeapType *)malloc(sizeof(HeapType));
}

void init(HeapType *h)
{
    h->heap_size = 0;
}

void insert_max_heap_by_score(HeapType *h, student item)
{
    int i;
    i = ++h->heap_size;

    while ((i != 1) && (item.score > h->heap[i / 2].score))
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

void insert_max_heap_by_name(HeapType *h, student item)
{
    int i;
    i = ++h->heap_size;

    while ((i != 1) && strcmp(item.name, h->heap[i / 2].name) > 0)
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

student delete_max_heap_by_score(HeapType *h)
{
    int parent, child;
    student item, temp;

    item = h->heap[1];
    temp = h->heap[h->heap_size--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size)
    {
        if ((child < h->heap_size) && h->heap[child].score < h->heap[child + 1].score)
        {
            child++;
        }
        if (temp.score >= h->heap[child].score)
            break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

student delete_max_heap_by_name(HeapType *h)
{
    int parent, child;
    student item, temp;

    item = h->heap[1];
    temp = h->heap[h->heap_size--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size)
    {
        if ((child < h->heap_size) && strcmp(h->heap[child].name, h->heap[child + 1].name) > 0)
        {
            child++;
        }
        if (strcmp(temp.name, h->heap[child].name) > 0)
            break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void heap_sort_by_score(student a[], int n)
{
    int i;
    HeapType *h;

    h = create();
    init(h);

    for (i = 1; i <= n; i++)
    {
        insert_max_heap_by_score(h, a[i]);
    }
    for (i = 1; i <= n; i++)
    {
        a[i] = delete_max_heap_by_score(h);
        a[i].grade = i+1;
        printf("%d %s\n",a[i].score,a[i].name);
    }
    free(h);
}

void heap_sort_by_name(student a[], int n)
{
    int i;
    HeapType *h;

    h = create();
    init(h);

    for (i = 1; i <= n; i++)
    {
        insert_max_heap_by_name(h, a[i]);
    }
    for (i = 1; i <= n; i++)
    {
        a[i] = delete_max_heap_by_name(h);
        a[i].grade = i+1;
        printf("%d %s %d\n",a[i].score,a[i].name,a[i].grade);
    }
    free(h);
}
