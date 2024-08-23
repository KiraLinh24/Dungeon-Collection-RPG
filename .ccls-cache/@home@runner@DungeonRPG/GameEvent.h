#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "CreateCharacter.h"
#include "Enemy.h"
using namespace std;

class GameEvent {
  public:
    // let player pick which direction they want to go
    void explore(CreateCharacter* player) {
      srand(time(0));
      cout << "You choose to explore. Which direction do you want to go?" << endl;
      cout << "1. Go Left (West direction)" << endl;
      cout << "2. Go Right (East direction)" << endl;
      cout << "3. Go Straight (North direction)" << endl;
      cout << endl;

      int choice;
      cin >> choice;
      switch (choice) {
        case 1:
            exploreLeft(player); //player select go left
            break;
        case 2:
            exploreRight(player); //player select go right
            break;
        case 3:
            exploreStraight(player); //player select go straight
            break;
        default:
            cout << "Invalid choice. Returning to exploration..." << endl;
            cout << endl;

            break;
      }
}

    void exploreLeft(CreateCharacter* player) {
      cout << "You chose to go left..." << endl;
      int eventChoice = rand() % 2; // randomly choose between gambling and finding treasure
    
      if (eventChoice == 0) {
          gambleCoins(player);
      } else {
          findTreasure(player);
      }
    }
    
    void exploreRight(CreateCharacter* player) {
      cout << "You chose to go right..." << endl;
      int eventChoice = rand() % 2; // randomly choose between encountering an enemy and gaining a boost
    
      if (eventChoice == 0) {
          encounterEnemy(player);
      } else {
          gainBoost(player);
      }
    }
    
    void exploreStraight(CreateCharacter* player) {
      cout << "You chose to go straight..." << endl;
      int eventChoice = rand() % 5; // randomly chooise between gamble, treasure, encounter enemy, gain boost, or fight final boss
    
      if (eventChoice == 0) {
          gambleCoins(player);
      } 
      else if (eventChoice == 1) {
          findTreasure(player);
      }
      else if (eventChoice == 2) {
          encounterEnemy(player);
      } 
      else if (eventChoice == 3) {
          gainBoost(player);
      }
      else if (eventChoice == 4) {
          finalBoss(player);
      }
      else {
          cout << "Invalid choice. Returning to exploration..." << endl;
          explore(player);
      }
    }

  private:
    void gambleCoins(CreateCharacter* player){
      int reward;
      int multiple = rand() % 3;
      if (multiple == 0){
        reward = 2; //multiple the bet by 2 if they won
      }
      else if(multiple == 1){
        reward = 3; //multiple the bet by 3 if they won
      }
      else{
        reward = 7; //multiple the bet by 7 if they won
      }
      
      cout << "You found a hidden room with gamble table and you'll receive " << reward << " time of the coin bet if you win. \nDo you want to gamble your coin?" << endl;
      cout << "1. Yes" << endl;
      cout << "2. No" << endl;
      int choice;
      cin >> choice;
      while(true){
        if (choice == 1){
          break;
        }
        else if( choice == 2){
          return;
        }
        else{
          cout << "Invalid choice. Please choose again." << endl;
        }
      }
      cout << "You decide to gamble your coins..." << endl;
      cout << "You have " << player->getGold() << " coins." << endl;
      cout << "How much do you want to gamble? (Your Maximum Bet is 10,000) " << endl;

      //if player below 0 coins, return to menu
      if(player->getGold() < 0){
        cout << "Look like you in debt. Sorry, you can't gamble." << endl;
        return;
      }

      int gambleAmount;
      while(true){
        cin >> gambleAmount;
        if(gambleAmount > 10000){
          cout << "Your bet is exceed the limit. Please try again." << endl; //if player bet more than 10,000, ask them again
        }
        else if (gambleAmount > player->getGold()){
          cout << "You don't have enough coins to gamble that much. Please try again." << endl; //if player bet more than their coins, ask them again
        }
        else{
          break;
        }
      }
      
      int gambleResult = rand() % 2 + 1;
      int pick;
      cout << "Pick your choice: \n1. Head \n2. Tail" << endl;
      cin >> pick;
      string HT;
      if (gambleResult == 1){
        HT = "Head";
      }
      else{
        HT = "Tail";
      }
      if(pick == gambleResult){
        cout << "It's " << HT <<"!! You gained " << gambleAmount * reward << endl; //player win the head and tail game, they gained coin
        player->deductGold(gambleAmount);
        player->addGold(gambleAmount * reward);
      }
      else{
        cout << "It's " << HT << "!! You lost " << gambleAmount << endl; //player lose the head and tail game, they lost coin
        player->deductGold(gambleAmount);
      }
      
    }

