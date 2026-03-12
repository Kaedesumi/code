#include <stdio.h>
#include <string.h>

#define MAXN 1000005   // 单个字符串最大长度 1e6，留一点余量

char s[MAXN];          // 用来存输入的括号串
char stack_[MAXN];     // 用数组模拟栈，保存左括号

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        // 读入一个只含括号的字符串
        scanf("%s", s);

        int top = -1;      // 栈顶指针，-1 表示空栈
        int ok = 1;        // 标记当前字符串是否合法，1 表示合法，0 表示不合法

        // 逐个字符扫描字符串
        for (int i = 0; s[i] != '\0'; i++) {
            char ch = s[i];

            // 1. 如果是左括号，直接入栈
            if (ch == '(' || ch == '[' || ch == '{') {
                stack_[++top] = ch;
            }
            // 2. 如果是右括号，则必须和栈顶左括号匹配
            else {
                // 如果此时栈为空，说明没有左括号可以匹配
                if (top == -1) {
                    ok = 0;
                    break;
                }

                // 取出当前栈顶元素，但先不急着弹栈
                char t = stack_[top];

                // 判断是否匹配
                if ((ch == ')' && t == '(') ||
                    (ch == ']' && t == '[') ||
                    (ch == '}' && t == '{')) {
                    // 匹配成功，弹栈
                    top--;
                } else {
                    // 类型不匹配，例如 "(]"、"{)"
                    ok = 0;
                    break;
                }
            }
        }

        // 如果前面没出错，但最后栈不空，说明还有左括号没配对
        if (ok && top == -1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}