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

int main()
{
    
}

void init(DListNode* phead)
{
    phead->llink = phead;
    phead->rlink = phead;
}

void print_dlist(DListNode* phead)
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
