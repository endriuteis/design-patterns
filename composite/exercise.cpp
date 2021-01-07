#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ContainsIntegers
{
  int value = 0;
};

struct SingleValue : ContainsIntegers
{
  SingleValue() = default;

  explicit SingleValue(const int value) { this->value = value; }

  // TODO
};

struct ManyValues : ContainsIntegers
{
  void add(const int value) { this->value += value; }
};

int sum(const vector<ContainsIntegers*> items)
{
  int sum = 0;
  for (auto item : items) sum += item->value;
  return sum;
}

int main()
{
  SingleValue single_value{1};
  ManyValues other_values;
  other_values.add(2);
  other_values.add(3);
  cout << sum({&single_value, &other_values}) << endl;
}
