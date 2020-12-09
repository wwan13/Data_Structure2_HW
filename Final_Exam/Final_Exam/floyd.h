

#ifndef floyd_h
#define floyd_h

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICE 100
#define INF 1000

typedef struct GraphType {
    int n;
    int weight[MAX_VERTICE][MAX_VERTICE];
}Graphtype;

int A[MAX_VERTICE][MAX_VERTICE];

void printA(Graphtype *g) {
    int i,j;
    printf("========================\n");
    for(i=0;i<g->n;i++) {
        for(j=0;j<g->n;j++) {
            if(A[i][j]==INF) {
                printf(" * ");
            }
            else {
                printf("%3d ",A[i][j]);
            }
        }
        printf("\n");
    }
    printf("========================\n");
}

void floyd(Graphtype *g) {
    int i,j,k;
    
    for(i=0;i<g->n;i++) {
        for(j=0;j<g->n;j++) {
            A[i][j] = g->weight[i][j];
        }
    }
    printA(g);
    
    for(k=0;k<g->n;k++) {
        for(i=0;i<g->n;g++) {
            for(j=0;j<g->n;j++) {
                if(A[i][k] + A[k][j] < A[i][j]) {
                    A[i][j] = A[i][j] + A[k][j];
                }
            }
        }
        printA(g);
    }
}


#endif
