#include <stdio.h>
#include <string.h>

// 定义一个结构体，用来存储每个病人的信息
typedef struct {
    char id[11];   // 病人ID（长度小于10，需要1位存'\0'）
    int age;       // 病人的年龄
    int order;     // 病人登记的先后顺序（输入顺序）
} Patient;


// 比较函数：判断a是否应该排在b前面
// 返回1表示 a 在 b 前
// 返回0表示 a 不应该在 b 前（需要交换）
int before(Patient a, Patient b) {

    // 判断是否是老年人
    int a_old = (a.age >= 60);
    int b_old = (b.age >= 60);

    // 情况1：一个是老年人，一个不是
    // 老年人优先
    if (a_old != b_old)
        return a_old > b_old;

    // 情况2：两个人都是老年人
    if (a_old && b_old) {

        // 年龄大的排前面
        if (a.age != b.age)
            return a.age > b.age;

        // 年龄相同，按登记顺序
        return a.order < b.order;
    }

    // 情况3：两个人都不是老年人
    // 按登记顺序
    return a.order < b.order;
}


int main() {

    int n;
    scanf("%d", &n);   // 输入病人数量

    Patient p[105];    // 存储所有病人信息（题目说小于100）

    // 读取每个病人的信息
    for (int i = 0; i < n; i++) {

        scanf("%s %d", p[i].id, &p[i].age);

        // 记录输入顺序
        // i 就是登记顺序
        p[i].order = i;
    }


    // 冒泡排序
    // 根据 before() 的规则排序
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - 1 - i; j++) {

            // 如果 p[j] 不应该在 p[j+1] 前面
            // 就交换
            if (!before(p[j], p[j + 1])) {

                Patient temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }


    // 按顺序输出病人的ID
    for (int i = 0; i < n; i++) {
        printf("%s\n", p[i].id);
    }

    return 0;
}