#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <list>
#include <algorithm>
#include <cstdio>
#include <iterator>
#include <sstream>

using namespace std;

string pa;    //Player Action Input
int enemyhp = 10;    //Enemy Current HP in Round
int enemymhp = 10;   //Enemy Max Hp
int enemydmg = 1;   //Enemy Damage
int enemydef = 0;   //Enemy Current Defence in Round
int enemydefg = 2;  //Enemy Defence Gain

int enemyPoisonLenght;    //How Long Enemy Gives Poison for
float enemyHealSize;    //How much % of Hp it Heals
int enemyStatusLenght;    //How Long is a Status Effect on Enemy for
string enemyStatusType = "none";    //What Status Type is on Enemy

int php = 10;   //Player HP in Round
int pmhp = 10;  //Player Max Hp
int pdmg = 1;   //Player Damage
int pdef = 0;   //Player Current Defence in Round
int pdefg = 2;  //Player Defence Gain


int pStatusLenght;    //How Long is a Status Effect on Player for
string pStatusType = "none";    //What Type of Effect Player has

bool pAbUnlockedPoison = false;   //Has Player Unlocked Poison
int pPoisonLenght;    //How Long Player Gives Poison for
bool pAbunlockedHeal = false;   //Has Player Unlocked Heal
float pHealSize;    //how much % HP Heal Gives
bool pUsedHeal = false;    //Use Heal in Round



int aiBehaviour_gainShield;   //Behaviour for Focusing on Shieding when HP Drops Below 50%
int aiBehaviour_stackShield = 0;    //Behaviour for Gaining Multiple Shields when Player gains Shield Multiple Times

int enemymistake;  //Enemy Mistake percentage Nr
int difficulty;   //For calculating enemy defence freq.
int roundc = 0;   //Round Count
int sic = 8;  //Shop Item Count

int r1;   //Shop rn item 1
int r2;   //Shop rn item 2
int r3;   //Shop rn item 3
int r4;    //Enemy random upgrade

int winCounter = 0;   //Counter for Wins in a Game
int lossCounter = 0;    //Counter for Losses in a Game


string to_lower(string unfinished) {    //Turns Input into Lower-Case
  transform(unfinished.begin(), unfinished.end(), unfinished.begin(), [](unsigned char c) {return tolower(c);});
  return unfinished;
}
void infoSave(string winner_loser) {    //For Saving Info in game_logs.txt
  std::ofstream outputFile("game_logs.txt", std::ios::app); // Open file for appending
  outputFile << winner_loser << std::endl;
  outputFile.close();
}


void difficultys() {    //Set the Difficulty for a the Game
  if (pa == "1") {difficulty = 2; infoSave("Difficulty lvl 1:");}
  else if (pa == "2") {difficulty = 3; infoSave("Difficulty lvl 2:");}
  else if (pa == "3") {difficulty = 4; infoSave("Difficulty lvl 3:");}
  else if (pa == "4") {difficulty = 5; infoSave("Difficulty lvl 4:");}
  else if (pa == "5") {difficulty = 10; infoSave("Difficulty lvl 5:");}
  else if (pa == "0") {difficulty = 1; infoSave("Difficulty lvl 0:");}
}

