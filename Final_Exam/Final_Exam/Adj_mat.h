// 인접 행렬

#ifndef adj_mat_h
#define adj_mat_h

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICE 50

typedef struct GraphType_mat {
    int n;
    int adj_mat[MAX_VERTICE][MAX_VERTICE];
}GraphType_mat;

// 그래프 초기화
void init_mat(GraphType_mat* g) {
    int r,c;
    g->n = 0;
    for(r=0;r<MAX_VERTICE;r++) {
        for(c=0;c<MAX_VERTICE;c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}

// 정접 삽입
void insert_vertex_mat(GraphType_mat* g, int v) {
    if((g->n+1)>MAX_VERTICE) {
        printf("그래프 개수 초과");
        exit(1);
    }
    g->n++;
}

// 간선 삽입 연산
void insert_edge_mat(GraphType_mat* g, int start, int end) {
    if(start >= g->n || end >= g->n) {
        printf("그래프 정접 번호 오류");
        exit(1);
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

// 인접 행렬 출력
void print_adj_mat(GraphType_mat* g) {
    int i,j;
    for(i=0;i<MAX_VERTICE;i++) {
        for(j=0;j<MAX_VERTICE;j++) {
            printf("%2d ",g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

#endif
