// 자료구조 실습 중간고사 1번
// 20194059 김태완

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char eng[50];
    char kor[50];
}dict;

typedef struct TreeNode
{
    dict key;
    struct TreeNode *left, *right;
} TreeNode;

void error(char *str);
TreeNode *new_node(dict item);
TreeNode *insert_node(TreeNode *node, dict key);
TreeNode *search(TreeNode *node, dict key);
TreeNode *min_value_node(TreeNode *node);
TreeNode *delete_node(TreeNode *root, dict key);
void inorder(TreeNode *root);
void free_memory(TreeNode *node);

int main()
{
    FILE *fp = NULL;
    char choice;
    dict tmp;
    TreeNode *root = NULL;
    
    fp = fopen("data1.txt","r");
    if(fp==NULL) error("file open error");
    
    printf("<< 사전에 단어를 등록 해 주세요 >>\n");
    while(!feof(fp))
    {
        fscanf(fp," %c",&choice);
        
        if(choice=='i')
        {
            fscanf(fp,"%s %s",tmp.eng,tmp.kor);
            printf("<< input : %s >>  ",tmp.eng);
            printf("%s : %s\n",tmp.eng,tmp.kor);
            root = insert_node(root,tmp);
        }
        else if(choice=='s')
        {
            fscanf(fp,"%s",tmp.eng);
            printf("<< search : %s >>  ",tmp.eng);
            root = search(root, tmp);
            printf("%s : %s\n",root->key.eng,root->key.kor);
        }
        else if(choice=='d')
        {
            fscanf(fp,"%s",tmp.eng);
            printf("<< delete : %s >>  ",tmp.eng);
            root = delete_node(root,tmp);
            printf("%s 단어삭제 \n",tmp.eng);
        }
        else if(choice=='p')
        {
            printf("<< print dictionary >>\n");
            inorder(root);
            printf("\n");
        }
        else if(choice=='q')
        {
            printf("<< exit >> \n");
            return 0;
        }
        else
        {
            printf("input is not correct.");
        }
    }
    free_memory(root);
    fclose(fp);
}

void error(char *str)
{
    printf("%s",str);
    exit(1);
}

TreeNode *new_node(dict item)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    if(temp==NULL) error("memory allocate error");
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode *insert_node(TreeNode *node, dict key)
{
    if (node == NULL)
        return new_node(key);
    
    if (strcmp(key.eng,node->key.eng)<0)
        node->left = insert_node(node->left, key);
    else if (strcmp(key.eng,node->key.eng)>0)
        node->right = insert_node(node->right, key);

    return node;
}

TreeNode *search(TreeNode *node, dict key)
{
    if (node == NULL)
        return NULL;
    if (strcmp(key.eng,node->key.eng)==0)
        return node;
    else if (strcmp(key.eng,node->key.eng)<0)
        return search(node->left, key);
    else
        return search(node->right, key);
}

TreeNode *min_value_node(TreeNode *node)
{
    TreeNode *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

TreeNode *delete_node(TreeNode *root, dict key)
{
    if (root == NULL)
        return root;

    if (strcmp(key.eng,root->key.eng)<0)
        root->left = delete_node(root->left, key);
    else if (strcmp(key.eng,root->key.eng)>0)
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

void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        root->key.eng[0] = toupper(root->key.eng[0]);
        printf("%s : %s, ", root->key.eng,root->key.kor);
        inorder(root->right);
    }
}

void free_memory(TreeNode *node) {
   if (node) {
       free_memory(node->left);
       free_memory(node->right);
       free(node);
   }
}
