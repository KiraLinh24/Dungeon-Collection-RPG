#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib> 
#include <string>
using namespace std;

class Weapon {
  protected:
      string name;
      int boost1;
      int boost2;
      int effect;
  public:
      Weapon(const string& name, int boost1, int boost2, int effect) : name(name), boost1(boost1), boost2(boost2), effect(effect){} //overload constructor take four parameters
      ~Weapon() {} //destructor method

      
      string getName() {return name; }
      int getBoost1() {return boost1; } //boost the attack power
      int getBoost2() {return boost2; } //boost the health
      int getEffect() {return effect; } //deduct the stamina

      int setBoost1(int boost){ return this->boost1 += boost; } //add-on the boost whenever it got call
      
};

//base class
class CreateCharacter{ 
  protected:
    string name;
    string classes;
    string special_atk[2];
    Weapon* weapon;
    int hp;
    int atk;
    int sta;
    int gold;

  public:
    CreateCharacter() : name(""), classes(""), weapon(nullptr), hp(0), atk(0), sta(0), gold(0) {} //default constructor
    CreateCharacter(string _name, string _class, Weapon* weapon, int _hp, int _atk, int _sta, int _coin) : name(_name), classes(_class), weapon(weapon), hp(_hp), atk(_atk), sta(_sta), gold(_coin) {} //overload constructor take seven parameters
    virtual ~CreateCharacter() {} //destructor method

    //get the player's stats
    string getName() { return name; }
    string getClass() {return classes; }
    int getHP() { return hp; }
    int getATK() { return atk; }
    int getSTA() { return sta; }
    int getGold() { return gold; }
    string getSpecialAbility1() { return special_atk[0]; }
    string getSpecialAbility2() { return special_atk[1]; }

    //add on to character's stats
    int addHP(int hp) { return this->hp += hp; }
    int addATK(int atk) { return this->atk += atk; }
    int addSTA(int sta) { return this->sta += sta; }
    int addGold(int gold) { return this->gold += gold; }
    //take away from character's stats
    int deductHP(int hp) { return this->hp -= hp; }
    int deductATK(int atk) { return this->atk -= atk; }
    int deductSTA(int sta) { return this->sta -= sta; }
    int deductGold(int gold) { return this->gold -= gold; }


    //create a new method for weapon
    string getWeaponName() { return weapon->getName();}
    int getWeaponBoost1() { return weapon->getBoost1();}
    int getWeaponBoost2() { return weapon->getBoost2();}
    int getWeaponEffect() { return weapon->getEffect();}
    int setWeaponBoost1(int boost) { return weapon->setBoost1(boost);}

    //pure virtual function
    virtual void attack() = 0;
    virtual void specialAbility1() = 0; 
    virtual void specialAbility2() = 0;
};

//derived class
class Mage : public CreateCharacter {

  public:
    Mage(string name, Weapon* weapon, int hp, int atk, int sta, int gold)
        : CreateCharacter(name, "Mage", weapon, hp, atk, sta, gold) { //call the base class constructor
        special_atk[0] = "Incendio";
        special_atk[1] = "Phoenix Glory";
    }
    ~Mage() override {}

    void attack() override {
        cout << name << " casts a spell with their " << weapon->getName() << "!" << endl;
    }
  
    void specialAbility1() override {
        cout << name << " uses " << special_atk[0] << "!" << endl;
        
    }
    void specialAbility2() override {
        cout << name << " uses " << special_atk[1] << "!" << endl;
    }

};

//derived class
class Swordsman : public CreateCharacter {

  public:
    Swordsman(string name, Weapon* weapon, int hp, int atk, int sta, int gold)
        : CreateCharacter(name, "Swordsman", weapon, hp, atk, sta, gold) { //call the base class constructor
        special_atk[0] = "Dragon Twister";
        special_atk[1] = "Eternal Slash";
    }
    ~Swordsman() override {}

    void attack() override {
        cout << name << " swings their " << weapon->getName() << " at the enemy!" << endl;
    }
  
    void specialAbility1() override {
        cout << name << " uses " << special_atk[0] << "!" << endl;
    }
    void specialAbility2() override {
        cout << name << " uses " << special_atk[1] << "!" << endl;
    }

};

//derived class
class Marksman : public CreateCharacter {

  public:
    Marksman(string name, Weapon* weapon, int hp, int atk, int sta, int gold)
        : CreateCharacter(name, "Marksman", weapon, hp, atk, sta, gold) { //call the base class constructor
        special_atk[0] = "Meteor Shower";
        special_atk[1] = "Hell Rain";
    }
    ~Marksman () override {}

    void attack() override {
        cout << name << " takes aim with their " << weapon->getName() << "!" << endl;
    }

    void specialAbility1() override {
        cout << name << " uses " << special_atk[0] << "!" << endl;
    }
    void specialAbility2() override {
        cout << name << " uses " << special_atk[1] << "!" << endl;
    }
};