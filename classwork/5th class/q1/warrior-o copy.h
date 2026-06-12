#pragma once
#include "Hero.h"

// TODO: 补全类定义，使 Warrior 以 public 方式单继承自 Hero
class Warrior : public Hero {
private:
    Data *atk; // 攻击力
public:
    Warrior(int h, int a);
    Warrior(const Warrior& other);
    ~Warrior();

    // TODO: 声明重写(override)的 useSkill 函数
    int useSkill() override;
};
