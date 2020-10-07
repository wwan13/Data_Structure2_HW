//자료구조2_HW2
//작성자 : 20194059 김태완
//작성일 : 2020.10.07
//프로그램명 : 이진트리를 이용한 여러가지 모듈

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode
// TreeNode 구조체 정의
{
    int key; // key값
    struct TreeNode *left, *right; // 자식 노드
}TreeNode;

// 함수 원형 정의
void error(char* string);
TreeNode* new_node(int item);
TreeNode* insert_node_recursive(TreeNode *node, int data);
void insert_node_loop(TreeNode **root, int data);
int get_node_count(TreeNode *node);
int get_max(int n1, int n2);
int get_height(TreeNode *node);
int get_leaf_count(TreeNode *node);
void free_memory(TreeNode *root);
void display_format(char *string);
void display_time(double time);
void display_result(int count_node, int height, int count_leaf);

int main()
{
    FILE *fp = NULL; // 파일 포인터 fp
    int tmp; // 파일에서 받아온 정수를 임시로 저장해둘 변수 tmp
    TreeNode *node1 = NULL; // 첫번째 이진트리
    TreeNode *node2 = NULL; // 두번째 이진트리
    double time; // 소요 시간을 저장해둘 time
    clock_t start, finish; // 시작 시간과 끝나는 시간을 저장해주는 변수
    
    fp = fopen("data_test.txt", "r"); // 읽기 모드로 data.txt 파일 오픈

    if (fp == NULL) // 파일오픈 오류 처리
    {
        error("file open error");
    }

    display_format("     순환     "); // 순환으로 삽입 연산 진행
    start = clock(); // 시작 시간 측정
    while (!feof(fp)) // 파일의 끝까지
    {
        fscanf(fp, "%d", &tmp); // 정수 하나씩 읽어서
        node1 = insert_node_recursive(node1, tmp); // 삽입(순환) 연산 진행
    }
    finish = clock(); // 종료 시간 측정
    time = (double)(finish - start) / CLOCKS_PER_SEC; // 소요 시간 계산
    display_time(time); // 소요 시간 출력

    rewind(fp); // 파일포인터를 맨 앞으로 돌린다
    printf("\n");

    display_format("     반복     "); // 반복으로 삽입 연산 진행
    start = clock(); // 시작 시간 측정
    while (!feof(fp)) // 파일의 끝까지
    {
        fscanf(fp, "%d", &tmp); // 정수를 하나씩 읽어서
        insert_node_loop(&node2, tmp); // 삽입(반복) 연산 진행
    }
    finish = clock(); // 종료 시간 측정
    time = (double)(finish - start) / CLOCKS_PER_SEC; // 소요 시간 계산
    display_time(time); // 소요 시간 출력

    printf("\n");

    display_format("     연산     "); // 연산 결과
    display_result(get_node_count(node1), get_height(node1), get_leaf_count(node1));
    // 총 노드의 개수, 트리의 높이, 단말 노드의 개수 출력
    
    fclose(fp); // 파일 닫기
    free_memory(node1); // node1 메모리 반납
    free_memory(node2); // node2 메모리 반납
    
    return 0; //프로그램 종료
}

void error(char* string)
// 에러를 출력하고 프로그램을 종료하는 함수
{
    printf("%s\n", string); // 매개변수로 받아온 문자열 (오류문장) 출력
    exit(1);
}

TreeNode* new_node(int data)
// 새로운 노드를 생성하고 자식 노드를 NULL로 설정하는 함수
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode)); // 메모리 할당
    if(temp==NULL) // 동적메모리 할당 오류 처리
    {
        error("memory allocate error");
    }
    temp->key = data; // key 에 받아온 item 저장
    temp->left = NULL; // 왼쪽 자식 노드 NULL
    temp->right = NULL; // 오른쪽 자식 노드 NULL

    return temp;
}

TreeNode* insert_node_recursive(TreeNode *node, int data)
// 순환의 방식으로 이진 탐색 트리의 삽입 연산을 진행하는 함수
{
    if (node == NULL) // 단말 노드일 경우
    {
        return new_node(data); // 새로운 노드를 생성
    }

    if (data < node->key) // 받아온 데이터가 부모노드의 key값보다 작을경우
    {
        node->left = insert_node_recursive(node->left, data);
        // 왼쪽 노드로 이동
    }
    else if (data > node->key) // 받아온 데이터가 부모노드의 key값보다 클경우

    {
        node->right = insert_node_recursive(node->right, data);
        // 오른쪽 노드로 이동
    }

    return node;
}

