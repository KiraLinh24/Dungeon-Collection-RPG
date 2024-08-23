#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib> 
#include <string>
#include "CreateCharacter.h"
#include "GameEvent.h" 
using namespace std;

//create a new character when the user select new game
CreateCharacter* createCharacter(){

  //get the user input for the character name and print out the name
  string name;
  cout << "What would you like your character's name to be?" << endl;
  cin.ignore();
  getline(cin, name);
  cout << endl;
  cout << "Your character's name is " << name << endl;

  //user have option to pick their character's class
  cout << "Pick your class: " 
     << "\n 1. Swordsman: Fearless warrior wielding a mighty sword"
      << "\n   HP: 625 "
      << "\n   ATK: 325 "
      << "\n   STA: 200 "
      << "\n   Special Ability: "
      << "\n     - Dragon Twister:  Deal double damage to the enemy"
      << "\n     - Eternal Slash:  Unleash a relentless slashing attack, dealing triple damage to the enemy"
     << endl << "\n 2. Mage: Master of elemental magic"
      << "\n   HP: 150 "
      << "\n   ATK: 300 "
      << "\n   STA: 525 "
      << "\n   Special Ability: "
      << "\n     - Incendio:  Send a fire attack that deals double damage to the enemy"
      << "\n     - Phoenix Glory:  Heal the the current's HP"
      << endl << "\n 3. Marksman: Deadly archer with unmatched precision" 
      << "\n   HP: 100 "
      << "\n   ATK: 550 "
      << "\n   STA: 395 " 
      << "\n   Special Ability: "
      << "\n     - Meteor Shower:  Deal double damage to the enemy"
      << "\n     - Hell Rain: Unleash a barrage of devastating attacks, dealing quadruple damage to the enemy" << endl;

  //variables
  int choice;
  int weaponChoice;
  bool cont = true;
  CreateCharacter* player = nullptr; //assign pointer object to the player

  //start of the while loop where use switch and case to pick their class and weapon
  cin >> choice;
  while(cont == true){
    switch(choice){
      case 1:
        cout << endl;
        cout << "You have chosen the Swordsman class." << endl;
        cout << "Pick your weapon: " 
         << "\n 1. Greatsword \n"
           << "      +15 ATK" << endl
           << "      +25 STA" << endl
           << "      -15 HP" << endl
         << "\n 2. Katana Blade \n"
            << "      +30 ATK" << endl
            << "      +20 STA" << endl
            << "      -55 HP" << endl
         << endl;

        //ask user what weapon they want for Swordsman class
        cin >> weaponChoice;
        while(true){  
          if (weaponChoice == 1){
            cout << "You have select the Mighty Greatsword." << endl;
            cout << "⠀⡴⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⢸⢇⢛⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⢸⠀⡏⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠸⡆⢷⡈⢷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠘⡆⢳⠈⢷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠸⣄⢧⠈⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠘⡌⢆⠀⣢⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠘⡈⢆⣯⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠸⡌⢮⢾⣹⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠸⣌⢮⢷⣽⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠙⡌⢮⣾⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠈⢎⢿⣿⣓⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡆⣏⢻⣷⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢃⡇⠈⢷⣟⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡸⠆⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⠄⡘⠻⣾⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⢶⣤⠼⢫⣇⡀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⣽⠘⣦⣰⣷⢄⠀⠀⠀⠀⣀⡶⠃⢀⢄⠄" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣯⡮⢾⣿⡮⡿⠀⠀⠀⡔⠏⢀⢴⢣⠂⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣽⣯⣿⣿⡏⠁⠀⢀⠹⡠⡨⠋⠁⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠀⢳⣟⣄⠀⠘⢰⠰⠁⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⣟⢆⠀⡶⣸⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣦⣷⠁⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣳⡀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠯⡽⠀" << endl;
            Weapon* greatsword = new Weapon("Greatsword", 15, 25, 15);  //create a new weapon object
            player = new Swordsman(name, greatsword, 625, 325, 200, 500);  //create a new Swordsman object
            break;
          }
          else if (weaponChoice == 2){
            cout << "You have select the Katana Blade." << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣤⣀⠀ " << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡼⣝⣿⣿⠁" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡾⣝⣾⠯⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣛⢾⠿⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⡳⣼⠟⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣟⢶⣽⠛⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣷⣮⣿⠛⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡟⠈⣻⣿⣧⡄⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡰⠋⢠⡾⠉⠉⠉⠁⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡞⠁⣴⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠋⣠⡾⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡞⠁⣴⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠋⣠⣾⡋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠎⢀⣼⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡜⠃⣠⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠋⣠⣾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠋⢠⣾⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡰⠋⢀⣼⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠊⢀⣴⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠋⣀⣴⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠋⣠⡾⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⢀⡴⢋⣤⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⣠⠞⢁⣴⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⣀⡴⠊⣡⡾⠏⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠈⠛⠛⠛⠋⠀⠀⠀" << endl;
            Weapon* katana = new Weapon("Katana Blade", 30, 20, 55);  //create a new weapon object
            player = new Swordsman(name, katana, 625, 325, 200, 500);  //create a new Swordsman object
            break;
          }
          else{
            cout << "Invalid input. Please try again." << endl;
            cout << endl;
            cin >> weaponChoice;
          }
        }
        cont = false;
        break;
      case 2:
        cout << endl;
        cout << "You have chosen the Mage class." << endl;
        cout << "Pick your weapon: " 
         << "\n 1. Wand \n"
           << "      +15 ATK" << endl
           << "      +30 STA" << endl
           << "      -5 HP" << endl
           << "\n 2. Staff \n"
           << "      +33 ATK" << endl
           << "      +25 STA" << endl
           << "      -15 HP" << endl
         << endl;

        //ask user what weapon they want for Mage class
        cin >> weaponChoice;
        while(true){  
          if (weaponChoice == 1){
            cout << "You have select the Powerful Wand." << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀ " << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠋⢀⣿⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡋⢀⣠⠞⠁⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⠏⠁⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⠏⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⠏⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⢀⣴⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⢀⣴⣿⣿⣿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⢀⡴⢿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⡴⠋⠀⣠⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠷⠤⠞⠁" << endl;
            Weapon* catalyst = new Weapon("Wand", 15, 30, 5);  //create a new weapon object
            player = new Mage(name, catalyst, 150, 300, 525, 500); //create a new Mage object
            break;
          }
          else if (weaponChoice == 2){
            cout << "You have select the Magical Staff." << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠠⠄⣀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡗⡔⢉⣑⢎⢧⡄⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣎⢆⢏⠿⣎⠎⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⣆⡇⠉⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡸⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢳⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢎⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣜⠎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡜⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡽⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⢣⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣆⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡘⡌⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡳⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠀⢀⢳⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⢀⣎⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠘⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            Weapon* staff = new Weapon("Staff", 33, 25, 15); //create a new weapon object
            player = new Mage(name, staff, 150, 300, 525, 500);   //create a new Mage object
            break;
          }
          else{
            cout << "Invalid input. Please try again." << endl;
            cout << endl;
            cin >> weaponChoice;
          }
        }
        cont = false;
        break;
      case 3:
        cout << endl;
        cout << "You have chosen the Marksman class." << endl;
        cout << "Pick your weapon: " 
         << "\n 1. Crossbow \n"
         << "      +10 ATK" << endl
         << "      +25 STA" << endl
         << "      -5 HP" << endl
         << "\n 2. Shuriken \n"
         << "      +15 ATK" << endl
         << "      +20 STA" << endl
         << "      -15 HP" << endl
         << endl;

        //ask user what weapon they want for Marksman class
        cin >> weaponChoice;
        while(true){  
          if (weaponChoice == 1){
            cout << "You have select the Precise Crossbow." << endl;
            cout << "⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣄⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⢸⣟⠻⢶⣦⣤⣄⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡇⠀⠈⠳⣄⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠘⣿⠀⠀⠈⠙⠻⢿⣿⣿⣿⣷⣦⣄⠀⠀⠀⠀⣿⡀⠀⠀⠈⠳⣄⠀" << endl
              << "⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠈⠙⠿⣿⣿⣿⠟⢀⣴⣦⡈⠻⣦⣤⣀⣀⡟⠀" << endl
              << "⠀⠀⠀⠀⠀⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⣠⣾⣿⢟⣿⣿⠆⠀⠀⠀⠈⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⢹⡇⠀⠀⠀⠀⠀⠀⠀⢀⣴⣾⡿⠋⣠⣿⡿⢁⣤⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⣴⣿⡿⠋⣠⣾⡿⠋⢠⣿⣿⣷⡀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⢸⣧⠀⠀⠀⠀⣠⣾⡿⠋⣠⣾⣿⠟⠁⠀⠈⢻⣿⣿⣷⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠈⣿⠀⠀⢠⣾⡿⠋⣠⣾⡿⠛⠁⠀⠀⠀⠀⠀⠹⣿⣿⡄⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⣿⢀⣴⡿⠋⣠⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣇⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⢀⣿⡿⠋⣠⣾⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⡀⠀⠀" << endl
              << "⠀⠀⠀⠀⣠⣿⣿⣧⣾⣿⣥⣤⣤⣄⣀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠹⣧⠀⠀" << endl
              << "⠀⠀⣠⣾⣿⣿⡿⠛⠁⠀⠀⠀⠉⠉⠉⠉⠉⠉⠙⠛⠛⠛⠛⠛⠛⠿⠶⠿⠇⠀" << endl
              << "⠀⠘⢿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            
            Weapon* crossbow = new Weapon("Crossbow", 10, 25, 5);  //create a new weapon object
            player = new Marksman(name, crossbow, 100, 550, 395, 500);  //create a new Marksman object
            break;
          }
          else if (weaponChoice == 2){
             cout << "You have select the Rasenshuriken." << endl;
            cout << "⠀⠀⠀⠀⠀⠀  ⠀⠀⠀⠀⠀⠀⠀⢰⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀  ⠀⠀⠀⠀⠀⢀⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀  ⠀⠀⠀⠀⠀⣼⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀  ⠀⠀⠀⠀⠰⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⢀⣀⡀⠀⠀⠀⠀  ⠀⠀⠀⠀⠈⣿⣿⠉⠀⠀⠀⠀⠀ ⠀⠀⠀⢀⣀⡀⠀" << endl
              << "⠀⠈⠙⢿⣿⣿⣿⣿⣿⣧⡀⠀⠀⣠⣿⣿⣄⠀⠀⢀⣼⣿⣿⣿⣿⣿⡿⠋⠁⠀" << endl
              << "⠀⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⡿⠛⠛⢿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠘⣿⣷⣀⣀⣾⣿⠃⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⠀⠀⢠⣿⣿⠿⠿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀⠀ ⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⡟⠀⠀⠀⠀⢻⣿⣷⣾⡀⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀ ⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⡷⠀⠀⠀⠀⢾⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀ ⠀⠀⠀⠀⠀⠀⢰⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠈⠻⢿⣿⡆⠀⠀⠀⠀⠀⠀⠀" << endl
              << "⠀ ⠀⠀⠀⠀⠀⢠⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⡄⠀⠀" << endl;
            Weapon* shuriken = new Weapon("Shuriken", 15, 20, 5); //create a new weapon object
            player = new Marksman(name, shuriken, 100, 550, 395, 500);  //create a new Marksman object
            break;
          }
          else{
            cout << "Invalid input. Please try again." << endl;
            cout << endl;
            cin >> weaponChoice;
          }
        }
        cont = false;
        break;
      default:
        cout << "Invalid choice. Please enter a valid choice." << endl;
        cout << endl;
        cin >> choice;
    }
  }

  //return the player object
  return player;
}

