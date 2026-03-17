#include <iostream>
#include "date.h"
using namespace std;
int main() {
    int y1, m1, d1, y2, m2, d2;
    // 输入第一个日期
    cin >> y1 >> m1 >> d1;
    // 输入第二个日期
    cin >> y2 >> m2 >> d2;
    // 创建两个 Date 对象
    Date date1(y1, m1, d1);
    Date date2(y2, m2, d2);
    // 显示两个日期
    date1.display();
    date2.display();
    // 计算并输出日期差
    int diff = date1.calculateDaysBetween(date2);
    cout << diff << endl;
    return 0;
}