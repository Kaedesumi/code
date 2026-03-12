#include <stdio.h>

#define MAXN 1000005

int next[MAXN];   // next[x] 表示 x 后面的元素

int main() {
    int q;
    scanf("%d", &q);

    next[1] = 0;   // 初始只有元素1

    while (q--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int x, y;
            scanf("%d %d", &x, &y);

            next[y] = next[x];
            next[x] = y;
        }

        else if (op == 2) {
            int x;
            scanf("%d", &x);

            printf("%d\n", next[x]);
        }

        else if (op == 3) {
            int x;
            scanf("%d", &x);

            if (next[x] != 0)
                next[x] = next[next[x]];
        }
    }

    return 0;
}