//load the game when select whereas it return the player in pointer
CreateCharacter* loadGame(){
  
  CreateCharacter* player = nullptr; //create a pointer to the player object

  //user input the file name to load
  string fname;
  ifstream fin;

  while (true) {
      cout << "Enter the file name: ";
      cin >> fname;

      fin.open(fname);
      if (fin.is_open()) {
          // File is successfully loaded
          cout << "File " << fname << " is loaded successfully." << endl;
          cout << endl;
          break;
      } else {
          // File not found, stop the code running
          cout << "File " << fname << " not found. Exiting..." << endl;
          exit(1);
      }
  }
  //variables
  string classes;
  string name;
  int hp;
  int atk;
  int sta;
  int coin;
  string weapon;
  int weaponBoost;

  //read the file and put it in their destinated variables
  getline(fin, classes);
  getline(fin, name);
  fin >> hp;
  fin >> atk;
  fin >> sta;
  fin >> coin;
  fin >> weaponBoost;
  getline(fin, weapon);
  
  // read classes and weapon string to assigned the variables into player object
  if( classes == "Swordsman"){
    if (weapon == "Greatsword"){
      Weapon* greatsword = new Weapon("Greatsword", weaponBoost, 25, 55);
      player = new Swordsman(name, greatsword, hp, atk, sta, coin);
    }
    else{
      Weapon* katana = new Weapon("Katana Blade", weaponBoost, 20, 15);
      player = new Swordsman(name, katana, hp, atk, sta, coin);
    }
  }
  else if( classes == "Mage"){
    if (weapon == "Catalyst Book"){
      Weapon* catalyst = new Weapon("Catalyst Book", weaponBoost, 30, 5); 
      player = new Mage(name, catalyst, hp, atk, sta, coin);
    }
    else{
      Weapon* staff = new Weapon("Staff", weaponBoost, 25, 15);
      player = new Mage(name, staff, hp, atk, sta, coin);
    }
  }
  else{
    if (weapon == "Crossbow"){
      Weapon* crossbow = new Weapon("Crossbow", weaponBoost, 25, 5); 
      player = new Marksman(name, crossbow, hp, atk, sta, coin);
    }
    else{
      Weapon* shuriken = new Weapon("Shuriken", weaponBoost, 20, 5);
      player = new Marksman(name, shuriken, hp, atk, sta, coin);
    }
  }

  //close the file and return the player object
  fin.close();
  return player;
}

