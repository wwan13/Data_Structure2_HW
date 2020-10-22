 //Student.txt 파일에 학번, 이름, 총점 데이터가 저장되어 있다. 이 데이터를 입력받아 학번을 기준으로 이진 탐색 트리에 저장하고 아래와 같이 출력하시오.
 //(1) i : 학번, 이름, 총점 데이터를 이진 탐색 트리에 저장
 //(2) u : 점수가 입력되면 입력 점수보다 높은(초과) 학생 점수의 총합
 //(3) s : 점수가 입력되면 입력 점수보다 낮은(미만) 학생 목록 출력
 //(4) d : 학번이 입력되면 해당 학번 학생 데이터 삭제 후 학생 목록(오름차순) 출력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int num,score;
    char name[30];
}student;

typedef struct TreeNode
{
    student key;
    struct TreeNode *left, *right;
} TreeNode;

void error(char *str);
TreeNode *new_node(student item);
TreeNode *insert_node(TreeNode *node, student key);

int main()
{
    FILE *fp = NULL;
    char ch;
    student tmp;
    TreeNode *data = NULL;
    
    fp = fopen("Student.txt","r");
    if(fp == NULL)
    {
        error("file open error");
    }
    
    while(!feof(fp))
    {
        fscanf(fp,"%c",&ch);
        if(ch=='i')
        {
            fscanf(fp,"%d %s %d",&tmp.num,tmp.name,&tmp.score);
            insert_node(data, tmp);
        }
        else if(ch=='u')
        {
            
        }
        else if(ch=='s')
        {
            
        }
        else if(ch=='d')
        {
            
        }
    }
    
    
}

void error(char *str)
{
    printf("%s\n",str);
    exit(1);
}

TreeNode *new_node(student item)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode *insert_node(TreeNode *node, student key)
{
    if (node == NULL)
        return new_node(key);

    if (key.score < node->key.score)
        node->left = insert_node(node->left, key);
    else if (key.score > node->key.score)
        node->right = insert_node(node->right, key);

    return node;
}

//가장 비슷한 값을 가진 노드를 찾는 함수
TreeNode *min_value_node(TreeNode *node)
{
    TreeNode *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

TreeNode *delete_node(TreeNode *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = delete_node(root->left, key);
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    else
    {
        //서브트리가 없거나 하나일때
        if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        //서브트리가 두개일때
        TreeNode *temp = min_value_node(root->right);

        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}
