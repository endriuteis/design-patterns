#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Flower
{
  virtual string str() = 0;
};

struct Rose : Flower
{
  string str() override { return "A rose"; }
};

struct RedFlower : Flower
{
  Flower& flower;

  RedFlower(Flower& flower) : flower(flower) {}

  string str() override
  {
    string s = flower.str();
    if (s.find("red") != string::npos)
      return s;
    else if (s.find("blue") != string::npos)
    {
      return s + " and red";
    }
    else
      return s + " that is red";
  }
};

struct BlueFlower : Flower
{
  Flower& flower;

  BlueFlower(Flower& flower) : flower(flower) {}

  string str() override
  {
    string s = flower.str();
    if (s.find("blue") != string::npos)
      return s;
    else if (s.find("red") != string::npos)
    {
      return s + " and blue";
    }
    else
      return s + " that is blue";
  }
};

int main(int ac, char* av[])
{
  Rose rose;
  BlueFlower blue_rose{rose};
  RedFlower red_rose{rose};
  BlueFlower b_r_rose{red_rose};
  RedFlower r_b_r_rose{b_r_rose};
  cout << r_b_r_rose.str() << endl;
}