//will save the game when the user select saves option
void saveGame(CreateCharacter* player){

  //user input the file name to save
  string fname;
  ofstream fout;

  while (true) {
      cout << "Enter the file name: ";
      cin >> fname;

      fout.open(fname);
      if (fout.is_open()) {
          // File is successfully saved
          cout << "File " << fname << " is saved successfully." << endl;
          cout << endl;
          break;
      } else {
          // File not found, prompt the user to enter a valid file name
          cout << "File " << fname << " not found. Please enter a valid file name." << endl;
          cout << endl;
      }
  }

  //received the player object and save it into the file
  fout << player->getClass() << endl;
  fout << player->getName() << endl;
  fout << player->getHP() << endl;
  fout << player->getATK() << endl;
  fout << player->getSTA() << endl;
  fout << player->getGold() << endl;
  fout << player->getWeaponBoost1() << endl;
  fout << player->getWeaponName() << endl;
  
  //close the file
  fout.close();
}

//a short game rule layout the game to guide the player
void gameRule(){
  cout << ".-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-." << endl
    << "|                                                                                       |" << endl
    << "|      ______   ______   _________   ______    ______   _    _   _        ______        |" << endl
    << "|     | | ____ | |  | | | | | | | \\ | |       | |  | \\ | |  | | | |      | |            |" << endl
    << "|     | |  | | | |__| | | | | | | | | |----   | |__| | | |  | | | |   _  | |----        |" << endl
    << "|     |_|__|_| |_|  |_| |_| |_| |_| |_|____   |_|  \\_\\ \\_|__|_| |_|__|_| |_|____        |" << endl
    << "!                                                                                       !" << endl
    << ":                                                                                       :" << endl
    << ":                                                                                       :" << endl
    << ".              1. Rule are simple, there two way to win the game!!                      ." << endl
    << ".                    • Earned 100,000 coins                                             ." << endl
    << ":                    • Defeated the final boss                                          :" << endl
    << ":              2. You can choose to not participate any event, except when              :" << endl
    << "!                 encounter enemy, you'll get punishment if you try run away!           !" << endl
    << "|              3. This game based on luck, so hopefully you're lucky enough             |" << endl
    << "|              4. Lastly and Importantly, throughout the game, use number key           |" << endl
    << "|                 to select your option; unless it ask for file or chartacter           |" << endl
    << "|                 name, you can type letter key!!!!!!!                                  |" << endl
    << "|                                                                                       |" << endl
    << "|                 That's all hope you enjoyed the adventure dungeon :)                  |" << endl
    << "|                    (Type any number key and enter to start the game)                  |" << endl
    << "|                                                                                       |" << endl
    << "`-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'" << endl;
  cout << endl;

  //player need to type any natural number in order to start the game
  int input;
  cin >> input;
  if(input){
    return;
  }
}

