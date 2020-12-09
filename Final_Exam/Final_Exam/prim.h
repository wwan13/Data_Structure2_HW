

#ifndef prim_h
#define prim_h

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICE 100
#define INF 1000

typedef struct GraphType {
    int n;
    int weight[MAX_VERTICE][MAX_VERTICE];
}Graphtype;

int selected[MAX_VERTICE];
int distance[MAX_VERTICE];

int get_min_vertex(int n) {
    int v=0,i=0;
    
    for(i=0;i<n;i++) {
        if(!selected[i]) {
            v=i;
            break;
        }
    }
    for(i=0;i<n;i++) {
        if(!selected[i] && (distance[i]<distance[v])) {
            v=i;
        }
    }
    return v;
}

void prim(Graphtype *g,int s) {
    int i,u, v;
    
    for(u=0;u<g->n;u++) {
        distance[u] = INF;
    }
    distance[s] = 0;
    for(i=0;i<g->n;i++) {
        u = get_min_vertex(g->n);
        selected[u] = 1;
        if(distance[u]==INF) {
            return;
        }
        printf("정점 %d 추가\n",u);
        for(v=0;v<g->n;v++) {
            if(g->weight[u][v]!=INF) {
                if(!selected[v] && g->weight[u][v] < distance[v]) {
                    distance[v] = g->weight[u][v];
                }
            }
        }
    }
}


#endif /* prim_h */