void showitems() {    //Shows Available Upgrades
  if (r1 == 1) {
    cout << "_____________" << endl;
    cout << "|   Hp ++   |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|   Max HP  |" << endl;
    cout << "|    +10    |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r1 == 2) {
    cout << "_____________" << endl;
    cout << "|   Dmg ++  |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|   Dmg +3  |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r1 == 3) {
    cout << "_____________" << endl;
    cout << "|   Hp +    |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "| Max HP +5 |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r1 == 4) {
    cout << "_____________" << endl;
    cout << "|   Dmg +   |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|   Dmg +2  |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r1 == 5) {
    cout << "_____________" << endl;
    cout << "| Def Gain+ |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|  Def Gain |" << endl;
    cout << "|    +2     |" << endl;
    cout << "|-----------|" << endl;
  }  
  else if (r1 == 6) {
    cout << "_____________" << endl;
    cout << "|  Def G ++ |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|  Def Gain |" << endl;
    cout << "|    +3     |" << endl;
    cout << "|-----------|" << endl;
  }  
  else if (r1 == 7) {
    cout << "________________" << endl;
    cout << "|   PoisonAtk  |" << endl;
    cout << "|--------------|" << endl;
    cout << "| Press'p', If |" << endl;
    cout << "| enemy def =0 |" << endl;
    cout << "| apply poison |" << endl;
    cout << "| for 3 rounds |" << endl;
    cout << "|--------------|" << endl;
  } 
  else if (r1 == 8) {
    cout << "________________" << endl;
    cout << "| Heal Ability |" << endl;
    cout << "|--------------|" << endl;
    cout << "|   Press'h'   |" << endl;
    cout << "| to heal +10% |" << endl;
    cout << "| once while in|" << endl;
    cout << "| combat. Lose |" << endl;
    cout << "|  25% max HP  |" << endl;
    cout << "|--------------|" << endl;
  } 

    if (r2 == 1) {
    cout << "_____________" << endl;
    cout << "|   Hp ++   |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|   Max HP  |" << endl;
    cout << "|    +10    |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r2 == 2) {
    cout << "_____________" << endl;
    cout << "|   Dmg ++  |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|   Dmg +3  |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r2 == 3) {
    cout << "_____________" << endl;
    cout << "|   Hp +    |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "| Max HP +5 |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r2 == 4) {
    cout << "_____________" << endl;
    cout << "|   Dmg +   |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|   Dmg +2  |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r2 == 5) {
    cout << "_____________" << endl;
    cout << "|  Def Gain |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|  Def Gain |" << endl;
    cout << "|    +2     |" << endl;
    cout << "|-----------|" << endl;
  }  
  else if (r2 == 6) {
    cout << "_____________" << endl;
    cout << "|  Def G ++ |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|  Def Gain |" << endl;
    cout << "|    +3     |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r2 == 7) {
    cout << "________________" << endl;
    cout << "|   PoisonAtk  |" << endl;
    cout << "|--------------|" << endl;
    cout << "| Press'p', If |" << endl;
    cout << "| enemy def =0 |" << endl;
    cout << "| apply poison |" << endl;
    cout << "| for 3 rounds |" << endl;
    cout << "|--------------|" << endl;
  }  
  else if (r2 == 8) {
    cout << "________________" << endl;
    cout << "| Heal Ability |" << endl;
    cout << "|--------------|" << endl;
    cout << "|   Press'h'   |" << endl;
    cout << "| to heal +10% |" << endl;
    cout << "| once while in|" << endl;
    cout << "| combat. Lose |" << endl;
    cout << "|  25% max HP  |" << endl;
    cout << "|--------------|" << endl;
  } 

    if (r3 == 1) {
    cout << "_____________" << endl;
    cout << "|   Hp ++   |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|   Max HP  |" << endl;
    cout << "|    +10    |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r3 == 2) {
    cout << "_____________" << endl;
    cout << "|   Dmg ++  |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|   Dmg +3  |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r3 == 3) {
    cout << "_____________" << endl;
    cout << "|   Hp +    |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "| Max HP +5 |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r3 == 4) {
    cout << "_____________" << endl;
    cout << "|   Dmg +   |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|   Dmg +2  |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r3 == 5) {
    cout << "_____________" << endl;
    cout << "|  Def Gain |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|  Def Gain |" << endl;
    cout << "|    +2     |" << endl;
    cout << "|-----------|" << endl;
  }  
  else if (r3 == 6) {
    cout << "_____________" << endl;
    cout << "|  Def G ++ |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|  Def Gain |" << endl;
    cout << "|    +3     |" << endl;
    cout << "|-----------|" << endl;
  } 
  else if (r3 == 7) {
    cout << "________________" << endl;
    cout << "|  Poison Atk  |" << endl;
    cout << "|--------------|" << endl;
    cout << "| Press'p', If |" << endl;
    cout << "| enemy def =0 |" << endl;
    cout << "| apply poison |" << endl;
    cout << "| for 3 rounds |" << endl;
    cout << "|--------------|" << endl;
  } 
  else if (r3 == 8) {
    cout << "________________" << endl;
    cout << "| Heal Ability |" << endl;
    cout << "|--------------|" << endl;
    cout << "|   Press'h'   |" << endl;
    cout << "| to heal +10% |" << endl;
    cout << "| once while in|" << endl;
    cout << "| combat. Lose |" << endl;
    cout << "|  25% max HP  |" << endl;
    cout << "|--------------|" << endl;
  } 
}

