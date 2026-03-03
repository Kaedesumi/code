#include <stdio.h>
#include <stdlib.h>

int **a;          // 棋盘编号
int n;            // 2^k
int tile_id = 1;  //骨牌编号

//覆盖以 (r,c) 为左上角、边长 size 的子棋盘；(sr,sc) 是该子棋盘内的“特殊方格”
void cover(int r, int c, int size, int sr, int sc) {
    if (size == 1) return;

    int mid = size / 2;

    // 四个象限中心交汇处的 4 个格子（各象限靠中心的那个格子）
    int cr_tl = r + mid - 1, cc_tl = c + mid - 1;
    int cr_tr = r + mid - 1, cc_tr = c + mid;
    int cr_bl = r + mid,     cc_bl = c + mid - 1;
    int cr_br = r + mid,     cc_br = c + mid;

    // 特殊格在哪个象限：0 TL, 1 TR, 2 BL, 3 BR
    int quad = (sr >= r + mid ? 2 : 0) + (sc >= c + mid ? 1 : 0);

    int id = tile_id++;

    // 在中心放一个 L 形骨牌：覆盖“非特殊象限”的三个中心格
    if (quad != 0) a[cr_tl][cc_tl] = id;
    if (quad != 1) a[cr_tr][cc_tr] = id;
    if (quad != 2) a[cr_bl][cc_bl] = id;
    if (quad != 3) a[cr_br][cc_br] = id;

    // 递归处理四个象限：非特殊象限把刚才放到的中心格当作它的“特殊格”
    // TL
    cover(r, c, mid,
          quad == 0 ? sr : cr_tl,
          quad == 0 ? sc : cc_tl);
    // TR
    cover(r, c + mid, mid,
          quad == 1 ? sr : cr_tr,
          quad == 1 ? sc : cc_tr);
    // BL
    cover(r + mid, c, mid,
          quad == 2 ? sr : cr_bl,
          quad == 2 ? sc : cc_bl);
    // BR
    cover(r + mid, c + mid, mid,
          quad == 3 ? sr : cr_br,
          quad == 3 ? sc : cc_br);
}

int main(void) {
    int k;
    int x, y; // 题目给的是第 x 行第 y 列（1-based）
    if (scanf("%d", &k) != 1) return 0;
    if (scanf("%d %d", &x, &y) != 2) return 0;

    n = 1 << k;
    int sr = x - 1, sc = y - 1; // 转 0-based

    a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        a[i] = (int *)calloc(n, sizeof(int)); // 默认全 0
    }
    a[sr][sc] = 0; // 特殊方格输出 0

    cover(0, 0, n, sr, sc);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j) putchar(' ');
            printf("%d", a[i][j]);
        }
        putchar('\n');
    }

    for (int i = 0; i < n; ++i) free(a[i]);
    free(a);
    return 0;
}