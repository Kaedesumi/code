#include "Mage.h"

// TODO: 实现构造函数
// 提示：必须在初始化列表中调用基类构造函数！随后为 atk 动态分配内存
Mage::Mage(int h, int a, int m) : Hero(h),atk(new Data(a)), mana(new Data(m)) {

}

// TODO: 实现拷贝构造函数（深拷贝）
// 提示：如何调用基类的拷贝构造函数来处理基类部分的属性？
Mage::Mage(const Mage& other) : Hero(other), atk(new Data(other.atk->seek())), mana(new Data(other.atk->seek())) {

}

// TODO: 实现析构函数
Mage::~Mage() {
    delete atk;
    delete mana;
}

// TODO: 实现 useSkill()
int Mage::useSkill(void) {
    // 提示：调用 atk 内部的方法获取数值
    if (mana->seek() >= 10)
    {
        int value = mana->seek() - 10;
        delete mana;
        mana = new Data(value);
        return atk->seek() * 3;
    }else return 0;
    
}
