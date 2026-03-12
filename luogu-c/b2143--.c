//157转12进制
//得到13余1
//得到1余1

#include <stdio.h>

const char digits[] = "0123456789ABCDEF";

void print_(long long N,int M){
    if (N >= M)print_(N / M,M);
    putchar(digits[N%M]);
}

int main(){
    long long X;
    int M;
    scanf("%lld%d",&X,&M);
    print_(X,M);
    return 0;
}