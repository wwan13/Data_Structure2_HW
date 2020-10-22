typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *search(TreeNode *node, int key)
{
    if (node == NULL)
        return NULL;
    if (key = node->key)
        return node;
    else if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

TreeNode *new_node(int item)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode *insert_node(TreeNode *node, int key)
{
    if (node == NULL)
        return new_node(key);

    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
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