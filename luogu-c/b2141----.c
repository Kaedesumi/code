#include <stdio.h>

int min_base = 0;

// 输入数和进制 base，以 base 进制解析该数并转换为 10 进制
// 如果某一位不合法，则返回 -1
long long convert_to_10(long long N, int base) {
    int number[20] = {0};
    int length = 0;

    if (N == 0) return 0;

    while (N > 0) {
        number[length++] = N % 10;
        N /= 10;
    }

    long long output = 0;
    for (int i = length - 1; i >= 0; i--) {
        if (number[i] >= base) return -1;   // 非法数位
        output = output * base + number[i];
    }
    return output;
}

// 找出所有数位中的最大值
void get_min_base(long long M) {
    if (M == 0) return;

    while (M > 0) {
        int digit = M % 10;
        if (digit > min_base) {
            min_base = digit;
        }
        M /= 10;
    }
}

int main() {
    int res = 0;
    long long p, q, r;
    scanf("%lld%lld%lld", &p, &q, &r);

    get_min_base(p);
    get_min_base(q);
    get_min_base(r);

    // 最小合法进制 = 最大数位 + 1，且至少为 2
    min_base++;
    if (min_base < 2) min_base = 2;

    if (min_base <= 16) {
        for (int i = min_base; i <= 16; i++) {
            long long pv = convert_to_10(p, i);
            long long qv = convert_to_10(q, i);
            long long rv = convert_to_10(r, i);

            // 只要有一个数在该进制下非法，就跳过
            if (pv == -1 || qv == -1 || rv == -1) {
                continue;
            }

            if (pv * qv == rv) {
                res = i;
                break;
            }
        }
    }

    printf("%d", res);
    return 0;
}