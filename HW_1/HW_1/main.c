//작성자 : 20194059 김태완
//작성일 : 2020.09.11
//프로그램명 : 연결리스트를 이용해 이름, 학번, 총점 순으로 정렬하는 프로그램

#define CRT_SECURE_NO_WARININGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
// 학생의 정보를 담고있는 구조체
{
    int num; // 학번
    char name[30]; // 이름
    float grade; // 총점
}STUDENT;

typedef struct node
// 단일링크드리스트 노드
{
    STUDENT student; // 데이터필드
    struct node *link; // 링크필드
}NODE;

//함수 원형 정의
NODE* insert_data(NODE* head, STUDENT value);
void print_list(NODE *head);
NODE* sort_by_number(NODE* head);

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
    printf("----------------------\n");
    
    head = sort_by_number(head);
    print_list(head);
    
}

NODE* insert_data(NODE* head, STUDENT value)
// 연결리스트에 데이터를 삽입하는 함수
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    p->student = value;
    p->link = head;
    head = p;
    return head;
}

void print_list(NODE *head)
// 리스트를 출력하는 함수
{
    for (NODE *p = head;p!=NULL;p = p->link)
    {
        printf("%d %s %.2f\n",p->student.num,p->student.name,p->student.grade);
    }
}

NODE* sort_by_number(NODE* head)
// 학번을 기준으로 정렬하는 함수
{
    NODE* p = NULL;
    //NODE* k = NULL;
    //NODE* tmp = NULL;
    
    for(p=head;p!=NULL;p=p->link)
    {
        /*
        for(k=p;k!=NULL;k=k->link)
        {
            if(k->link->student.num > k->student.num)
            {
                if(k==p)
                {
                    k->link = k->link->link;
                    k->link->link = k;
                }
                else
                {
                    //k->link = tmp->link;
                    k->link = k->link->link;
                    k->link->link = k;
                    //k->link = k;
                    tmp->link = k->link;
                }
            }
            tmp = k;
        }
        tmp = p;
         */
    }
    return head;
}

NODE* sort_by_name(NODE* head)
// 이름을 기준으로 정렬하는 함수
{
    
    return head;
}

NODE* sort_by_grade(NODE *head)
// 점수를 기준으로 정렬하는 함수
{
    
    return head;
}
