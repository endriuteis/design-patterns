#include <complex>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

struct Creature
{
  int attack, health;

  Creature(int attack, int health) : attack(attack), health(health) {}
};

struct CardGame
{
  vector<Creature> creatures;

  CardGame(const vector<Creature> &creatures) : creatures(creatures) {}

  // return -1 if there is no clear winner
  int combat(int creature1, int creature2)
  {
    Creature &first = creatures[creature1];
    Creature &second = creatures[creature2];
    hit(first, second);
    hit(second, first);
    bool first_alive = first.health > 0;
    bool second_alive = second.health > 0;
    if (first_alive == second_alive) return -1;
    return first_alive ? creature1 : creature2;
  }

  virtual void hit(Creature &attacker, Creature &other) = 0;
};

struct TemporaryCardDamageGame : CardGame
{
  TemporaryCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}

  void hit(Creature &attacker, Creature &other) override
  {
    auto old_health = other.health;
    other.health -= attacker.attack;
    if (other.health > 0) other.health = old_health;
  }
};

struct PermanentCardDamageGame : CardGame
{
  PermanentCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}

  void hit(Creature &attacker, Creature &other) override { other.health -= attacker.attack; }
};

int main(int ac, char *av[])
{
  Creature c1{1, 2};
  Creature c2{1, 2};
  TemporaryCardDamageGame temp_game({c1, c2});
  cout << "Winner is: " << temp_game.combat(0, 1) << endl;
  cout << "Winner is: " << temp_game.combat(0, 1) << endl;

  c1 = Creature{1, 1};
  c2 = Creature{2, 2};
  temp_game = TemporaryCardDamageGame({c1, c2});
  cout << "Winner is: " << temp_game.combat(0, 1) << endl;

  c1 = Creature{2, 2};
  c2 = Creature{2, 2};
  temp_game = TemporaryCardDamageGame({c1, c2});
  cout << "Winner is: " << temp_game.combat(0, 1) << endl;

  c1 = Creature{1, 2};
  c2 = Creature{1, 3};
  PermanentCardDamageGame perm_game({c1, c2});
  cout << "Winner is: " << perm_game.combat(0, 1) << endl;
  cout << "Winner is: " << perm_game.combat(0, 1) << endl;
}