#pragma
#include "CreateCharacter.h"



class Mage : public CreateCharacter {

  public:

    Mage(string name, Weapon* weapon, int hp, int atk, int sta, int gold)
        : CreateCharacter(name, "Mage", weapon, hp, atk, sta, gold) {
        special_atk[0] = "Incendio";
        special_atk[1] = "Phoenix Glory";
    }

    ~Mage() override {}

    Mage& operator+= (const CreateCharacter& other) override{
      Mage result(*this);

      // Add properties from 'other' to 'result'
      result.hp += other.getHP();
      result.atk += other.getATK();
      result.sta += other.getSTA();
      result.gold += other.getGold();

      return result;

    }




    void attack() override {
        cout << name << " casts a spell with their " << weapon->getName() << "!" << endl;
    }

    void specialAbility() override {
        cout << name << " uses " << special_atk[0] << "!" << endl;
    }
};