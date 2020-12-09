
#ifndef dijkstra_h
#define dijkstra_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICE 100
#define INF 1000

typedef struct GraphType {
    int n;
    int weight[MAX_VERTICE][MAX_VERTICE];
}Graphtype;

int found[MAX_VERTICE];
int distance[MAX_VERTICE];

int choose(int distance[], int n, int found[]) {
    int i,min,minpos;
    
    min = INT_MAX;
    minpos = -1;
    
    for(i=0;i<n;i++) {
        if(distance[i]<min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    }
    
    return minpos;
}

void print_status(Graphtype* g) {
    static int step = 1;
    int i;
    
    printf("STEP %d: ",step++);
    printf("distance: ");
    for(i=0;i<g->n;i++) {
        if(distance[i] == INF) {
            printf(" * ");
        }
        else {
            printf("%2d ",distance[i]);
        }
    }
    
    printf("\n");
    printf("found: ");
    
    for(i=0;i<g->n;i++) {
        printf("%2d ",found[i]);
    }
    printf("\n");
}

void shortest_path(Graphtype *g, int start) {
    int i,u,w;
    
    for(i=0;i<g->n;i++) {
        distance[i] = g->weight[start][i];
        found[i] = 0;
    }
    
    found[start] = 1;
    
    distance[start] = 0;
    
    for(i=0;i<g->n-1;i++) {
        print_status(g);
        u = choose(distance, g->n, found);
        found[u] = 1;
        for(w=0;w<g->n;w++) {
            if(!found[w]) {
                if(distance[u] + g->weight[u][w] < distance[w]) {
                    distance[w] = distance[u] + g->weight[u][w];
                }
            }
        }
    }
}


#endif /* dijkstra_h */
