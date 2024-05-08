#include <iostream>
#include <map>
#include <string>
#include <list>
#include <algorithm>
#include <cstdio>
#include <iterator>

using namespace std;

string pa; //Player Action Input
int enemyhp = 10;
int enemydmg = 1;
int enemydef = 0;
int enemydefg = 2;
int php = 10;
int pmhp = 10;
int pdmg = 1;
int pdef = 0;
int pdefg = 2;

int enemymistake;
int difficulty;
int roundc = 0;
int sic = 5;  //Shop Item Count

int r1;
int r2;
int r3;


string to_lower(string unfinished) {
  transform(unfinished.begin(), unfinished.end(), unfinished.begin(), [](unsigned char c) {return tolower(c);});
  return unfinished;
}

void difficultys() {
  if (pa == "1") {difficulty = 2;}
  else if (pa == "2") {difficulty = 3;}
  else if (pa == "3") {difficulty = 4;}
  else if (pa == "4") {difficulty = 5;}
  else if (pa == "5") {difficulty = 10;}
  else if (pa == "0") {difficulty = 1;}
}

void showitems() {
  if (r1 == 1) {
    cout << "_____________" << endl;
    cout << "|   Hp ++   |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "| Max HP +3 |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r1 == 2) {
    cout << "_____________" << endl;
    cout << "|   Dmg ++  |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|   Dmg +2  |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r1 == 3) {
    cout << "_____________" << endl;
    cout << "|   Hp +    |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "| Max HP +2 |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r1 == 4) {
    cout << "_____________" << endl;
    cout << "|   Dmg +   |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|   Dmg +1  |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r1 == 5) {
    cout << "_____________" << endl;
    cout << "|  Def Gain |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|  Def Gain |" << endl;
    cout << "|    +1     |" << endl;
    cout << "|-----------|" << endl;
  }  

    if (r2 == 1) {
    cout << "_____________" << endl;
    cout << "|   Hp ++   |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "| Max HP +3 |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r2 == 2) {
    cout << "_____________" << endl;
    cout << "|   Dmg ++  |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|   Dmg +2  |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r2 == 3) {
    cout << "_____________" << endl;
    cout << "|   Hp +    |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "| Max HP +2 |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r2 == 4) {
    cout << "_____________" << endl;
    cout << "|   Dmg +   |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|   Dmg +1  |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r2 == 5) {
    cout << "_____________" << endl;
    cout << "|  Def Gain |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|  Def Gain |" << endl;
    cout << "|    +1     |" << endl;
    cout << "|-----------|" << endl;
  }  

    if (r3 == 1) {
    cout << "_____________" << endl;
    cout << "|   Hp ++   |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "| Max HP +3 |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r3 == 2) {
    cout << "_____________" << endl;
    cout << "|   Dmg ++  |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|   Dmg +2  |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r3 == 3) {
    cout << "_____________" << endl;
    cout << "|   Hp +    |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "| Max HP +2 |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r3 == 4) {
    cout << "_____________" << endl;
    cout << "|   Dmg +   |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|   Dmg +1  |" << endl;
    cout << "|           |" << endl;
    cout << "|-----------|" << endl;
  }
  else if (r3 == 5) {
    cout << "_____________" << endl;
    cout << "|  Def Gain |" << endl;
    cout << "|-----------|" << endl;
    cout << "| Increases |" << endl;
    cout << "|  Def Gain |" << endl;
    cout << "|    +1     |" << endl;
    cout << "|-----------|" << endl;
  }  
}

void usf() {
  if (pa == "1") {
    if (r1 == 1) {
      pmph += 3;
    }
    if (r1 == 2) {
      pdmg += 2;
    }
    if (r1 == 3) {
      pmhp += 2;
    }
    if (r1 == 4) {
      pdmg += 1;
    }
    if (r1 == 5) {
      pdefg += 1;
    }
  }
  else if (pa == "2") {

  }
  else if (pa == "2") {
    
  }
}

void upgradep() {
  cout << "1";
  while(true) {
    r1 = rand() % sic + 1;
    r2 = rand() % sic + 1;
    r3 = rand() % sic + 1;    
    if ((r1 != r2)&&(r1 != r3)&&(r2 != r3)) {
      break;
    }
  }
  showitems();
  cin >> pa;
  usf();
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
  pdef += 2;
}


void actions() {
  if (pa == "a") {
    attackf();
  }
  else if (pa == "d") {
    defencef();
  }
}

void enemya() {
  enemymistake = rand() % difficulty + 1;
  if (enemymistake > 1) {
    if ((enemydef >= 1)||(pdef == 0)) {
      cout << "Enemy is Attacking!" << endl;
      if (pdef == 0) {
        php = php - enemydmg;
      }
      else if (pdef > 0) {
        pdef = pdef -enemydmg;
        if (enemydef < 0) {
          php = php + pdef;
          pdef = 0;    
        }
      }
    }
    else if (enemydef == 0) {
      cout << "Enemy is Shielding Up!" << endl;
      enemydef += 2;
    }
  }
  else if (enemymistake == 1) {
    cout << "Enemy Fails to attack" << endl;
  }
}

int main() {
  srand (time(NULL));
  cout << "Choose Difficulty 1-5" << endl;
  cin >> pa;
  difficultys();
  while (true) {
    roundc += 1;
    while (true) {
      cout << "____________________________" << endl;
      cout << "|      |  Enemy  |  Player |" << endl;
      cout << "|--------------------------|" << endl;
      cout << "|  Hp  |    " << enemyhp << "    |    " << php << "    |" << endl;
      cout << "| Dmg  |    " << enemydmg << "    |    " << pdmg << "    |" << endl;
      cout << "| Def  |    " << enemydef << "    |    " << pdef << "    |" << endl;
      cout << "|--------------------------|" << endl;
      cout << "Player, make your move: ", cin >> pa;
      pa = to_lower(pa);
      actions();
      if ((enemyhp > 0)&&(php > 0)) {
        enemya();
      }
      else {
        cout << "End of Round!" << endl;
        if (php > 0) {cout << "Player Wins Round!" << endl;}
        else if (enemyhp > 0) {cout << "Player Loses Round!" << endl;}
        break;
      }
    }
    if (roundc > 4) {
      cout << "Continue?(y/n)", cin >> pa;
      if (pa == "n") {
        cout << "End of Game!!" << endl;
        break;
      }
    }
    cout << "Continue to Upgrade phase? ", cin >> pa;
    upgradep();
  }
}
