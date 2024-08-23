#pragma once
#include "CreateCharacter.h"

class Marksman : public CreateCharacter {
private:
    string special_atk[2]; // Special abilities

public:
    Marksman(string name, Weapon* weapon, int hp, int atk, int sta, int gold)
        : CreateCharacter(name, "Marksman", weapon, hp, atk, sta, gold) {
        special_atk[0] = "Meteor Shower";
        special_atk[1] = "Hell Rain";
    }
    ~Marksman () {}
    void attack() override {
        cout << name << " takes aim with their " << weapon->getName() << "!" << endl;
    }

    void specialAbility() override {
        cout << name << " executes a " << special_atk[0] << "!" << endl;
    }
};