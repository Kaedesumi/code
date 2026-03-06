#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef long long ll;

typedef struct Node {
    ll w;
    int id;          // tie-break
    int leaf_idx;    // >=0 if leaf, else -1
    struct Node *l, *r;
} Node;

typedef struct {
    Node **a;
    int sz, cap;
} Heap;

int less(Node *x, Node *y) {
    if (x->w != y->w) return x->w < y->w;
    return x->id < y->id;
}

void heap_init(Heap *h, int cap) {
    h->a = (Node**)malloc(sizeof(Node*) * (cap + 1));
    h->sz = 0;
    h->cap = cap;
}

static void heap_push(Heap *h, Node *x) {
    int i = ++h->sz;
    h->a[i] = x;
    while (i > 1) {
        int p = i / 2;
        if (less(h->a[p], h->a[i])) break;
        Node *tmp = h->a[p]; h->a[p] = h->a[i]; h->a[i] = tmp;
        i = p;
    }
}

