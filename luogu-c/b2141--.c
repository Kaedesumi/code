#include <stdio.h>

/*
作用：
把一个“按十进制形式写出的数 x”当作 B 进制数解析，
并转换成真正的十进制值。

例如：
x = 42, B = 13
表示 42(13) = 4*13 + 2 = 54

返回值：
如果某一位数字 >= B（不合法），返回 -1
否则返回转换后的十进制值
*/
long long parse(long long x, int B) {

    // 如果 x 为 0，直接返回
    if (x == 0) return 0;

    // 用数组存储每一位数字
    int digits[20];
    int len = 0;

    /*
    先把数字拆成每一位
    例如：
    x = 123
    digits = {3,2,1}
    */
    while (x > 0) {
        digits[len++] = x % 10; // 取最后一位
        x /= 10;                // 去掉最后一位
    }

    long long val = 0;

    /*
    从最高位开始计算 B 进制的值

    例如 digits = {3,2,1}
    实际数字 = 123

    计算过程：
    val = 0
    val = 0*B + 1
    val = 1*B + 2
    val = (1B+2)*B + 3
    */
    for (int i = len - 1; i >= 0; --i) {

        // 如果某一位 >= B，说明这个数在 B 进制下不合法
        if (digits[i] >= B) return -1;

        // 按 B 进制展开
        val = val * B + digits[i];
    }

    return val;
}


/*
作用：
求一个数字可能的最小进制

原理：
一个进制必须大于所有数字位

例如：
x = 42
最大数字 = 4
所以最小进制 = 5

但题目要求最小进制 >= 2
*/
int minBase(long long x) {

    int mx = 0;

    // 如果 x 是 0，最小进制按 2 处理
    if (x == 0) return 2;

    // 找最大数位
    while (x > 0) {

        int d = x % 10;   // 当前最低位

        if (d > mx)       // 更新最大数字
            mx = d;

        x /= 10;
    }

    /*
    进制必须 > 最大数位

    mx + 1 是理论最小进制
    但进制至少为 2
    */
    return mx + 1 > 2 ? mx + 1 : 2;
}


int main() {

    long long p, q, r;

    // 输入三个数
    scanf("%lld %lld %lld", &p, &q, &r);

    /*
    找三个数允许的最小进制

    例如：
    p = 42
    q = 9
    r = 378

    start 必须 >= 三个数各自的最小进制
    */

    int start = minBase(p);

    int t = minBase(q);
    if (t > start) start = t;

    t = minBase(r);
    if (t > start) start = t;


    /*
    枚举所有可能进制
    B ∈ [start , 16]
    */

    for (int B = start; B <= 16; B++) {

        // 把三个数按 B 进制解析为十进制
        long long pv = parse(p, B);
        long long qv = parse(q, B);
        long long rv = parse(r, B);

        /*
        判断是否满足
        p × q = r
        */

        if (pv * qv == rv) {

            // 找到合法进制
            printf("%d", B);

            return 0;
        }
    }

    // 如果没有任何进制满足
    printf("0");

    return 0;
}