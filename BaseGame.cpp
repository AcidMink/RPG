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

string pa; //Player Action Input
int enemyhp = 10;
int enemymhp = 10; //Enemy Max Hp
int enemydmg = 1;
int enemydef = 0;
int enemydefg = 2;  //Enemy Defence Gain

int enemyPoisonLenght;
int enemyStatusLenght;
string enemyStatusType = "none";
bool enemyAbUnlockedPoison = false;

int php = 10;
int pmhp = 10;  //Player Max Hp
int pdmg = 1;
int pdef = 0;
int pdefg = 2;  //Player Defence Gain

int pPoisonLenght;
int pStatusLenght;
string pStatusType = "none";
bool pAbUnlockedPoison = false;



int aiBehaviour_gainShield;
int aiBehaviour_stackShield = 0;

int enemymistake;  //Enemy Mistake percentage Nr
int difficulty;   //For calculating enemy defence freq.
int roundc = 0;   //Round Count
int sic = 7;  //Shop Item Count

int r1;   //Shop rn item 1
int r2;   //Shop rn item 2
int r3;   //Shop rn item 3
int r4;    //Enemy random upgrade


string to_lower(string unfinished) {
  transform(unfinished.begin(), unfinished.end(), unfinished.begin(), [](unsigned char c) {return tolower(c);});
  return unfinished;
}
void infoSave(string winner_loser) {
  std::ofstream outputFile("game_logs.txt", std::ios::app); // Open file for appending
  outputFile << winner_loser << std::endl;
  outputFile.close();
}


void difficultys() {
  if (pa == "1") {difficulty = 2; infoSave("Difficulty lvl 1:");}
  else if (pa == "2") {difficulty = 3; infoSave("Difficulty lvl 2:");}
  else if (pa == "3") {difficulty = 4; infoSave("Difficulty lvl 3:");}
  else if (pa == "4") {difficulty = 5; infoSave("Difficulty lvl 4:");}
  else if (pa == "5") {difficulty = 10; infoSave("Difficulty lvl 5:");}
  else if (pa == "0") {difficulty = 1; infoSave("Difficulty lvl 0:");}
}

void showitems() {
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
}

void usf() {
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
  }
}

void upgradeEnemySelect() {
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
}

void enemyupgrade() {
  r4 = rand() % sic + 1;
  upgradeEnemySelect();
}

void upgradep() {
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

void attackf() {
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
void defencef() {
  pdef += pdefg;
}
void applyPoison() {
  if ((enemydef == 0)&&(enemyStatusType == "none")) {
    enemyStatusType = "Poison";
    enemyStatusLenght = pPoisonLenght;    
    cout << "Poison effect succesful!(" << pPoisonLenght << ")" << endl;
  }
  else if (enemydef > 0) {
    cout << "Failed to apply poison, enemy def too high!" << endl;
  }
}


void actions() {
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
}

void enemyAI() {
  enemymistake = rand() % difficulty + 1;
  aiBehaviour_gainShield = enemymhp * 0.5;

  if (enemymistake > 1) {
    if (pdmg > enemydefg) {
      cout << "Enemy is Attacking!" << endl;
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
    else if ((enemydef == 0)&&(pdef == 0)&&(enemyhp > aiBehaviour_gainShield)) {
      cout << "Enemy is Attacking!" << endl;
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
      cout << "Enemy is Shielding Up!" << endl;
      enemydef += enemydefg; 
    }    
    else if ((enemydef == 0)&&(pdef != 0)) {
      cout << "Enemy is Shielding Up!" << endl;
      enemydef += enemydefg; 
    }
    else if (aiBehaviour_stackShield > 2) {
      cout << "Enemy is Shielding Up!" << endl;
      enemydef += enemydefg; 
    }
    else if ((enemydef != 0)&&(pdef != 0)) {
      cout << "Enemy is Attacking!" << endl;
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
      cout << "Enemy is Attacking!" << endl;
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

int main() {
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
        if (php > 0) {cout << "Player Wins Round!" << endl; infoSave("Win");}
        else if (enemyhp > 0) {cout << "Player Loses Round!" << endl; infoSave("Lose");}
        break;
      }
    }
    if (roundc > 4) {
      cout << "Continue?(y/n)", cin >> pa;
      if (pa == "n") {
        cout << "End of Game!!" << endl;
        infoSave("End of Game!");
        infoSave("Stats : hp, dmg, defg  ;; Enemy: hp, dmg, defg");
        string spmhp = to_string(pmhp);
        string spdmg = to_string(pdmg);
        string spdefg = to_string(pdefg);
        infoSave(spmhp);
        infoSave(spdmg);
        infoSave(spdefg);
        string senemymhp = to_string(enemymhp);
        string senemydmg = to_string(enemydmg);
        string senemydefg = to_string(enemydefg);
        infoSave(senemymhp);
        infoSave(senemydmg);
        infoSave(senemydefg);
        string spPoisonUn = to_string(pAbUnlockedPoison);
        string senemyPoisonUn = to_string(enemyAbUnlockedPoison);
        infoSave("Abilities(Player/enemy): Poison,");
        infoSave(spPoisonUn);
        infoSave(senemyPoisonUn);
        break;
      }
    }
    cout << "Continue to Upgrade phase? ", cin >> pa;
    upgradep();
  }
}
