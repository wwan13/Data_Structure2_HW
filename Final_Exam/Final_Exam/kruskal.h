//
//  kruskal.h
//  Final_Exam
//
//  Created by 김태완 on 2020/12/09.
//

#ifndef kruskal_h
#define kruskal_h

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICE 100
#define INF 1000

int parent[MAX_VERTICE];

void set_init(int n) {
    int i;
    
    for(i=0;i<n;i++) {
        parent[i] = -1;
    }
}

int set_find(int curr) {
    if(parent[curr]==-1) {
        return curr;
    }
    while(parent[curr]!=-1) {
        curr = parent[curr];
    }
    return curr;
}

void set_union(int a, int b) {
    int root1 = set_find(a);
    int root2 = set_find(b);
    
    if(root1 != root2) {
        parent[root1] = root2;
    }
}

struct Edge {
    int start;
    int end;
    int weight;
};

typedef struct GraphType {
    int n;
    struct Edge edges[2*MAX_VERTICE];
}GraphType;

void graph_init(GraphType *g) {
    int i;
    g->n = 0;
    for(i=0;i<2*MAX_VERTICE;i++) {
        g->edges[i].start = 0;
        g->edges[i].end = 0;
        g->edges[i].weight = INF;
    }
}

void insert_edge(GraphType *g, int start, int end, int w) {
    g->edges[g->n].start = start;
    g->edges[g->n].end = end;
    g->edges[g->n].weight = w;
    g->n++;
}

int compare(const void *a, const void *b) {
    struct Edge* x = (struct Edge *)a;
    struct Edge* y = (struct Edge *)b;
    return (x->weight - y->weight);
}

void kruskal(GraphType *g) {
    int edge_accepted = 0;
    int uset,vset;
    struct Edge e;
    
    set_init(g->n);
    qsort(g->edges, g->n, sizeof(struct Edge), compare);
    
    printf("크루스칼 최소 신장 트리 알고리즘 \n");
    
    int i=0;
    
    while(edge_accepted < (g->n - 1)) {
        e = g->edges[i];
        uset = set_find(e.start);
        vset = set_find(e.end);
        if(uset != vset) {
            printf("간선 (%d, %d) %d 선택\n",e.start,e.end,e.weight);
            edge_accepted++;
            set_union(uset, vset);
        }
        i++;
    }
}


#endif /* kruskal_h */