    void findTreasure(CreateCharacter* player){
      cout << "You saw something foggy ahead. It's can be a treasure or trap. Do you wish to continue approach it?" << endl;
      cout << "1. Yes" << endl;
      cout << "2. No" << endl;
      int choice;
      cin >> choice;
      while(true){
        if (choice == 1){
          break; //continue approaching
        }
        else if( choice == 2){
          return; //exit the function
        }
        else{
          cout << "Invalid choice. Please choose again." << endl;
        }
      }
      int eventChoice = rand() % 4 + 1;
      if( eventChoice == 1){
        cout << "You found golds pot while exploring! You earned ";
        int golds = rand() % 24000 + 6900; // give a random amount of golds between 6900 and 30899
        player->addGold(golds);
        cout << golds <<" coins" << endl;
      }
      else if (eventChoice == 2){
        cout << "You found better " << player->getWeaponName() << " while exploring!" << endl;
        int boost = rand() % 11 + 5; // give a random boost attack power between 5 and 15
        player->setWeaponBoost1(boost);
        cout << "Your " << player->getWeaponName() << " got addition " << boost << " boost! Now your weapon total ATK is " << player->getWeaponBoost1() << endl;
      }
      else if (eventChoice == 3){
        cout << "Oh No! There a trap as you explore! Your health is draining!" << endl; 
        int lost = rand() % 11 + 15; // give a random amount of lost health between 15 and 25
        player->deductHP(lost);
        cout << "You lost " << lost << " HP" << endl;
      }
      else if (eventChoice == 4){
        int lost;
        cout << "Your coins had been stole by a thief! You lost some coins!" << endl;
        //if player has more than 15000 coins, deduct player's coins by 3000 to 12000
        if (player->getGold() > 15000){ 
          lost = rand() % 9001 + 3000; 
          player->deductGold(lost);
          cout << "You lost " << lost << " coins" << endl;
        }
        else{ //else, deduct player's coins by 5 to 500
          lost = rand() % 496 + 5;
          player->deductGold(lost);
          cout << "You lost " << lost << " coins" << endl;
        }
      }
    }

