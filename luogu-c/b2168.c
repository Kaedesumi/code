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

/* ---------- Min Heap of Node* ---------- */
typedef struct {
    Node **a;
    int sz, cap;
} Heap;

static int less(Node *x, Node *y) {
    if (x->w != y->w) return x->w < y->w;
    return x->id < y->id;
}

static void heap_init(Heap *h, int cap) {
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

static Node* heap_pop(Heap *h) {
    Node *ret = h->a[1];
    h->a[1] = h->a[h->sz--];
    int i = 1;
    while (1) {
        int l = i * 2, r = l + 1, m = i;
        if (l <= h->sz && less(h->a[l], h->a[m])) m = l;
        if (r <= h->sz && less(h->a[r], h->a[m])) m = r;
        if (m == i) break;
        Node *tmp = h->a[i]; h->a[i] = h->a[m]; h->a[m] = tmp;
        i = m;
    }
    return ret;
}

/* ---------- Huffman DFS to generate codes ---------- */
static char* my_strdup(const char *s) {
    size_t n = strlen(s);
    char *p = (char*)malloc(n + 1);
    memcpy(p, s, n + 1);
    return p;
}

static void dfs(Node *u, char *path, int dep, char **codes, int n) {
    if (!u) return;
    if (u->leaf_idx >= 0) {
        if (n == 1) {                // only one symbol: give it "0"
            codes[u->leaf_idx] = my_strdup("0");
        } else {
            path[dep] = '\0';
            codes[u->leaf_idx] = my_strdup(path);
        }
        return;
    }
    path[dep] = '0';
    dfs(u->l, path, dep + 1, codes, n);
    path[dep] = '1';
    dfs(u->r, path, dep + 1, codes, n);
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char **words = (char**)malloc(sizeof(char*) * n);
    ll *w = (ll*)malloc(sizeof(ll) * n);
    char buf[64];

    for (int i = 0; i < n; ++i) {
        scanf("%s %lld", buf, &w[i]);
        words[i] = my_strdup(buf);
    }

    // node pool: at most 2n-1 nodes
    Node *pool = (Node*)malloc(sizeof(Node) * (2 * n));
    int pcnt = 0, next_id = 0;

    Heap hp;
    heap_init(&hp, 2 * n + 5);

    for (int i = 0; i < n; ++i) {
        Node *nd = &pool[pcnt++];
        nd->w = w[i];
        nd->id = next_id++;
        nd->leaf_idx = i;
        nd->l = nd->r = NULL;
        heap_push(&hp, nd);
    }

    // build Huffman tree
    while (hp.sz > 1) {
        Node *a = heap_pop(&hp);
        Node *b = heap_pop(&hp);
        Node *p = &pool[pcnt++];
        p->w = a->w + b->w;
        p->id = next_id++;
        p->leaf_idx = -1;
        p->l = a;     // left -> '0'
        p->r = b;     // right -> '1'
        heap_push(&hp, p);
    }

    Node *root = heap_pop(&hp);

    char **codes = (char**)calloc(n, sizeof(char*));
    char path[2048];
    dfs(root, path, 0, codes, n);

    for (int i = 0; i < n; ++i) {
        printf("%s %s\n", words[i], codes[i]);
    }

    // free
    for (int i = 0; i < n; ++i) {
        free(words[i]);
        free(codes[i]);
    }
    free(words);
    free(codes);
    free(w);
    free(pool);
    free(hp.a);
    return 0;
}
