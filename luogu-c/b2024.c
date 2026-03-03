#include <stdio.h>

int main(void) {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;

    long long a = 0, b = 0;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            a = i;
            b = n / i;
            break;
        }
    }

    // n 是两个不同质数的乘积，必能找到因子
    long long ans = (a > b) ? a : b;
    printf("%lld\n", ans);
    return 0;
}