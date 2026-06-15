// BooleanString.cpp
#include <cstring>
#include "BooleanString.h"

BooleanString::BooleanString(){
    len = 0;
    str_p = new char[1];
    str_p[0] = '\0';
};

BooleanString::BooleanString(const BooleanString &s){
    len = s.len;

    str_p = new char[len + 1];

    strcpy(str_p, s.str_p);
}

//==================辅助函数================
bool isBooleanStr(const char *s)
{
    if (s == nullptr)
    {
        return false;
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != '0' && s[i] != '1')
        {
            return false;
        }
    }

    return true;
}


BooleanString::~BooleanString(){
    delete[] str_p;
    str_p = nullptr;
}


// 输出字符串，最后输出换行符
void BooleanString::print(){
    cout << str_p << endl;
};




BooleanString::BooleanString(const char *s){
    if (!isBooleanStr(s))
    {
        len = 0;
        str_p = new char[1];
        str_p[0] = '\0';
        return;
    }
    
    len = strlen(s);
    str_p = new char[len + 1];
    strcpy(str_p, s);
}



BooleanString& BooleanString::operator=(const BooleanString &s)
{
    if (this == &s)
    {
        return *this;
    }

    delete[] str_p;

    len = s.len;

    str_p = new char[len + 1];

    strcpy(str_p, s.str_p);

    return *this;
}

BooleanString& BooleanString::operator=(const char* s)
{
    if (!isBooleanStr(s))
    {
        return *this;
    }

    delete[] str_p;

    len = strlen(s);

    str_p = new char[len + 1];

    strcpy(str_p, s);

    return *this;
}



char& BooleanString::operator[](int index)
{
    return str_p[index];
}




//============拼接=============
BooleanString BooleanString::operator+(const BooleanString &A)
{
    int newLen = len + A.len;

    char *temp = new char[newLen + 1];

    strcpy(temp, str_p);

    strcat(temp, A.str_p);

    BooleanString result(temp);

    delete[] temp;

    return result;
}




bool BooleanString::operator==(const BooleanString &A)
{
    return strcmp(str_p, A.str_p) == 0;
}


bool BooleanString::operator<(const BooleanString &A)
{
    return strcmp(str_p, A.str_p) < 0;
}

//============按位取反================
BooleanString BooleanString::operator!()
{
    char *temp = new char[len + 1];

    for (int i = 0; i < len; i++)
    {
        temp[i] = (str_p[i] == '1') ? '0' : '1';
    }

    temp[len] = '\0';

    BooleanString result(temp);

    delete[] temp;

    return result;
}



//=========与=========
BooleanString BooleanString::operator&(const BooleanString &A)
{
    int maxLen = (len > A.len) ? len : A.len;

    char *temp = new char[maxLen + 1];

    for (int i = 0; i < maxLen; i++)
    {
        char x = (i < len) ? str_p[i] : '0';
        char y = (i < A.len) ? A.str_p[i] : '0';

        temp[i] = (x == '1' && y == '1') ? '1' : '0';
    }

    temp[maxLen] = '\0';

    BooleanString result(temp);

    delete[] temp;

    return result;
}





//==============或============
BooleanString BooleanString::operator|(const BooleanString &A)
{
    int maxLen = (len > A.len) ? len : A.len;

    char *temp = new char[maxLen + 1];

    for (int i = 0; i < maxLen; i++)
    {
        char x = (i < len) ? str_p[i] : '0';
        char y = (i < A.len) ? A.str_p[i] : '0';

        temp[i] = (x == '1' || y == '1') ? '1' : '0';
    }

    temp[maxLen] = '\0';

    BooleanString result(temp);

    delete[] temp;

    return result;
}

