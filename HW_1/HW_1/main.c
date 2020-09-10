//작성자 : 20194059 김태완
//작성일 : 2020.09.11
//프로그램명 : 연결리스트를 이용해 이름, 학번, 총점 순으로 정렬하는 프로그램

#define CRT_SECURE_NO_WARININGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int num;
    char name[30];
    float grade;
}STUDENT;

typedef struct node
{
    STUDENT student;
    struct node *link;
}NODE;

NODE* insert_data(NODE* head, STUDENT value);
void print_list(NODE *head);

int main()
{
    FILE *fp;
    STUDENT tmp;
    NODE* head = NULL;

    
    fp = fopen("data.txt","r");
    
    if(fp == NULL)
    {
        printf("file open error\n");
        exit(1);
    }
    
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %f",&tmp.num,tmp.name,&tmp.grade);
        head = insert_data(head, tmp);
        //printf("%d %s %f\n",tmp.num,tmp.name,tmp.grade);
    }
    rewind(fp);
    
    print_list(head);
    
    
}

NODE* insert_data(NODE* head, STUDENT value)
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    p->student = value;
    p->link = head;
    head = p;
    return head;
}

void print_list(NODE *head)
{
    for (NODE *p = head;p!=NULL;p = p->link)
    {
        printf("%d %s %.2f\n",p->student.num,p->student.name,p->student.grade);
    }
}

NODE* sort_by_integer(NODE* head)
{
    
    return head;
}

NODE* sort_by_string(NODE* head)
{
    
    return head;
}

NODE* sort_by_float(NODE *head)
{
    
    return head;
}