void usf() {    //For Giving Correct Upgrade for Chosen Card
  if (pa == "1") {
    if (r1 == 1) {
      pmhp += 10;
    }
    else if (r1 == 2) {
      pdmg += 3;
    }
    else if (r1 == 3) {
      pmhp += 5;
    }
    else if (r1 == 4) {
      pdmg += 2;
    }
    else if (r1 == 5) {
      pdefg += 2;
    }
    else if (r1 == 6) {
      pdefg += 3;
    }
    else if (r1 == 7) {
      pAbUnlockedPoison = true;
      pPoisonLenght += 3;
    }
    else if (r1 == 8) {
      pAbunlockedHeal = true;
      pHealSize += 0.1;
    }
  }
  else if (pa == "2") {
    if (r2 == 1) {
      pmhp += 10;
    }
    else if (r2 == 2) {
      pdmg += 3;
    }
    else if (r2 == 3) {
      pmhp += 5;
    }
    else if (r2 == 4) {
      pdmg += 2;
    }
    else if (r2 == 5) {
      pdefg += 2;
    }
    else if (r2 == 6) {
      pdefg += 3;
    }
    else if (r2 == 7) {
      pAbUnlockedPoison = true;
      pPoisonLenght += 3;
    }
    else if (r2 == 8) {
      pAbunlockedHeal = true;
      pHealSize += 0.1;
    }
  }
  else if (pa == "3") {
    if (r3 == 1) {
      pmhp += 10;
    }
    else if (r3 == 2) {
      pdmg += 3;
    }
    else if (r3 == 3) {
      pmhp += 5;
    }
    else if (r3 == 4) {
      pdmg += 2;
    }
    else if (r3 == 5) {
      pdefg += 2;
    }
    else if (r3 == 6) {
      pdefg += 3;
    }
    else if (r3 == 7) {
      pAbUnlockedPoison = true;
      pPoisonLenght += 3;
    }
    else if (r3 == 8) {
      pAbunlockedHeal = true;
      pHealSize += 0.1;
    }
  }
}

void upgradeEnemySelect() {   //Gives Random Upgrade for Enemy
  if (r4 == 1) {
    enemymhp += 10;
    cout << "Enemy Hp++" << endl;
  }
  else if (r4 == 2) {
    enemydmg += 3;
    cout << "Enemy Dmg++" << endl;
  }
  else if (r4 == 3) {
    enemymhp += 5;
    cout << "Enemy Hp+" << endl;
  }
  else if (r4 == 4) {
    enemydmg += 2;
    cout << "Enemy Dmg+" << endl;
  }
  else if (r4 == 5) {
    enemydefg += 2;
    cout << "Enemy DefG +2" << endl;
  }
  else if (r4 == 6) {
  enemydefg += 3;
  cout << "Enemy DefG +3" << endl;
  }
  else if (r4 == 7) {
  enemyPoisonLenght += 3;
  cout << "Enemy Poison Lenght +3" << endl;
  }
}

void enemyupgrade() {  //Creates the Random Upgrade Number and Picks it out
  r4 = rand() % sic + 1;
  upgradeEnemySelect();
}

void upgradep() {   //Makes Sure You can't get same Upgrades in Shop
  while(true) {
    r1 = rand() % sic + 1;
    r2 = rand() % sic + 1;
    r3 = rand() % sic + 1;    
    if ((r1 != r2)&&(r1 != r3)&&(r2 != r3)) {
      break;
    }
  }
  showitems();
  cout << "Choose upgrade!(1-3) ", cin >> pa;
  usf();
  enemyupgrade();
}

