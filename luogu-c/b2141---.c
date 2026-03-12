#include <stdio.h>

int min_base = 0;


//输入数和进制base，以base进制解析该数并转换为10进制
long long convert_to_10(long long N,int base){
    int number[20] = {0};
    int length = 0;
    while (N > 0)
    {
        number[length++] = N%10;
        N /= 10;
    }//如此一来123，则number中会储存321
    //接下来转化为10进制
    long long output = 0;
    for (int i = length-1; i >= 0; i--)
    {
        output = output * base + number[i];
    }
    return output;
}

//得到最小进制

void get_min_base(long long M){
    int number[20] = {0};
    int length = 0;
    while (M > 0)
    {
        number[length++] = M%10;
        M /= 10;
    }//如此一来123，则number中会储存321
    //挨个比较
    for (int i = 0; i < length; i++)
    {
        if (number[i] > min_base)
        {
            min_base = number[i];
        }
    }
}

int main(){
    //输入
    int res = 0;
    long long p,q,r;
    scanf("%lld%lld%lld",&p,&q,&r);
    //先得到最小进制
    get_min_base(p);
    get_min_base(q);
    get_min_base(r);

    min_base++;
    //从最小合适进制开始到16进制
    if (min_base <= 16)
    {
        for (int i = min_base; i <= 16; i++)
        {
            //pqr以i进制转化为16进制是否满足提议
            if (convert_to_10(p,i) * convert_to_10(q,i) == convert_to_10(r,i))
            {
                res = i;
                break;
            }
        }
    }
    printf("%d",res);
    return 0;
}