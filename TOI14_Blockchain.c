/*
TASK: blockchain.c
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10000

typedef struct {
    int u;
    int v;
} Edge;

typedef Edge EdgeList[MAX_NODES];

int input() {
    int val;
    scanf("%d", &val);
    return val;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_edge(EdgeList vec, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (vec[i].u > vec[j].u || (vec[i].u == vec[j].u && vec[i].v > vec[j].v)) {
                swap(&vec[i].u, &vec[j].u);
                swap(&vec[i].v, &vec[j].v);
            }
        }
    }
}

void get_tree_graph(EdgeList vec, int *size) {
    int n = input();
    for (int i = 1; i < n; ++i) {
        int u = input();
        int v = input();
        if (u < v) {
            swap(&u, &v);
        }
        vec[*size].u = u;
        vec[*size].v = v;
        (*size)++;
    }
    sort_edge(vec, *size);
}

int main() {
    int t = input();
    int q = input();
    EdgeList trees[MAX_NODES];
    int tree_counts[MAX_NODES] = {0};

    for (int i = 0; i < t; ++i) {
        int size = 0;
        get_tree_graph(trees[i], &size);
        tree_counts[i]++;
    }

    for (int i = 0; i < q; ++i) {
        int size = 0;
        EdgeList query;
        get_tree_graph(query, &size);
        int count = 0;
        for (int j = 0; j < t; ++j) {
            if (memcmp(trees[j], query, sizeof(Edge) * size) == 0) {
                count += tree_counts[j];
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
