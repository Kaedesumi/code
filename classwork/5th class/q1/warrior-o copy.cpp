#include "Warrior.h"

// TODO: 实现构造函数
// 提示：必须在初始化列表中调用基类构造函数！随后为 atk 动态分配内存
Warrior::Warrior(int h, int a) : Hero(h), atk(new Data(a)){
}

// TODO: 实现拷贝构造函数（深拷贝）
// 提示：如何调用基类的拷贝构造函数来处理基类部分的属性？
Warrior::Warrior(const Warrior& other) : Hero(other), atk(new Data(other.atk->seek())){
}

// TODO: 实现析构函数
Warrior::~Warrior() {
    delete atk;
}

// TODO: 实现 useSkill()，返回战士的攻击力数值
int Warrior::useSkill() {
    // 提示：调用 atk 内部的方法获取数值
    return atk->seek() * 2;
    return 0;
}