//print starter menu at the start when user click run program
void starter(){
    cout <<  "   __________________________________________________________" << endl
         <<  " / \\                                                         \\."  << endl
         <<  "|   |       __ _____ __  ___ _____    __  __  __ __ ___      |."  << endl
         <<  " \\_ |     /' _/_   _/  \\| _ \\_   _|  / _]/  \\|  V  | __|     |."  << endl
         <<  "    |     `._`. | || /\\ | v / | |   | [/\\ /\\ | \\_/ | _|      |."  << endl
         <<  "    |     |___/ |_||_||_|_|_\\ |_|    \\__/_||_|_| |_|___|     |."  << endl
         <<  "    |                                                        |."  << endl
         <<  "    |                                                        |."  << endl
         <<  "    |                                                        |."  << endl
         <<  "    |                       1. New Game                      |."  << endl
         <<  "    |                                                        |."  << endl
         <<  "    |                       2. Load Game                     |."  << endl
         <<  "    |                                                        |."  << endl
         <<  "    |                       3. Quit                          |."  << endl
         <<  "    |                                                        |."  << endl
         <<  "    |                                                        |."  << endl
         <<  "    |   _____________________________________________________|___"  << endl
         <<  "    |  /                                                       /." << endl
         <<  "    \\_/_______________________________________________________/." << endl;
    cout << endl;
}