void attackf() {    //Player Attacks the enemy
  if (enemydef == 0) {
    enemyhp = enemyhp - pdmg;
  }
  else if (enemydef > 0) {
    enemydef = enemydef -pdmg;
    if (enemydef < 0) {
      enemyhp = enemyhp + enemydef;
      enemydef = 0;
    }
  }
}
void defencef() {   //Defence Action
  pdef += pdefg;
}
void applyPoison() {    //Apply Poison if Enemy has no Defence
  if ((enemydef == 0)&&(enemyStatusType == "none")) {
    enemyStatusType = "Poison";
    enemyStatusLenght = pPoisonLenght;    
    cout << "Poison effect succesful!(" << pPoisonLenght << ")" << endl;
  }
  else if (enemydef > 0) {
    cout << "Failed to apply poison, enemy def too high!" << endl;
  }
}
void applyHeal() {    //Apply Heal to Self
  pUsedHeal = true;
  cout << pHealSize << " " << pmhp << endl;
  int pGainHp_Heal = pHealSize * pmhp;
  cout << "???" << pGainHp_Heal;
  php += pGainHp_Heal;
}


void actions() {    //For taking Effect Damage and Allowing Player to do Actions
  if (pa == "a") {
    aiBehaviour_stackShield = 0;
    attackf();
  }
  else if (pa == "d") {
    aiBehaviour_stackShield += 1;
    defencef();
  }
  else if ((pa == "p")&&(pAbUnlockedPoison == true)) {
    applyPoison();
  }
  else if ((pa == "h")&&(pAbunlockedHeal == true)&&(pUsedHeal == false)) {
    applyHeal();
    cout << "?" << endl;
  }
  else {cout << "Action Failed..." << endl;}

  if (pStatusType != "none") {
    if ((pStatusType == "Poison")&&(pStatusLenght > 0)) {
      php = php - 1;
      pStatusLenght -= 1;
    }
  }    
  if ((pStatusType != "none")&&(pStatusLenght == 0)) {
      pStatusType = "none";
  }
}

void enemyAI() {    //All Enemy Behaviours
  enemymistake = rand() % difficulty + 1;
  aiBehaviour_gainShield = enemymhp * 0.5;

  if (enemymistake > 1) {
    if (pdmg > enemydefg) {
      cout << "1   Enemy is Attacking!" << endl;
      if (pdef == 0) {
        php = php - enemydmg;
      }
      else if (pdef > 0) {
        pdef = pdef -enemydmg;
        if (pdef < 0) {
          php = php + pdef;
          pdef = 0;    
        }
      }
    }
    else if ((enemydmg > pdmg)&&(pdefg < enemydmg)&&(enemyhp > php)) {
      cout << "2   Enemy is Attacking!" << endl;
      if (pdef == 0) {
        php = php - enemydmg;
      }
      else if (pdef > 0) {
        pdef = pdef -enemydmg;
        if (pdef < 0) {
          php = php + pdef;
          pdef = 0;    
        }
      }      
    }    
    else if ((pdef == 0)&&(enemydmg < enemyPoisonLenght)&&(pStatusType == "none")) {
      cout << "1  Enemy does Poison Attack" << endl;
      pStatusType = "Poison";
      pStatusLenght = enemyPoisonLenght;
    }
    else if ((enemydef == 0)&&(pdef == 0)&&(enemyhp >= aiBehaviour_gainShield)) {
      cout << "3   Enemy is Attacking!" << endl;
      if (pdef == 0) {
        php = php - enemydmg;
      }
      else if (pdef > 0) {
        pdef = pdef -enemydmg;
        if (pdef < 0) {
          php = php + pdef;
          pdef = 0;    
        }
      }
    }
    else if ((enemydef == 0)&&(pdef == 0)&&(enemyhp < aiBehaviour_gainShield)) {
      cout << "1   Enemy is Shielding Up!" << endl;
      enemydef += enemydefg; 
    }    
    else if ((enemydef == 0)&&(pdef != 0)) {
      cout << "2   Enemy is Shielding Up!" << endl;
      enemydef += enemydefg; 
    }
    else if (aiBehaviour_stackShield > 2) {
      cout << "3   Enemy is Shielding Up!" << endl;
      enemydef += enemydefg; 
    }
    else if ((enemydef != 0)&&(pdef != 0)) {
      cout << "4   Enemy is Attacking!" << endl;
      if (pdef == 0) {
        php = php - enemydmg;
      }
      else if (pdef > 0) {
        pdef = pdef -enemydmg;
        if (pdef < 0) {
          php = php + pdef;
          pdef = 0;    
        }
      }
    }
    else if ((enemydef != 0)&&(pdef == 0)) {
      cout << "5   Enemy is Attacking!" << endl;
      if (pdef == 0) {
        php = php - enemydmg;
      }
      else if (pdef > 0) {
        pdef = pdef -enemydmg;
        if (pdef < 0) {
          php = php + pdef;
          pdef = 0;    
        }
      }      
    }
    else {cout << "Enemy is confused????????????????" << endl;}
  }
  else if (enemymistake == 1) {
    cout << "Enemy Misses the attack" << endl;
  }
  if (enemyStatusType != "none") {
    if ((enemyStatusType == "Poison")&&(enemyStatusLenght > 0)) {
      enemyhp = enemyhp - 1;
      enemyStatusLenght -= 1;
    }
    if ((enemyStatusType == "Poison")&&(enemyStatusLenght == 0)) {
      enemyStatusType = "none";
    }
  }
}

