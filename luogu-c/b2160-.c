#include <stdio.h>

//结构体
typedef struct{
    char id[11];
    int age;
    int time;
}Patient;

//比较函数
//返回1表示A在前，0表示B在前
int compare(Patient A,Patient B){
    //如果都是老人
    if (A.age >= 60 && B.age >= 60)
    {
        //比较年龄，如果不一样
        if (A.age != B.age)
        {
            return (A.age > B.age);
        }
        //如果年龄一样，比较时间
        if (A.age == B.age)
        {
            return A.time < B.time;
        }
    }
    //如果一个是老人一个不是
    if (A.age >= 60 && B.age < 60)
    {
        return 1;
    }
    if (A.age < 60 && B.age >= 60)
    {
        return 0;
    }
    //如果都不是老人
    if (A.age < 60 && B.age < 60)
    {
        return A.time < B.time;
    }
    return 0;
}

int main(){
    //输入
    int n;
    scanf("%d",&n);

    //开结构体数组
    Patient p[105];
    for (int i = 0; i < n; i++)
    {
        scanf("%s",p[i].id);
        p[i].time = i;
        scanf("%d",&p[i].age);
    }

    //冒泡排序
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            //如果不应该在前面就交换
            if (!compare(p[j],p[j +1]))
            {
                Patient temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }  
        }
    }
    //按顺序输出
    for (int i = 0; i < n; i++)
    {
        printf("%s\n",p[i].id);
    }
    return 0;
    
}