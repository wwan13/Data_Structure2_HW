//자료구조2_HW2
//작성자 : 20194059 김태완
//작성일 : 2020.10.07
//프로그램명 : 이진트리를 이용한 여러가지 모듈

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode* new_node(int item);
TreeNode* insert_node_recursive(TreeNode *node, int data);

int main()
{
    printf("asd");
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
    
    if(data < node->data)
    {
        node -> left = insert_node_recursive(node->left,data);
    }
    else if (data > node->data)
    {
        node -> right = insert_node_recursive(node->right,data);
    }
    
    return node;
}

void insert_node_loop(TreeNode **root, int data)
{
    TreeNode *p, *t;
    TreeNode *n;
    
    t = *root;
    p = NULL;
    
    while(t != NULL)
    {
        if(data == t->data)
        {
            return;
        }
        p = t;
        if(data < t->data)
        {
            t = t->left;
        }
        else
        {
            t = t->right;
        }
    }
    
    n = new_node(data);
    
    if(p!=NULL)
    {
        if(data < p->data)
        {
            p->left = n;
        }
        else if(data > p->data)
        {
            p->right = n;
        }
    }
    else
    {
        *root = n;
    }
}
