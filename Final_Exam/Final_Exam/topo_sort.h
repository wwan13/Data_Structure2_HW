
#ifndef topo_sort_h
#define topo_sort_h

#include "adj_list.h"
#include "stack.h"

int topo_list(GraphType_list *g) {
    int i,w,u;
    
    StackType s;
    GraphNode *node;
    
    
    int *in_degree = (int *)malloc(sizeof(int) * g->n);
    
    for(i=0;i<g->n;i++) {
        in_degree[i] = 0;
    }
    
    for(i=0;i<g->n;i++) {
        GraphNode *node = g->adj_list[i];
        while(node != NULL) {
            in_degree[node->vertex]++;
            node = node->link;
        }
    }
    
    stack_init(&s);
    for(i=0;i<g->n;i++) {
        if(in_degree[i]==0) {
            push(&s, i);
        }
    }
    
    while (!stack_is_empty(&s)) {
        w = pop(&s);
        printf("정점 %d ->",w);
        node = g->adj_list[w];
        while (node!=NULL) {
            u = node->vertex;
            in_degree[u]--;
            if(in_degree[u]==0) {
                push(&s, u);
            }
            node = node->link;
        }
    }
    
    
    free(in_degree);
    printf("\n");
    return (i==g->n);
}


#endif /* topo_sort_h */
