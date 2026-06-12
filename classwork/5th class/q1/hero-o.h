#pragma once
#include "Data.h"

class Hero {
protected:
    Data *hp; // 指向生命值的指针
public:
    // 基类构造与析构已给出
    Hero(int h) : hp(new Data(h)) {}
    virtual ~Hero() { delete hp; }
    
    // 基类的拷贝构造，已实现深拷贝
    Hero(const Hero& other) : hp(new Data(other.hp->seek())) {}

    int getHp(void) const { return hp->seek(); }

    // TODO: 请在此处声明纯虚函数 useSkill，返回类型为 int
};