int main() {    //Base for the Game
  srand (time(NULL));
  cout << "Choose Difficulty 1-5" << endl;
  cin >> pa;
  difficultys();
  cout << "'a' to attack, 'd' to add shield!" << endl;
  cout << "Type 'c' to continue!(press 'c') ", cin >> pa;
  while (true) {
    roundc += 1;
    enemyhp = enemymhp;
    php = pmhp;
    enemydef = 0;
    pdef = 0;
    enemyStatusType = "none";
    pStatusType = "none";
    enemyStatusLenght = 0;
    pStatusLenght = 0;
    pUsedHeal = false;
    while (true) {
      if ((enemyhp > 0)&&(php > 0)) {
        cout << "____________________________" << endl;
        cout << "|~~~~~~|  Enemy  |  Player |" << endl;
        cout << "|--------------------------|" << endl;
        cout << "|  Hp  |    " << enemyhp << "    |    " << php << "    |" << endl;
        cout << "| Dmg  |    " << enemydmg << "    |    " << pdmg << "    |" << endl;
        cout << "| Def  |    " << enemydef << "    |    " << pdef << "    |" << endl;
        cout << "|--------------------------|" << endl;
        cout << "| DefG |    " << enemydefg << "    |    " << pdefg << "    |" << endl;
        cout << "|--------------------------|" << endl;
        cout << "|StatEf|  " << enemyStatusType << "  |  " << pStatusType << "  |" << endl;
        cout << "|StatL |    " << enemyStatusLenght << "    |    " << pStatusLenght << "    |    " << endl;
        cout << "|--------------------------|" << endl;        
        cout << "Player, make your move: ", cin >> pa;
        pa = to_lower(pa);
        actions();
        if (enemyhp > 0) {
          enemyAI();
        }
      }
      else {
        cout << "End of Round!" << endl;
        if (php > 0) {cout << "Player Wins Round!" << endl; winCounter += 1;}
        else if (enemyhp > 0) {cout << "Player Loses Round!" << endl; lossCounter += 1;}
        break;
      }
    }
    if (roundc > 4) {
      cout << "Continue?(y/n)", cin >> pa;
      if (pa == "n") {
        cout << "End of Game!!" << endl;
        infoSave("Wins/Losses");
        
        infoSave("Stats : hp, dmg, defg  ;; Enemy: hp, dmg, defg");
        string spMHp = to_string(pmhp);
        string spDmg = to_string(pdmg);
        string spDefg = to_string(pdefg);
        string spStats = spMHp + " " + spDmg + " " + spDefg;
        infoSave(spStats);
        string sEnemyMHp = to_string(enemymhp);
        string sEnemyDmg = to_string(enemydmg);
        string sEnemyDefg = to_string(enemydefg);
        string sEnemyStats = sEnemyMHp + " " + sEnemyDmg + " " + sEnemyDefg;
        infoSave(sEnemyStats);
        string spPoisonLenght = to_string(pPoisonLenght);
        string sEnemyPoisonLenght = to_string(enemyPoisonLenght);
        infoSave("Abilities(Player/enemy): PoisonLen,");
        string sPoisonLenghts = spPoisonLenght + " " + sEnemyPoisonLenght;
        infoSave(sPoisonLenghts);
        infoSave("End of Game! \n");
        break;
      }
    }
    cout << "Continue to Upgrade phase? ", cin >> pa;
    upgradep();
  }
}
