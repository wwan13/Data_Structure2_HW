//자료구조2_HW1
//작성자 : 20194059 김태완
//작성일 : 2020.10.07
//프로그램명 : 이진트리를 이용한 여러가지 모듈

#include <stdio.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
}TreeNode;

int main()
{
    printf("asd");
}

void recursive_inoder(TreeNode *root)
{
    if(root)
    {
        recursive_inoder(root->left);
        printf("|%d| ",root->data);
        recursive_inoder(root->right);
    }
}

void *pop()
{
    TreeNode *p = NULL;
    if(top >=0 )
    {
        p = stack
    }
}
