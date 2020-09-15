//작성자 : 20194059 김태완
//작성일 : 2020.09.11
//프로그램명 : 연결리스트를 이용해 이름, 학번, 총점 순으로 정렬하는 프로그램

#define _CRT_SECURE_NO_WARNINGS
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
void error(char* string);
NODE* insert_data(NODE* head, STUDENT value);
void print_type(char *string);
void print_list(NODE *head);
void free_memory(NODE* head);
NODE* sort_by_number(NODE* head);
NODE* sort_by_name(NODE* head);
NODE* sort_by_grade(NODE *head);

int main()
{
    FILE *fp; // 파일 포인터 생성
    STUDENT tmp; // 파일에서 데이터를 받아오기 위해 임시로 사용하는 변수
    NODE* head = NULL; // 연결리스트의 맨 처음 노드를 가리키는 변수

    
    fp = fopen("data.txt","r"); // 파일 오픈
    
    if(fp == NULL) //파일 오픈 오류시 에러 출력 후 코드 종료
    {
        error("file open error");
    }
    
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %f",&tmp.num,tmp.name,&tmp.grade);
        head = insert_data(head, tmp);
    }
    rewind(fp);
    fclose(fp);
    
    print_type("   정렬 전    ");
    print_list(head);
    printf("\n");
    
    print_type("학번 기준 정렬");
    head = sort_by_number(head);
    print_list(head);
    printf("\n");

    print_type("이름 기준 정렬");
    head = sort_by_name(head);
    print_list(head);
    printf("\n");

    print_type("총점 기준 정렬");
    head = sort_by_grade(head);
    print_list(head);
    
    free_memory(head);
    return 0;
}

void error(char* string)
// 에러를 출력하고 프로그램을 종료하는 함수
{
    printf("%s\n",string);
    exit(1);
}

NODE* insert_data(NODE* head, STUDENT value)
// 연결리스트에 데이터를 삽입하는 함수
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    if(p==NULL)
    {
        error("memory allocate arror");
    }
    p->student = value;
    p->link = head;
    head = p;
    return head;
}

void print_type(char *string)
// 리스트 출력 전 어떤 방식으로 정렬했는지 알려주기 위한 출력 함수
{
    printf("┌──────────────────────────┐\n");
    printf("│       %8s     │\n",string);
    printf("└──────────────────────────┘\n");
}

void print_list(NODE *head)
// 리스트를 출력하는 함수
{
    NODE *p = NULL;
    printf("┌──────────┬────────┬──────┐\n");
    printf("│    학번  │   이름 │ 총점 │\n");
    printf("├──────────┼────────┼──────┤\n");

    for(p = head;p!=NULL;p=p->link)
    {
        printf("│ %8d │ %4s │ %.2f │\n",p->student.num,p->student.name,p->student.grade);
    }
    printf("└──────────┴────────┴──────┘\n");
}

void free_memory(NODE* head)
// 연결리스트에 사용된 메모리를 해제하는 함수
{
    NODE *p = NULL;
    NODE *tmp = NULL;
    for(p = head;p!=NULL;p=p->link)
    {
        tmp = p;
        free(tmp);
    }
}

void swap(NODE* n1, NODE* n2)
// 두 노드의 데이터를 서로 바꿔주는 함수
{
    STUDENT tmp;
    tmp = n1->student;
    n1->student = n2->student;
    n2->student=tmp;
}

NODE* sort_by_number(NODE* head)
// 학번을 기준으로 정렬하는 함수
{
    NODE* p = NULL;
    NODE* k = NULL;
    
    for(p=head;p->link!=NULL;p=p->link)
    {
        for(k=head;k->link!=NULL;k=k->link)
        {
            if(k->student.num > k->link->student.num)
            {
                swap(k,k->link);
            }
        }
    }
    return head;
}

NODE* sort_by_name(NODE* head)
// 이름을 기준으로 정렬하는 함수
{
    NODE* p = NULL;
    NODE* k = NULL;
    
    for(p=head;p->link!=NULL;p=p->link)
    {
        for(k=head;k->link!=NULL;k=k->link)
        {
            if(strcmp(k->student.name,k->link->student.name)>0)
            {
                swap(k,k->link);
            }
        }
    }
    return head;
}

NODE* sort_by_grade(NODE *head)
// 점수를 기준으로 정렬하는 함수
{
    NODE* p = NULL;
    NODE* k = NULL;
    
    for(p=head;p->link!=NULL;p=p->link)
    {
        for(k=head;k->link!=NULL;k=k->link)
        {
            if(k->link->student.grade > k->student.grade)
            {
                swap(k,k->link);
            }
        }
    }
    return head;
}
