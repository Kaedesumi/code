#include <vector>
#include <iostream>
using namespace std;

struct Item{  
    int exp;  // 指数 
    int coef; // 系数 
};

// TODO: 实现 input

// TODO: 实现 output

// TODO: 实现 add

// TODO: 实现 multiply

int main() {
    vector <Item> f1,f2,f3,f4; // 4 个多项式 
    input(f1);  // 建立多项式 f1：按多项式的每一项，分别输入指数和系数，指数为负数结束  
    input(f2); 
    add(f1,f2,f3);  // 实现：f3=f1+f2  
    multiply(f1,f2,f4);   // 实现：f4=f1*f2 
    output(f3);  // 显示多项式 f3，如：2x^4+2x^3+4x^2+3x+10 
    output(f4);
}