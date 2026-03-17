#include "date.h"
#include <iostream>
using namespace std;

// 构造函数
Date::Date(int y, int m, int d) : year(y), month(m), day(d) {
    if (!isValidDate()) {
        //不需修改，我们希望看到某些异常日期测试用例对应的“-1”输出
    }
}

// 判断日期是否合法
bool Date::isValidDate() const {
    //TODO
    //这个函数需要被其他函数使用
    //未到日期也属于正常输入
}

// 判断是否是闰年
bool Date::isLeapYear(int y) const {
    //TODO
}

// 返回该月的天数
int Date::daysInMonth(int m, int y) const {
    //TODO
    //错误返回0
}

// 计算从公元1年1月1日到当前日期的天数
int Date::daysSinceEpoch() const {
    int totalDays = 0;
    // TODO: 计算当前年份中到当前日期的天数
    
    return totalDays;
    //如果非法，返回-1
}

// 计算从某个日期到另一个日期的天数差
int Date::calculateDaysBetween(const Date &other) const {
    //TODO
    //如果任意一个日期非法，返回-1
}

// 显示日期
void Date::display() const {
    //TODO：按照yyyy-mm-dd格式输出,加一个换行
    //
    //如：cout<<2025-02-17<<endl;
    
    //如果非法，输出-1
}
