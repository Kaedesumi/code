#include <stdio.h>

long long parse(long long x, int B) {
    if (x == 0) return 0;

    int digits[20];
    int len = 0;

    while (x > 0) {
        digits[len++] = x % 10;
        x /= 10;
    }

    long long val = 0;

    for (int i = len - 1; i >= 0; --i) {
        if (digits[i] >= B) return -1;
        val = val * B + digits[i];
    }

    return val;
}

int minBase(long long x) {
    int mx = 0;
    if (x == 0) return 2;

    while (x > 0) {
        int d = x % 10;
        if (d > mx) mx = d;
        x /= 10;
    }
    return mx + 1 > 2 ? mx + 1 : 2;
}

int main() {
    long long p, q, r;
    scanf("%lld %lld %lld", &p, &q, &r);

    int start = minBase(p);
    int t = minBase(q);
    if (t > start) start = t;
    t = minBase(r);
    if (t > start) start = t;

    for (int B = start; B <= 16; B++) {
        long long pv = parse(p, B);
        long long qv = parse(q, B);
        long long rv = parse(r, B);

        if (pv * qv == rv) {
            printf("%d", B);
            return 0;
        }
    }

    printf("0");
    return 0;
}