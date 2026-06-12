#pragma once
#include "Hero.h"

class Mage : public Hero {
private:
    Data *atk; // 法术攻击力
    Data *mana; // 魔力值

public:
    Mage(int h, int a, int m);

    Mage(const Mage& other);

    ~Mage();

    int useSkill(void) override;
};