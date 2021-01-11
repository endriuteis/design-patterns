#include <iostream>

using namespace std;

template <typename T>
struct Property
{
  T value;
  Property(const T initialValue) { *this = initialValue; }
  operator T() { return value; }
  T operator=(T newValue) { return value = newValue; }
};

struct Creature
{
  Property<int> strength{10};
  Property<int> agility{5};
};

int main(int ac, char* av[])
{
  Creature creature;
  creature.agility = 20;
  cout << creature.agility << endl;

  return 0;
}