    void encounterEnemy(CreateCharacter* player) {
      //declare a pointer of enemy type
      Enemy* enemy = nullptr;
      int enemyType = rand() % 3 + 1; // Randomly choose between Bandit, Alien, and Skeleton to battle the player
      switch (enemyType) {
        int option;
          case 1: //bandit
              if (player->getATK() < 500){
                enemy = new Bandit();
              }
              else{
                enemy = new Bandit(0);
              }
              enemy->printFace();
              cout << "You encountered a Bandit! If you escape, it'll affect your health and stamina.\nDo you want to battle it and earn some coin? " << endl;
              cout << "1. Yes" << endl;
              cout << "2. No" << endl;
              cin >> option;
              while(true){
                if (option == 1){
                  break;
                }
                else if( option == 2){ 
                  player->deductHP(15);
                  player->deductSTA(5);
                  cout << "You flee away!! You lose 15 HP and 5 STA!" << endl;

                  return;
                }
                else{
                  cout << "Invalid choice. Please choose again." << endl;
                  cout << endl;
                }
              }
              break;
          case 2: //alien
              if (player->getATK() < 500){
                enemy = new Alien();
              }
              else{
                enemy = new Alien(0);
              }
              enemy->printFace();
              cout << "You encountered an Alien! If you escape, it'll affect your health and stamina.\nDo you want to battle it and earn some coin? " << endl;
              cout << "1. Yes" << endl;
              cout << "2. No" << endl;
              cin >> option;
              while(true){
                if (option == 1){
                  break;
                }
                else if( option == 2){
                  player->deductHP(15);
                  player->deductSTA(5);
                  cout << "You flee away!! You lose 15 HP and 5 STA!" << endl;
                  return;
                }
                else{
                  cout << "Invalid choice. Please choose again." << endl;
                  cout << endl;
                }
              }
              break;
          case 3: //skeleton
              if (player->getATK() < 500){
                 enemy = new Skeleton();
              }
              else{
                enemy = new Skeleton(0);
              }
              enemy->printFace();
              cout << "You encountered a Skeleton! If you escape, it'll affect your health and stamina.\nDo you wish to battle it to received spledid rewards? " << endl;
              cout << "1. Yes" << endl;
              cout << "2. No" << endl;
              cin >> option;
              while(true){
                if (option == 1){
                  break;
                }
                else if( option == 2){
                  player->deductHP(15);
                  player->deductSTA(5);
                  cout << "You escape the battle! You lose 15 HP and 5 STA!" << endl;
                  cout << endl;
                  return;
                }
                else{
                  cout << "Invalid choice. Please choose again." << endl;
                  
                }
              }
              cout << endl;
              break;
      }
  
      // Display enemy stats
      cout << endl << "==========================================================" << endl;
      cout << "Enemy Stats:" << endl;
      cout << "HP: " << enemy->getHP() << endl;
      cout << "ATK: " << enemy->getATK() << endl;
      cout << endl;
      cout << player->getName() << "'s Stats:" << endl;
      cout << "HP: " << (player->getHP() - player->getWeaponEffect())<< endl;
      cout << "ATK: " << (player->getATK() + player->getWeaponBoost1()) << endl;
      cout << "STA: " << (player->getSTA() + player->getWeaponBoost2()) << endl;

      int enemyHP = enemy->getHP();
      cout << endl;
      cout << "Prepare for battle!" << endl;
  
      bool playerTurn = true; // Flag to indicate player's turn
      while ((player->getHP()-player->getWeaponEffect()) > 0 && enemyHP > 0) {
          if (playerTurn) {
              cout << endl;
              cout << player->getName() << "'s' turn!" << endl;
              cout << "1. Attack" << endl;
              cout << "2. Special Ability" << endl;
              cout << "3. Run" << endl;
              int choice;
              cin >> choice;
  
              switch (choice) {
                  case 1:
                      if((player->getSTA()+ player->getWeaponBoost2()) < 25){ //if player's stamina is less than 25, they can't attack
                        cout << "You don't have enough stamina to attack! You lose your turn!" << endl;
                      }
                      else{
                          enemyHP -= (player->getATK() + player->getWeaponBoost1());
                          player->attack();
                          cout << "Deals " << player->getATK() + player->getWeaponBoost1() << " damage!" << endl;
                          cout << endl;
                          player->deductSTA(25);
                      }
                      break;
                  case 2:
                      cout << "Which special ability do you want to use?" << "\n1. " << player->getSpecialAbility1() << " cost 225 STA \n2. " << player->getSpecialAbility2() << " cost 475 STA"<< endl;
                        cin >> choice;
                        if (choice == 1){
                          if((player->getSTA()+ player->getWeaponBoost2()) < 225){ //if player's stamina is less than 225, they can't use special ability 1 and lose turn
                            cout << "You don't have enough stamina to use this ability. You lose your turn!" << endl;
                          }
                          else{
                            player->specialAbility1();
                            player->deductSTA(225);
                            enemyHP -= ((player->getATK() + player->getWeaponBoost1())*2); //double the player's attack power
                          }
                        }
                        else{
                          if( (player->getSTA()+ player->getWeaponBoost2()) < 475){ //if player's stamina is less than 475, they can't use special ability 2 and lose turn
                            cout << "You don't have enough stamina to use this ability. You lose your turn!" << endl;
                          }
                          else{
                            //use special ability 2 base on player's class they pick at the beginning
                            if( player->getClass() == "Mage"){
                              player->specialAbility2();
                              player->addHP(player->getHP()*0.2);
                              player->deductSTA(475);
                            }
                            else if( player->getClass() == "Swordsman"){
                              player->specialAbility2();
                              enemyHP -= ((player->getATK() + player->getWeaponBoost1())*3);
                              player->deductSTA(475);
                            }
                            else{
                              player->specialAbility2();
                              enemyHP -= ((player->getATK() + player->getWeaponBoost1())*5);
                              player->deductSTA(475);
                            }
                          }
                        }
                      break;
                  case 3:
                      cout << "You tried to run, are you sure?" << endl;
                      cout << "1. Yes \n2. No" << endl;
                      cin >> choice;
                      if (choice == 1){ //if player choose to run, they lose 15 health point and 5 stamina point
                        cout << "You ran away! You lose 15 HP and 5 STA!" << endl;
                        player->deductHP(15);
                        player->deductSTA(5);
                        return;
                      }
                      else{
                        cout << "You decided to fight!" << endl;
                      }
                      break;
                  default:
                      cout << "Invalid choice. Please try again." << endl;
              }
          } else {
              cout << "Enemy's turn!" << endl;
              player->deductHP(enemy->getATK());
              enemy->attack();
              cout << "The enemy attacked you with their " << enemy->getATK() << " damage!" << endl;
          }
  
          // Display remaining HP
          cout << "Enemy Stats:" << endl;
          cout << "HP: " << enemyHP << endl;
          cout << "ATK: " << enemy->getATK() << endl;
          cout << endl;
          cout << player->getName() << "'s' Stats:" << endl;
          cout << "HP: " << (player->getHP() - player->getWeaponEffect())<< endl;
          cout << "ATK: " << (player->getATK() + player->getWeaponBoost1()) << endl;
          cout << "STA: " << (player->getSTA() + player->getWeaponBoost2()) << endl;
          cout << endl;
  
          // Toggle turn for player and enemy
          playerTurn = !playerTurn;
      }
  
      // Determine the outcome of the battle
      if ((player->getHP() - player->getWeaponEffect()) <= 0) {
          cout << "You were defeated by the enemy! Game Over!" << endl;
          exit(1);
      } else {
          int boost = rand() % 11 + 5;
          player->setWeaponBoost1(boost);
         
          cout << "You defeated the enemy! You received " << enemy->getCoin() << " and a new weapon with better stats!!" << endl;
          cout << "Your " << player->getWeaponName() << " got addition " << boost << " boost! Now your weapon total ATK is " << player->getWeaponBoost1() << endl;
          player->addGold(enemy->getCoin());
        
      }
  
      // Free memory allocated for the enemy
      delete enemy;
    }

