TreeNode *search(TreeNode *node, int key)
{
    while (node != NULL)
    {
        if (key == node->key)
            return node;
        else if (key == node->key)
            node = node->left;
        else
            node = node->right;
    }
    return NULL;
}

void insert_node(TreeNode **root, int key)
{
    TreeNode *p, *t;
    TreeNode *n;

    t = *root;
    p = NULL;
    while (t != NULL)
    {
        if (key == t->key)
            return;
        p = t;
        if (key < t->key)
            t = t->left;
        else
            t = t->right;
    }

    n = (TreeNode *)malloc(sizeof(TreeNode));
    if (n == NULL)
        return;
    n->key = key;
    n->left = n->right = NULL;

    if (p != NULL)
        if (key < p->key)
            p->left = n;
        else
            p->right = n;
    else
        *root = n;
}

void *delete_node(TreeNode **root, int key)
{
    TreeNode *p, *child, *succ, *succ_p, *t;

    p = NULL;
    t = *root;

    while (t != NULL && t->key != key)
    {
        p = t;
        t = (key < t->key) ? t->left : t->right;
    }

    if (t == NULL)
    {
        printf("key is not in the tree");
        return;
    }

    //단말노드일 경우
    if ((t->left == NULL) && (t->right == NULL))
    {
        if (p != NULL)
        { //연결 끊기
            if (p->left == t)
                p->left = NULL;
            else
                p->right = NULL;
        }
        else //부모노드가 null이라면 루트를 삭제
            *root = NULL;
    }

    //하나의 서브트리를 가질 경우
    else if ((t->left == NULL) || (t->right == NULL))
    {
        child = (t->left != NULL) ? t->left : t->right; //자식 찾기
        if (p != NULL)
        {
            if (p->left == t) //부모노드를 자식노드와 연결
                p->left = child;
            else
                p->right = child;
        }
        else
            *root = child;
    }

    //두개의 서브트리를 가질 경우
    else
    {
        //오른쪽 서브트리에서 후계자를 찾음
        succ_p = t;
        succ = t->right;

        //후계자를 찾아 왼쪽으로 이동
        while (succ->left != NULL)
        {
            succ_p = succ;
            succ = succ->left;
        }

        //후계자의 부모와 자식을 연결
        if (succ_p->left == succ)
            succ_p->left = succ->right;
        else
            succ_p->right = succ->right;

        //후계자가 가진 키값을 현재노드에 보가
        t->key = succ->key;
        //후계자 삭제
        t = succ;
    }
}