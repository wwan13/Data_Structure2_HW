typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

// 스택 푸쉬
void push(TreeNode *p)
{
    if (top < SIZE - 1)
    {
        stack[++top];
    }
}

// 스택 팝
TreeNode pop()
{
    TreeNode *p = NULL;
    if (top >= 0)
    {
        p = stack[top--];
    }
    return p;
}

// 중위 순회
void inorder_iter(TreeNode *root)
{
    while (1)
    {
        for (; root != NULL; root->left)
        {
            push(root);
        }
        root = pop();
        if (root == NULL)
            break;
        printf("%d", root->data);
        root = root->data;
    }
}