    void gainBoost(CreateCharacter* player){
      cout << "You found a place to take a rest! Pick the following to boost your stats or continue" << endl;
      cout << "1. Take a nap to heal your health \n2. Practice your skill to increase your attack power \n3. Meditate to restore your stamina \n4. Continue" << endl;
      int choice;
      cin >> choice;
      while (true){
        if( choice == 1){
          cout << "You gain " << player->getHP()*0.2 << " HP!" << endl;
          player->addHP(player->getHP() * 0.2); //add 20% of the player's current HP to their HP
          break;
        }
        else if( choice == 2){
          cout << "You gain " << player->getATK()*0.1 << " ATK!" << endl;
          player->addATK(player->getATK() * 0.1); //add 10% of the player's current ATK to their ATK
          break;
        }
        else if( choice == 3){
          cout << "You gain " << player->getSTA()*0.2 << " STA!" << endl;
          player->addSTA(player->getSTA() * 0.2); //add 20% of the player's current STA to their STA
          break;
        }
        else{
          cout << "Invalid choice. Please choose again." << endl;
        }
      }
    }

    void finalBoss(CreateCharacter* player){
      cout << "You have lucky enough to find the final boss! You can battle the final boss to win the game without collect 100,000 coins! \nThere no punishment if you choose to run away." << endl;
      cout << "Do you wish to battle the Dragon, the final boss, to win the game?? " << endl;
      cout << "1. Yes" << endl;
      cout << "2. No" << endl;
      int option;
      cin >> option;
      while(true){
        if (option == 1){
          break;
        }
        else if( option == 2){
          return;
        }
        else{
          cout << "Invalid choice. Please choose again." << endl;
          cout << endl;
        }
      }
      
      Enemy* enemy = nullptr; //declare a pointer of enemy type
      enemy = new Dragon(); //create a new object of Dragon type in dynamic memory

      enemy->printFace();
      cout << "You have chosen to battle the Dragon, the final boss!" << endl;
      
      //show enemy stats
      cout << "Enemy Stats:" << endl;
      cout << "HP: " << enemy->getHP() << endl;
      cout << "ATK: " << enemy->getATK() << endl;
      cout << endl;

      //show player stats
      cout << player->getName() << "'s Stats:" << endl;
      cout << "HP: " << (player->getHP() - player->getWeaponEffect())<< endl;
      cout << "ATK: " << (player->getATK() + player->getWeaponBoost1()) << endl;
      cout << "STA: " << (player->getSTA() + player->getWeaponBoost2()) << endl;

      int enemyHP = enemy->getHP();
      cout << endl;
      cout << "Prepare for battle!" << endl;

      bool playerTurn = true; // Flag to indicate player's turn
      while ((player->getHP()-player->getWeaponEffect()) > 0 && enemyHP > 0) { //loop contuinues as long player and enemy's HP is greater than 0
          if (playerTurn) {
              cout << endl;

              //print out player's action
              cout << player->getName()<< "'s turn!" << endl;
              cout << "1. Attack" << endl;
              cout << "2. Special Ability" << endl;
              cout << "3. Run" << endl;
              int choice;
              cin >> choice;

              switch (choice) {
                  case 1:
                      //check if player has enough stamina to attack
                      if((player->getSTA()+ player->getWeaponBoost2()) < 25){ 
                        cout << "You don't have enough stamina to attack! You lose your turn!" << endl;
                      }
                      else{
                          enemyHP -= (player->getATK() + player->getWeaponBoost1());
                          player->attack();
                          cout << "Deals " << player->getATK() + player->getWeaponBoost1() << " damage!" << endl;
                          cout << endl;
                          player->deductSTA(25);
                      }
                      cout << endl;
                      break;
                  case 2:
                      cout << "Which special ability do you want to use?" << "\n1. " << player->getSpecialAbility1() << " cost 225 STA \n2. " << player->getSpecialAbility2() << " cost 475 STA"<< endl;
                        cin >> choice;
                        if (choice == 1){
                          //check if player has enough stamina to use special ability 1
                          if((player->getSTA()+ player->getWeaponBoost2()) < 225){
                            cout << "You don't have enough stamina to use this ability. You lose your turn!" << endl;
                          }
                          else{
                            player->specialAbility1();
                            player->deductSTA(225);
                            enemyHP -= ((player->getATK() + player->getWeaponBoost1())*2);
                          }
                        }
                          //check if player has enough stamina to use special ability 2
                        else{
                          if((player->getSTA()+ player->getWeaponBoost2()) < 475){
                            cout << "You don't have enough stamina to use this ability. You lose your turn!" << endl;
                          }
                          else{
                            //use the 2nd special ability based on the player's class
                            if( player->getClass() == "Mage"){
                              player->specialAbility2();
                              player->addHP(player->getHP()*0.2);
                              player->deductSTA(475);
                            }
                            else if( player->getClass() == "Swordsman"){
                              player->specialAbility2();
                              enemyHP -= ((player->getATK() + player->getWeaponBoost1())*3);
                              player->deductSTA(475);
                            }
                            else{
                              player->specialAbility2();
                              enemyHP -= ((player->getATK() + player->getWeaponBoost1())*5);
                              player->deductSTA(475);
                            }
                          }
                        }
                      cout << endl;
                      break;
                  case 3:
                      //player can run away from the boss battle but only in 50% chance success
                      cout << "You have 50% chance to run, are you sure?" << endl;
                      cout << "1. Yes \n2. No" << endl;
                      cin >> choice;
                      if (choice == 1){
                        int random = rand() % 2;
                        if (random == 0){
                          cout << "You ran away success!" << endl;
                          return;
                        }
                        else{
                          cout << "You failed to run away! You continue to battle the game!" << endl;
                          break;
                        }
                      }
                      else{
                        cout << "You decided to fight!" << endl;
                      }
                       break;
                  default:
                      cout << "Invalid choice. Please try again." << endl;
              }
          } else {
              //enemy turn after the player turn
              cout << "Enemy's turn!" << endl;
              player->deductHP(enemy->getATK());
              enemy->attack();
              cout << "The enemy attacked you with their " << enemy->getATK() << " damage!" << endl;
          }

          // Display remaining HP
          cout << endl << "==========================================================" << endl;
          cout << "Enemy Stats:" << endl;
          cout << "HP: " << enemyHP << endl;
          cout << "ATK: " << enemy->getATK() << endl;
          cout << endl;
          cout << player->getName() << "'s' Stats:" << endl;
          cout << "HP: " << (player->getHP() - player->getWeaponEffect())<< endl;
          cout << "ATK: " << (player->getATK() + player->getWeaponBoost1()) << endl;
          cout << "STA: " << (player->getSTA() + player->getWeaponBoost2()) << endl;
          cout << endl;
  
          // Toggle turn (determine player or enemy turn)
          playerTurn = !playerTurn;
      }

      // Determine the outcome of the battle
      if ((player->getHP() - player->getWeaponEffect()) <= 0) {
      
          cout << "You were defeated by the enemy! Game Over!" << endl;
          // Free memory allocated for the enemy
          delete enemy;
          exit(1);
      } else {
          
          cout << "You defeated the enemy! \nCongratulation, You win the game!" << endl;
          // Free memory allocated for the enemy
          delete enemy;
          exit(1);
      }

    }

};