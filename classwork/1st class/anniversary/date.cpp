#include "date.h"
#include <iostream>
using namespace std;

// 构造函数
Date::Date(int y, int m, int d) : year(y), month(m), day(d) {
    if (!isValidDate()) {
        cout << -1 << endl;
        return;
        //不需修改，我们希望看到某些异常日期测试用例对应的“-1”输出
    }
}

// 判断日期是否合法
bool Date::isValidDate() const {
    if (year <= 0) return false;
    if (month < 1 || month > 12) return false;

    int days = daysInMonth(month, year);
    if (day < 1 || day > days) return false;

    return true;
    //这个函数需要被其他函数使用
    //未到日期也属于正常输入
}

// 判断是否是闰年
bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// 返回该月的天数
int Date::daysInMonth(int m, int y) const {
    if (m < 1 || m > 12) return 0;
    if (m == 2) {
        return isLeapYear(y) ? 29 : 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    return 31;
    //错误返回0
}

// 计算从公元1年1月1日到当前日期的天数
int Date::daysSinceEpoch() const {
    if (!isValidDate()) return -1;
    int totalDays = 0;
    // TODO: 计算当前年份中到当前日期的天数
    for (int y = 1; y < year; ++y) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < month; ++m) {
        totalDays += daysInMonth(m, year);
    }
    // 3. 加上当前月的天数
    totalDays += day - 1;
    return totalDays;
    //如果非法，返回-1
}

// 计算从某个日期到另一个日期的天数差
int Date::calculateDaysBetween(const Date &other) const {
    if (!isValidDate() || !other.isValidDate()) return -1;
    //如果任意一个日期非法，返回-1
    int d1 = daysSinceEpoch();
    int d2 = other.daysSinceEpoch();
    return d1 > d2 ? (d1 - d2) : (d2 - d1);
}

// 显示日期
void Date::display() const {
    //TODO：按照yyyy-mm-dd格式输出,加一个换行
    if (!isValidDate()) {
        cout << -1 << endl;
        return;
    }
    if (year < 10) cout << "000";
    else if (year < 100) cout << "00";
    else if (year < 1000) cout << "0";
    cout << year << "-";
    if (month < 10) cout << "0";
    cout << month << "-";
    if (day < 10) cout << "0";
    cout << day << endl;
    //如：cout<<2025-02-17<<endl;
    //如果非法，输出-1
}
