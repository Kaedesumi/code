#include <stdio.h>
#include <stdbool.h>

#define LIM 100000

static bool isPrime[LIM + 1];

static void sieve(void) {
    for (int i = 0; i <= LIM; ++i) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; (long long)i * i <= LIM; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= LIM; j += i) isPrime[j] = false;
        }
    }
}

static int reverseInt(int x) {
    int r = 0;
    while (x > 0) {
        r = r * 10 + (x % 10);
        x /= 10;
    }
    return r;
}

int main(void) {
    int M, N;
    if (scanf("%d %d", &M, &N) != 2) return 0;

    sieve();

    int first = 1;
    for (int p = M; p <= N; ++p) {
        if (!isPrime[p]) continue;
        int rp = reverseInt(p);
        if (isPrime[rp]) {
            if (!first) putchar(',');
            printf("%d", p);
            first = 0;
        }
    }

    if (first) printf("No");
    putchar('\n');
    return 0;
}