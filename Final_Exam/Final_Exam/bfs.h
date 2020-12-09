
#ifndef bfs_h
#define bfs_h

#include "adj_list.h"
#include "adj_mat.h"
#include "queue.h"

int visited[MAX_VERTICE];

void bfs_mat(GraphType_mat *g, int v) {
    int w;
    QueueType q;
    
    queue_init(&q);
    visited[v] = 1;
    printf("%d 방문 ->",v);
    
    enqueue(&q, v);
    
    while (!queue_is_empty(&q)) {
        v = dequeue(&q);
        for(w=0;w<g->n;w++) {
            if(g->adj_mat[v][w] && !visited[w]) {
                visited[w] = 1;
                printf("%d 방문 -> ",w);
                enqueue(&q, w);
            }
        }
    }
}

void bfs_list(GraphType_list *g, int v) {
    GraphNode *w;
    QueueType q;
    
    queue_init(&q);
    
    visited[v] = 1;
    printf("%d 방문 -> ",v);
    
    enqueue(&q, v);
    while(!queue_is_empty(&q)) {
        v = dequeue(&q);
        for(w = g->adj_list[v];w;w=w->link) {
            if(!visited[w->vertex]) {
                visited[w->vertex] = 1;
                printf("%d 방문 -> ",w->vertex);
                enqueue(&q, w->vertex);
            }
        }
    }
}


#endif
