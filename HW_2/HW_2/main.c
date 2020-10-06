//자료구조2_HW2
//작성자 : 20194059 김태완
//작성일 : 2020.10.07
//프로그램명 : 이진트리를 이용한 여러가지 모듈

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
}TreeNode;

void error(char* string);
TreeNode* new_node(int item);
TreeNode* insert_node_recursive(TreeNode *node, int data);
void insert_node_loop(TreeNode **root, int data);
int get_node_count(TreeNode *node);
int get_max(int n1, int n2);
int get_height(TreeNode *node);
int get_leaf_count(TreeNode *node);
void display_format(char *string);
void display_time(double time);
void display_result(int count_node, int height, int count_leaf);

int main()
{
    FILE *fp = NULL;
    int tmp, input;
    TreeNode *node1 = NULL;
    TreeNode *node2 = NULL;
    double time;
    clock_t start, finish;
    fp = fopen("data.txt", "r");

    if (fp == NULL)
    {
        error("file open error");
    }

    display_format("     순환     ");
    start = clock();
    while (!feof(fp))
    {
        fscanf(fp, "%d", &tmp);
        node1 = insert_node_recursive(node1, tmp);
    }
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC; // 총 걸린 시간 계산
    display_time(time);

    rewind(fp);
    printf("\n");

    display_format("     반복     ");
    start = clock();
    while (!feof(fp))
    {
        fscanf(fp, "%d", &tmp);
        insert_node_loop(&node2, tmp);
    }
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC; // 총 걸린 시간 계산
    display_time(time);

    printf("\n");

    display_format("     연산     ");
    display_result(get_node_count(node1), get_height(node1), get_leaf_count(node1));
    
}

void error(char* string)
// 에러를 출력하고 프로그램을 종료하는 함수
{
    printf("%s\n", string); // 매개변수로 받아온 문자열 (오류문장) 출력
    exit(1);
}

TreeNode* new_node(int item)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

TreeNode* insert_node_recursive(TreeNode *node, int data)
{
    if (node == NULL)
    {
        return new_node(data);
    }

    if (data < node->data)
    {
        node->left = insert_node_recursive(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert_node_recursive(node->right, data);
    }

    return node;
}

void insert_node_loop(TreeNode **root, int data)
{
    TreeNode *p, *t;
    TreeNode *n;

    t = *root;
    p = NULL;

    while (t != NULL)
    {
        if (data == t->data)
        {
            return;
        }
        p = t;
        if (data < t->data)
        {
            t = t->left;
        }
        else
        {
            t = t->right;
        }
    }

    n = new_node(data);

    if (p != NULL)
    {
        if (data < p->data)
        {
            p->left = n;
        }
        else if (data > p->data)
        {
            p->right = n;
        }
    }
    else
    {
        *root = n;
    }
}

int get_node_count(TreeNode *node)
{
    int count = 0;
    if (node != NULL)
    {
        count = 1 + get_node_count(node->left) + get_node_count(node->right);
    }
    return count;
}

int get_max(int n1, int n2)
{
    if (n1 > n2)
    {
        return n1;
    }
    else
    {
        return n2;
    }
}

int get_height(TreeNode *node)
{
    int height = 0;
    if (node != NULL)
    {
        height = 1 + get_max(get_height(node->left), get_height(node->right));
    }
    return height;
}

int get_leaf_count(TreeNode *node)
{
    int count = 0;

    if (node != NULL)
    {
        if (node->left == NULL && node->right == NULL)
        {
            return 1;
        }
        else
        {
            count = get_leaf_count(node->left) + get_leaf_count(node->right);
        }
    }
    return count;
}

void display_format(char *string)
// 리스트 출력 전 어떤 방식으로 정렬했는지 알려주기 위한 출력 함수
{
    printf("┌──────────────────────────┐\n");
    printf("│       %4s     │\n", string); // 매개변수로 받아온 문자열 출력
    printf("└──────────────────────────┘\n");
}

void display_time(double time)
// 리스트 출력 전 어떤 방식으로 정렬했는지 알려주기 위한 출력 함수
{
    printf("┌──────────────────────────┐\n");
    printf("│ 소요시간 : %lf      │\n", time); // 매개변수로 받아온 문자열 출력
    printf("└──────────────────────────┘\n");
}

void display_result(int count_node,int height, int count_leaf)
// 리스트 출력 전 어떤 방식으로 정렬했는지 알려주기 위한 출력 함수
{
    printf("┌──────────────────────────┐\n");
    printf("│ 전체 노드의 갯수 : %5d │\n", count_node); // 매개변수로 받아온 문자열 출력
    printf("│ 이진트리의 높이: %3d     │\n", height);
    printf("│ 단말 노드의 갯수 : %5d │\n", count_leaf);
    printf("└──────────────────────────┘\n");
}
