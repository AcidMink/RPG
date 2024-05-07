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
int php = 10;
int pdmg = 1;
int pdef = 0;

int enemymistake;
int difficulty;
int roundc = 0;


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
}

void upgradep() {
  cout << "Coming Soon!" << endl;
  cout << "Continue?(y/n)", cin >> pa; 
  if ((pa == "y")||(pa == "n")) {
    cout << "End of Upgrade Phase!" << endl;
  }
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
