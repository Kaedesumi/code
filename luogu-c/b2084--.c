
#include <stdio.h>

int main(){
    long long n;
    scanf("%lld",&n);

    long long a = 0, b= 0;
    for(long long i = 2; i * i <= n; i++){
        if( n % i == 0){
            a = i;
            b = n/i;
            break;
        }
    }
     long long ans = (a>b)?a:b;
     printf("%lld\n",ans);
     return 0;

}