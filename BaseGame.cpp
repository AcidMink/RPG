incluse <iostream>

using namespace std;

string pa; //Player Action Input
int enemyhp = 10;
int enemydmg = 1;
int enemydef = 0;
int php = 10;
int pdmg = 1;
int pdef = 0;



string to_lower(string unfinished) 
{
  transform(unfinished.begin(), unfinished.end(), unfinished.begin(), [](unsigned char c) {return tolower(c);});
  return unfinished;
}

void attackf() 
{
  if (enemydef == 0)
  {
    enemyhp = enemyhp - pdmg;
  }
  elif (enemydef > 0)
  {
    enemydef = enemydef -pdmg;
    if (enemdef < 0) {enemydef = 0;}
  }
}
void defencef()
{
  pdef += 2;
}


void actions(string move) 
{
  if (pa == "a") {
    attackf();
  }
  elif (pa == "d") {
    defencef();
  }
}

void enemya()
{
  if (enemydef >= 1) 
  {
    cout << "Enemy is Attacking" << endl;
    
  }
}

int main() 
{
  while (true) 
  {
    cout << "EnemyHP: " << enemyhp << "      PlayerHp: " << php << endl;
    cout << "EnemyDmg: " << enemydmg << "    PlayerDmg: " << pdmg << endl;
    cout << "EnemyDef: " << enemydef << "    PlayerDef: " << pdef << endl;
    cout << "Player, make your move: ", cin >> pa;
    pa = to_lower(pa);
    actions(pa);
    if (enemyhp > 0) 
    {
      enemya();
    }
  }
}
