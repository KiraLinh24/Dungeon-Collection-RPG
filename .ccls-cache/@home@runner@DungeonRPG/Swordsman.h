#pragma once
#include "CreateCharacter.h"

class Swordsman : public CreateCharacter {
private:
    string special_atk[2]; // Special abilities

public:
    Swordsman(string name, Weapon* weapon, int hp, int atk, int sta, int gold)
        : CreateCharacter(name, "Swordsman", weapon, hp, atk, sta, gold) {
        special_atk[0] = "Dragon Twister";
        special_atk[1] = "Eternal Slash";
    }
    ~Swordsman() {}
    void attack() override {
        cout << name << " swings their " << weapon->getName() << " at the enemy!" << endl;
    }

    void specialAbility() override {
        cout << name << " performs a " << special_atk[0] << "!" << endl;
    }
};