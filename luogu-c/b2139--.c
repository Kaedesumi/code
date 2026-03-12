#include <stdio.h>

#define LIM 100000

// 标记数组
// 0 表示素数
// 1 表示不是素数
int biaoji[LIM + 1];


// 埃氏筛：求出 1~LIM 所有素数
void sieve() {

    // 先全部认为是素数
    for (int i = 0; i <= LIM; i++) {
        biaoji[i] = 0;
    }

    // 0 和 1 不是素数
    biaoji[0] = 1;
    biaoji[1] = 1;

    // 从 2 开始筛
    for (int i = 2; (long long)i * i <= LIM; i++) {

        // 如果 i 还是素数
        if (biaoji[i] == 0) {

            // 把 i 的倍数全部标记为合数
            for (int j = i * i; j <= LIM; j += i) {
                biaoji[j] = 1;
            }
        }
    }
}


// 计算整数的反序
// 例如 123 -> 321
int reverseInt(int x) {

    int r = 0;

    while (x > 0) {
        r = r * 10 + x % 10;
        x /= 10;
    }

    return r;
}


int main() {

    int M, N;
    scanf("%d %d", &M, &N);

    // 先筛出所有素数
    sieve();

    int first = 1;   // 用来控制是否打印逗号

    // 枚举区间 [M, N]
    for (int p = M; p <= N; p++) {

        // 如果 p 不是素数，跳过
        if (biaoji[p] == 1) continue;

        // 计算 p 的反序
        int rp = reverseInt(p);

        // 如果反序也是素数
        if (biaoji[rp] == 0) {

            // 不是第一个数时先输出逗号
            if (!first) printf(",");

            printf("%d", p);

            first = 0;
        }
    }

    // 如果一个都没输出
    if (first) {
        printf("No");
    }

    return 0;
}