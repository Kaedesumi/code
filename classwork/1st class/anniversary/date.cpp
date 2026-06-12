#include "date.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
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
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year))
    {
        return false;
    }
    else
    {
        return true;
    }
    
}

// 判断是否是闰年
bool Date::isLeapYear(int y) const {
    //TODO
    if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

// 返回该月的天数
int Date::daysInMonth(int m, int y) const {
    //TODO
    //错误返回0
    if ((isLeapYear(y) == true) && (m == 2))
    {
        return 29;
    }
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        return 31;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        return 30;
    }
    if ((isLeapYear(y) == false) && (m == 2))
    {
        return 28;
    }
}

// 计算从公元1年1月1日到当前日期的天数
int Date::daysSinceEpoch() const {
    if (!isValidDate()) return -1;
    int totalDays = 0;
    // TODO: 计算当前年份中到当前日期的天数
    for (int i = 1; i < year; i++)
        {
            if (isLeapYear(i) == true)
                {
                    totalDays += 366;
                }
                else{
                    totalDays += 365;
                }
            
        }
    for (int i = 1; i < month; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
        {
            totalDays += 31;
        }
        if (i == 4 || i == 6 || i == 9 || i == 11)
        {
            totalDays += 30;
        }
        if (i == 2 && isLeapYear(year) == true)
        {
            totalDays += 29;
        }
        if (i == 2 && isLeapYear(year) != true)
        {
            totalDays += 28;
        }
        
    }
    for (int i = 1; i < day; i++)
    {
        totalDays += 1;
    }

    
    
    
    
    
    return totalDays;
    //如果非法，返回-1
}

// 计算从某个日期到另一个日期的天数差
int Date::calculateDaysBetween(const Date &other) const {
    //TODO
    //如果任意一个日期非法，返回-1

    if (other.isValidDate() == false || isValidDate() == false)
    {
        return -1;
    }

    return abs(daysSinceEpoch() - other.daysSinceEpoch());
    
}

// 显示日期
void Date::display() const {
    //TODO：按照yyyy-mm-dd格式输出,加一个换行
    //
    if(isValidDate() == false){
        cout<<"-1"<< endl;
    }
    else{
        cout<< setw(4) << setfill('0') << year << "-"
        << setw(2) << setfill('0') << month << "-"
        << setw(2) << setfill('0') << day
        << endl;
    }
    
    //如：cout<<2025-02-17<<endl;
    
    //如果非法，输出-1
}
