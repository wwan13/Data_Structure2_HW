// 인접 리스트

#ifndef adj_list_h
#define adj_list_h

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICE 50

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType_list {
    int n;
    GraphNode* adj_list[MAX_VERTICE];
}GraphType_list;

// 리스트 초기화
void init(GraphType_list* g) {
    int v;
    g->n = 0;
    for(v=0;v<MAX_VERTICE;v++) {
        g->adj_list[v] = NULL;
    }
}

// 정점 삽입 연산
void insert_vertex_list(GraphType_list* g, int v) {
    if((g->n+1)>MAX_VERTICE) {
        printf("그래프 개수 초과");
        exit(1);
    }
    g->n++;
}

// 간선 삽입 연산
void insert_edge_list(GraphType_list* g, int u, int v) {
    GraphNode *node;
    
    if(u >= g->n || v >= g->n) {
        printf("그래프 정접 번호 오류");
        exit(1);
    }
    
    node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

// 인접 리스트 출력
void print_adj_list(GraphType_list *g) {
    int i;
    
    for(i=0;i<g->n;i++) {
        GraphNode *p = g->adj_list[i];
        printf("정접 %d의 인접 리스트 ",i);
        while (p!=NULL) {
            printf("-> %d",p->vertex);
            p = p->link;
        }
    }
}

#endif 
