#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];

typedef struct DListNode
{
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
}DListNode;

DListNode* current;

void init(DListNode* phead);
void print_dlist(DListNode* phead);
void dinsert(DListNode *before, element data);
void ddelete(DListNode* head, DListNode* removed);

int main()
{
    char ch;
    DListNode* head = (DListNode *)malloc(sizeof(DListNode));
    init(head);
    
    dinsert(head, "Mamamia");
    dinsert(head, "Dancing Queen");
    dinsert(head, "Fernando");
    
    current = head->rlink;
    
    print_dlist(head);
    
    do
    {
        printf("\n명령어를 입력하시오(<,>,q): ");
        ch = getchar();
        if(ch == '<')
        {
            current = current->llink;
            if(current==head)
            {
                current = current->llink;
            }
        }
        else if(ch=='>')
        {
            current = current->rlink;
            if(current==head)
            {
                current = current->rlink;
            }
        }
    }while(ch!='q');
    free(head);
}

void init(DListNode* phead)
/* 이중 연결리스트를 초기화 */
{
    phead->llink = phead;
    phead->rlink = phead;
}

void print_dlist(DListNode* phead)
/* 이중 연결리스트의 노드를 출력 */
{
    DListNode* p = NULL;
    for(p=phead->rlink;p!=phead;p=p->rlink)
    {
        if(p==current)
        {
            printf("<-| #%s# |->",p->data);
        }
        else
        {
            printf("<-| %s |->",p->data);
        }
    }
}

void dinsert(DListNode *before, element data)
/* 노드 newnode를 노드 before의 오른쪽에 삽입한다. */
{
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
    strcpy(newnode->data,data);
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed)
/* 노드 removed를 삭제한다 */
{
    if(removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->llink->llink = removed->llink;
    free(removed);
}