void insert_node_loop(TreeNode **root, int data)
// 반복의 방식으로 이진 탐색 트리의 삽입 연산을 진행하는 함수
{
    TreeNode *p, *t;
    TreeNode *n;

    t = *root;
    p = NULL;

    while (t != NULL) // t 가 비어있지 않을 떄 까지
    {
        if (data == t->key) // data와 key값이 같을 경우
        {
            return; // 함수 종려
        }
        p = t; // 이전 노드의 주소를 기억 하기 위해 포인터 변수 P 사용
        if (data < t->key) // data 가 key 값보다 작을 경우
        {
            t = t->left; // 왼쪽 자식 노드 진입
        }
        else // data 가 key 값보다 클 경우
        {
            t = t->right; // 오른쪽 자식 노드 진입
        }
    }

    n = new_node(data); // 새로운 노드 생성

    if (p != NULL) // p가 비어있지 않을 경우
    {
        if (data < p->key) // data 가 key 값보다 작을 경우
        {
            p->left = n; // 왼쪽에 새로운 노드 연결
        }
        else if (data > p->key) // data 가 key 값보다 클 경우
        {
            p->right = n; // 오른쪽에 새로운 노드 연결
        }
    }
    else // p 가 비어있는 경우
    {
        *root = n; // 새로운 노드를 루트로 지정
    }
}

int get_node_count(TreeNode *node)
// 이진 탐색 트리의 노드 개수를 구하는 함수
{
    int count = 0;
    if (node != NULL) // 노드가 비어있지 않을 경우
    {
        count = 1 + get_node_count(node->left) + get_node_count(node->right);
        // 각 자식 노드에 대해 순환 호출 한 후 1을 더해 전체 노드의 개수를 구한다.
    }
    return count;
}

int get_max(int n1, int n2)
// 두 값중 큰 수를 구하는 함수
{
    if (n1 > n2) // n1이 더 큰 경우
    {
        return n1; // n1 반환
    }
    else // n2가 더 큰 경우
    {
        return n2; // n2 반환
    }
}

int get_height(TreeNode *node)
// 이진 탐색 트리의 높이를 구하는 함수
{
    int height = 0;
    if (node != NULL) // 노드가 비어있지 않은 경우
    {
        height = 1 + get_max(get_height(node->left), get_height(node->right));
        // 왼쪽 노드와 오른쪽 노드중 더 높이가 큰 쪽을 순환호출하고 1을 더해 트리의 전체 놓이 계산.
    }
    return height;
}

int get_leaf_count(TreeNode *node)
// 이진 탐색 트리의 단말 노드 개수를 구하는 함수
{
    int count = 0;

    if (node != NULL)
    {
        if (node->left == NULL && node->right == NULL) // 단말 노드일 경우
        {
            return 1; // 1 반환
        }
        else // 비단말 노드의 경우
        {
            count = get_leaf_count(node->left) + get_leaf_count(node->right);
            // 왼쪽 오른쪽 자식 노드 각각에 대해 순환 호출 하며 반환값을 더해주어 단말 노드의 개수 계산.
        }
    }
    return count;
}

void free_memory(TreeNode *root)
// 후위순회 하며 사용한 메모리를 반납하는 함수
{
    if(root!=NULL)
    {
        free_memory(root->left); // 왼쪽 자식 노드 접근
        free_memory(root->right); // 오른쪽 자식 노드 접근
        free(root); // 메모리 해제
    }
}

void display_format(char *string)
// 이후 나올 출력에 대한 형식을 출력 해주는 함수
{
    printf("┌──────────────────────────┐\n");
    printf("│       %4s     │\n", string); // 매개변수로 받아온 문자열 출력
    printf("└──────────────────────────┘\n");
}

void display_time(double time)
// 소요된 시간을 출력 해주는 함수
{
    printf("┌──────────────────────────┐\n");
    printf("│ 소요시간 : %lf      │\n", time); // 매개변수로 받아온 소요 시간 출력
    printf("└──────────────────────────┘\n");
}

void display_result(int count_node,int height, int count_leaf)
// 이진 탐색 트리에 대한 추가 연산 결과를 출력 해주는 함수
{
    printf("┌──────────────────────────┐\n");
    printf("│ 전체 노드의 개수 : %5d │\n", count_node); // 전체 노드의 개수 출력
    printf("│ 이진트리의 높이: %3d     │\n", height); // 트리의 높이 출력
    printf("│ 단말 노드의 개수 : %5d │\n", count_leaf); // 단말 노드의 개수 출력
    printf("└──────────────────────────┘\n");
}
