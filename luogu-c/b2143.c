#include <stdio.h>

void print_base_rec(unsigned int x, unsigned int m) {
    static const char digits[] = "0123456789ABCDEF";
    if (x >= m) print_base_rec(x / m, m);
    putchar(digits[x % m]);
}

int main(void) {
    unsigned int X, M;
    if (scanf("%u %u", &X, &M) != 2) return 0;
    print_base_rec(X, M);
    return 0;
}