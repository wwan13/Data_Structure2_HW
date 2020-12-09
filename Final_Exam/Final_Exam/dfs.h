

#ifndef dfs_h
#define dfs_h

#include <stdio.h>

#include "adj_list.h"
#include "adj_mat.h"

int visited[MAX_VERTICE];

void dfs_mat(GraphType_mat* g, int v) {
    int w;
    visited[v] = 1;
    printf("정점 %d ->",v);
    
    for(w=0;w<g->n;w++) {
        if(g->adj_mat[v][w] && !visited[w]) {
            dfs_mat(g, w);
        }
    }
}

void dfs_list(GraphType_list *g, int v) {
    GraphNode* w;
    visited[v] = 1;
    printf("정점 %d ->",v);
    
    for(w=g->adj_list[v];w;w=w->link) {
        if(!visited[w->vertex]) {
            dfs_list(g, w->vertex);
        }
    }
}

// void dfs_iterative

#endif 
