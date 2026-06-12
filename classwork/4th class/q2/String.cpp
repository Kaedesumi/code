// String.cpp


// TODO: 实现 String 的各个成员函数

#include "String.h"
#include <cstring>
#include <iostream>

String::String() {
    len = 0;
    str_p = new char[1];
    str_p[0] = '\0';
}

String::String(const char *s) {
    len = strlen(s);
    str_p = new char[len + 1];
    strcpy(str_p, s);
}

String::String(const String &s) {
    len = s.len;
    str_p = new char[len + 1];
    strcpy(str_p, s.str_p);
}

String::~String() {
    delete[] str_p;
    str_p = nullptr;
    len = 0;
}

void String::print() {
    cout << str_p << endl;
}







String& String::operator=(const String &s) {
    if (this == &s) {
        return *this;
    }

    delete[] str_p;

    len = s.len;
    str_p = new char[len + 1];
    strcpy(str_p, s.str_p);

    return *this;
}

String& String::operator=(const char *s) {
    delete[] str_p;

    len = strlen(s);
    str_p = new char[len + 1];
    strcpy(str_p, s);

    return *this;
}









char& String::operator[](int index)
{
    return str_p[index];
}





String String::operator+(const String &s)
{
    char *temp = new char[len + s.len + 1];

    strcpy(temp, str_p);
    strcat(temp, s.str_p);

    String result(temp);

    delete[] temp;

    return result;
}



bool String::operator==(const String &s) {
    return strcmp(str_p, s.str_p) == 0;
}

bool String::operator!=(const String &s) {
    return strcmp(str_p, s.str_p) != 0;
}

bool String::operator<(const String &s) {
    return strcmp(str_p, s.str_p) < 0;
}