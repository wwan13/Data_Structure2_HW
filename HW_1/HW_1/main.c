//자료구조2_HW1
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
// 단일 링크드리스트 노드
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
        // 파일에서 학번, 이름, 총점 순으로 데이터를 읽어온다
        head = insert_data(head, tmp);
        // 연결리스트에 파일로부터 불러온 데이터를 삽입한다
    }
    rewind(fp); // 파일 포인터의 위치를 맨 앞으로 돌린다
    fclose(fp); // 파일 닫기
    
    // 정렬 전 데이터 출력
    print_type("   정렬 전    ");
    print_list(head); // 노드를 옮겨가며 데이터 출력
    printf("\n");
    
    print_type("학번 기준 정렬");
    head = sort_by_number(head); // 학번을 기준으로 데이터 정렬
    print_list(head); // 노드를 옮겨가며 데이터 출력
    printf("\n");

    print_type("이름 기준 정렬");
    head = sort_by_name(head); // 이름을 기준으로 데이터 정렬
    print_list(head); // 노드를 옮겨가며 데이터 출력
    printf("\n");

    print_type("총점 기준 정렬");
    head = sort_by_grade(head); // 총점을 기준으로 데이터 정렬
    print_list(head); // 노드를 옮겨가며 데이터 출력
    
    free_memory(head); // 메모리 해제
    return 0; //프로그램 종료
}

void error(char* string)
// 에러를 출력하고 프로그램을 종료하는 함수
{
    printf("%s\n",string); // 매개변수로 받아온 문자열 (오류문장) 출력
    exit(1);
}

NODE* insert_data(NODE* head, STUDENT value)
// 연결리스트에 데이터를 삽입하는 함수
{
    NODE *p = (NODE *)malloc(sizeof(NODE)); // 메모리 동적 할당
    if(p==NULL) // 동적 할당 오류 처리
    {
        error("memory allocate arror");
    }
    p->student = value; // 데이터필드에 데이터 대입
    p->link = head; // 원래 헤드의 주소를 p의 링크 필드에 대입
    // 만약 헤드가 비어있어도 메인 함수에서 헤드를 NULL로 초기화 해 주어 맨 마지막 p->link에
    // NULL 값이 들어같 채로 새로운 데이터가 채워지기 때문에 따로 헤드가 비어있을떄의 처리를 안 해주어도 된다
    head = p; // 헤드를 p로 변경
    return head; // 헤드포인터의 주소 반환
}

void print_type(char *string)
// 리스트 출력 전 어떤 방식으로 정렬했는지 알려주기 위한 출력 함수
{
    printf("┌──────────────────────────┐\n");
    printf("│       %8s     │\n",string); // 매개변수로 받아온 문자열 출력
    printf("└──────────────────────────┘\n");
}

void print_list(NODE *head)
// 리스트를 출력하는 함수
{
    NODE *p = NULL;
    printf("┌──────────┬────────┬──────┐\n");
    printf("│    학번  │   이름 │ 총점 │\n");
    printf("├──────────┼────────┼──────┤\n");

    for(p = head;p!=NULL;p=p->link) // 노드가 끝날 때 까지 반복
    {
        printf("│ %8d │ %4s │ %.2f │\n",p->student.num,p->student.name,p->student.grade);
        // 학번 이름 총점 순으로 출력
    }
    printf("└──────────┴────────┴──────┘\n");
}

void free_memory(NODE* head)
// 연결리스트에 사용된 메모리를 해제하는 함수
{
    NODE *p = NULL;
    NODE *tmp = NULL;
    for(p = head;p!=NULL;p=p->link) // 노드가 끝날 때 까지 반복
    {
        tmp = p; // tmp에 p의 주소를 대입 해 주며
        free(tmp); // tmp에 담긴 주소의 메모리를 해제
    }
}

void swap(NODE* n1, NODE* n2)
// 두 노드의 데이터를 서로 바꿔주는 함수
{
    STUDENT tmp;
    // 두 데이터의 위치를 바꿔준다
    tmp = n1->student;
    n1->student = n2->student;
    n2->student=tmp;
}

NODE* sort_by_number(NODE* head)
// 학번을 기준으로 정렬하는 함수
{
    NODE* p = NULL;
    NODE* k = NULL;
    
    // 버블정렬 알고리즘 (학번은 오름차순으로 정렬 해야함)
    for(p=head;p->link!=NULL;p=p->link)
    {
        for(k=head;k->link!=NULL;k=k->link)
        {
            if(k->student.num > k->link->student.num) // 앞에있는 학번이 더 클 경우
            {
                swap(k,k->link); // 두 데이터의 위치 변경
            }
        }
    }
    return head; // 헤드 포인터 반환
}

NODE* sort_by_name(NODE* head)
// 이름을 기준으로 정렬하는 함수
{
    NODE* p = NULL;
    NODE* k = NULL;
    
    // 버블정렬 알고리즘 (이름은 사전순 오름차순으로 정렬)
    for(p=head;p->link!=NULL;p=p->link)
    {
        for(k=head;k->link!=NULL;k=k->link)
        {
            if(strcmp(k->student.name,k->link->student.name)>0)
            // 앞에 있는 데이터가 사전순으로 더 클 경우
            {
                swap(k,k->link); // 두 데이터의 위치 변셩
            }
        }
    }
    return head; // 헤드 포인터 반환
}

NODE* sort_by_grade(NODE *head)
// 점수를 기준으로 정렬하는 함수
{
    NODE* p = NULL;
    NODE* k = NULL;
    
    // 버블 정렬 알고리즘 (총점은 내림차순 정렬)
    for(p=head;p->link!=NULL;p=p->link)
    {
        for(k=head;k->link!=NULL;k=k->link)
        {
            if(k->link->student.grade > k->student.grade) // 뒤에 있는 데이터가 더 클 경우
            {
                swap(k,k->link); // 두 데이터의 위치 변경
            }
        }
    }
    return head; // 헤드 포인터 반환
}
