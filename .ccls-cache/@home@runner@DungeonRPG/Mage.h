#pragma once
#include "CreateCharacter.h"

class Mage : public CreateCharacter {
private:
    string special_atk[2]; // Special abilities

public:
    Mage(string name, Weapon* weapon, int hp, int atk, int sta, int gold)
        : CreateCharacter(name, "Mage", weapon, hp, atk, sta, gold) {
        special_atk[0] = "Incendio";
        special_atk[1] = "Phoenix Glory";
    }

    ~Mage() {}
    void attack() override {
        cout << name << " casts a spell with their " << weapon->getName() << "!" << endl;
    }

    void specialAbility() override {
        cout << name << " uses " << special_atk[0] << "!" << endl;
    }
};