//print the menu to show the player vary options
void menu(){
  cout << "   _.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._" << endl
    << ".-'---      - ---     --     ---   -----   - --       ----  ----   -     ---`-." << endl
    << " )                                                                           (" << endl
    << "(                                                                             )" << endl
    << " )               __|                         \\  |                            (" << endl
    << "(               (_ |   _` |   ` \\    -_)    |\\/ |   -_)    \\   |  |           )" << endl
    << " )             \\___| \\__,_| _|_|_| \\___|   _|  _| \\___| _| _| \\_,_|          (" << endl
    << "(                                                                             )" << endl
    << " )                                                                           (" << endl
    << "(                                                                             )" << endl
    << " )                              1. Explore                                   (" << endl
    << "(                                                                             )" << endl
    << " )                              2. Check Status                              (" << endl
    << "(                                                                             )" << endl
    << " )                              3. Save Game                                 (" << endl
    << "(                                                                             )" << endl
    << " )                              4. Quit Game                                 (" << endl
    << "(                                                                             )" << endl
    << " )                                                                           (" << endl
    << "(___       _       _       _       _       _       _       _       _       ___)" << endl
    << "    `-._.-' (___ _) (__ _ ) (_   _) (__  _) ( __ _) (__  _) (__ _ ) `-._.-'    " << endl
    << "            `-._.-' (  ___) ( _  _) ( _ __) (_  __) (__ __) `-._.-'            " << endl
    << "                    `-._.-' (__  _) (__  _) (_ _ _) `-._.-'                    " << endl
    << "                            `-._.-' (_ ___) `-._.-'                            " << endl
    << "                                    `-._.-'                                    " << endl;
  cout << endl;
}

//print out the player status when it got call in the main function
void checkStatus(CreateCharacter* player){
  //print out the player status from the player object
   cout << " __| |____________________________________________| |__" << endl
        << "(__   ____________________________________________   __)" << endl
        << "   | |" << endl
        << "   | |                 Check Status:" << endl
        << "   | |" << endl
        << "   | |                 Name: " << player->getName()  << endl
        << "   | |                 Class: " << player->getClass() << endl
        << "   | |                 Speciality Ability:" << endl
        << "   | |                     " << player->getSpecialAbility1()  << endl
        << "   | |                     " << player->getSpecialAbility2() << endl
        << "   | |                 HP: " << player->getHP() << endl
        << "   | |                 ATK: " << player->getATK()  << endl
        << "   | |                 STA: " << player->getSTA() << endl
        << "   | |                 Coin: " << player->getGold()  << endl
        << "   | |                 Weapon: " << player->getWeaponName() << endl
        << "   | |                        +" << player->getWeaponBoost1() << " ATK" << endl
        << "   | |                        +" << player->getWeaponBoost2() << " STA" << endl
        << "   | |                        -" << player->getWeaponEffect() << " HP" << endl
        << "   | | " <<  endl
        << "   | |           Type any number key to continue" << endl
        << " __| |____________________________________________   __" << endl
        << "(__   ____________________________________________   __)" << endl
        << "   | |                                            | |" << endl;
  //to see the menu or continue, the user have to type any natural number key
  int input;
  cin >> input;
  if(input){
    return;
  }
  
}

