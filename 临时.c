#include <stdio.h>
#include <string.h>

typedef struct 
{
    char name[10];
    int number;
}person;

int main(void)
{
    person zzm;
    strcpy(zzm.name,"shuaige");
    zzm.number = 123456;
    printf("%s %i",zzm.name,zzm.number);
    printf("hello\n");
    return 0;
}
