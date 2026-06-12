#pragma once
#include "Hero.h"

// TODO: 补全类定义，使 Mage 以 public 方式单继承自 Hero
class Mage {
private:
    Data *atk; // 法术攻击力
    Data *mana; // 魔力值
public:
    Mage(int h, int a, int m);
    Mage(const Mage& other);
    ~Mage();

    // TODO: 声明重写(override)的 useSkill 函数
};
