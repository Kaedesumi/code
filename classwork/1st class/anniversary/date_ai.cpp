#include "date.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// 构造函数
Date::Date(int y, int m, int d) : year(y), month(m), day(d) {
    if (!isValidDate()) {
        //不需修改，我们希望看到某些异常日期测试用例对应的“-1”输出
    }
}

// 判断日期是否合法
bool Date::isValidDate() const {
    if (year < 1) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > daysInMonth(month, year)) return false;
    return true;
}

// 判断是否是闰年
bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// 返回该月的天数
int Date::daysInMonth(int m, int y) const {
    if (m < 1 || m > 12) return 0;

    if (m == 2) {
        if (isLeapYear(y)) return 29;
        else return 28;
    }

    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }

    return 31;
}

// 计算从公元1年1月1日到当前日期的天数
int Date::daysSinceEpoch() const {
    if (!isValidDate()) return -1;

    int totalDays = 0;

    // 累加之前所有完整年份的天数
    for (int y = 1; y < year; y++) {
        if (isLeapYear(y)) totalDays += 366;
        else totalDays += 365;
    }

    // 累加当前年份之前所有完整月份的天数
    for (int m = 1; m < month; m++) {
        totalDays += daysInMonth(m, year);
    }

    // 当前月已经过去的天数
    totalDays += (day - 1);

    return totalDays;
}

// 计算从某个日期到另一个日期的天数差
int Date::calculateDaysBetween(const Date &other) const {

    if (!isValidDate() || !other.isValidDate()) return -1;

    int d1 = daysSinceEpoch();
    int d2 = other.daysSinceEpoch();

    return abs(d1 - d2);
}

// 显示日期
void Date::display() const {

    if (!isValidDate()) {
        cout << -1 << endl;
        return;
    }

    cout << year << "-"
         << setw(2) << setfill('0') << month << "-"
         << setw(2) << setfill('0') << day
         << endl;
}