int main() {
  //call the game rule function to show the player the game rule
  gameRule();

  //call the starter function to show the player starter mennu
  starter();

  //variables
  int choice;
  bool cont = true;
  CreateCharacter* player = nullptr; //assign player as a pointer to create character object of type CreateCharacter type

  //player select their choice from the start menu
  cin >> choice;
  while(cont == true){
    switch(choice){
      case 1:
        cout << endl << "You have chosen to start a new game." << endl;
        cout << endl; 
        player = createCharacter(); //receive the player object from the createCharacter function
        cont = false;
        break;
      case 2:
        cout << "You have chosen to load a game." << endl;
        cout << endl;
        player = loadGame(); //receive the player object from the loadGame function
        cont = false;
        break;
      case 3:
        cout << "You have chosen to quit the game." << endl; 
        cout << endl; 
        exit(1); //exit the program
        break;
      default:
        cout << "Invalid choice. Select again." << endl;
        cout << endl; 
        cin >> choice; //ask the user the option again
    }
  }

  //print the menu to show the player vary options
  menu();
  cout << endl << "==========================================================" << endl;

  cont = true;
  cin.ignore();
  cin >> choice;
  while(cont == true){
    //if player health is 0, the game will end
    if(player->getHP() <= 0){
      cout << "You have died. Thank you for your adventure, peace-out. " << endl;
      delete player; //delete the player object to avoid memory leak
      return 0;
    }
    //if player earned 100,000 coins, the game will end
    if(player->getGold() >= 100000){
      cout << "You have earned enough coin to win the game." << endl;
      cout << "Congratulations!!!! You a beast in this game!!!" << endl;
      delete player; //delete the player object to avoid memory leak
      return 0;
    }
    switch(choice){
      
      case 1:
        //if player below 50 stamina, give the player 50 stamina to fight enemy
        if(player->getSTA() < 50){
          player->addSTA(50);
        }
      
        GameEvent gameEvent; //create a gameEvent object of the gameEvent class
        gameEvent.explore(player); //call the explore method from the gameEvent class on gameEvent object, player pointer will be passed as a arguement to this method
        cout << endl;

        //if player higher than 0 health, let the player pick their option again from the menu
        if(player->getHP() > 0 || player->getGold() < 100000){
          //print the menu to show the player vary options
          menu();
          cout << endl << "==========================================================" << endl;
          cin >> choice;
          break;
        }
        break;
      
      case 2:
        checkStatus(player); //call the checkStatus function to show the player status  
        cout << endl;
        cout << endl << "==========================================================" << endl;

        //if player higher than 0 health, let the player pick their option again from the menu
        if(player->getHP() > 0){
          //print the menu to show the player vary options
          menu();
          cout << endl << "==========================================================" << endl;
          cin >> choice;
          break;
        }
        break;
      
      case 3:
        cout << "You have chosen to save the game." << endl;
        saveGame(player);  //call the saveGame function to save the player object to a file
        cout << endl;
        
        //if player higher than 0 health, let the player pick their option again from the menu
        if(player->getHP() > 0 || player->getGold() < 100000){
          //print the menu to show the player vary options
          menu();
          cout << endl << "==========================================================" << endl;
          cin >> choice;
          break;
        }
        break;
      
      case 4:
          cout << "You have chosen to exit the game. Do you want to save the game before leave?" << endl;
        cout << "1. Yes \n2. No" << endl;
        cout << endl;
        int save; 
        cin >> save;
        if (save == 1){
          //player agree to save the game 
          saveGame(player);
          cout << "Your progress had been saved." << endl;
          cout << "Thank you for playing!" << endl;
          delete player; //avoid the memory leak from delete player pointer
          exit(1);
        } 
        else{
          cout << "Thank you for playing!" << endl;
          delete player; //avoid the memory leak
          exit(1);
        }
      default:
        cout << "Invalid choice. Select again." << endl;
        cout << endl;
        cin >> choice;
    }
  }
  
  return 0;
}