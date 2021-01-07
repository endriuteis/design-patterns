#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

#include <boost/bimap.hpp>
#include <boost/flyweight.hpp>
#include <boost/flyweight/key_value.hpp>
using namespace boost;
using namespace flyweights;

struct User
{
  // users share names! e.g., John Smith
  flyweight<string> first_name, last_name;
  // ...

  User(const string& first_name, const string& last_name) :
    first_name{first_name},
    last_name{last_name} {}
};

int main(int ac, char* av[])
{
  User user1{"John", "Smith"};
  User user2{"Jane", "Smith"};

  cout << user1.first_name << endl;
  cout << boolalpha;

  cout << "Are first names the same object? " << (&user1.first_name.get() == &user2.first_name.get()) << endl;
  cout << "Are last names the same object? " << (&user1.last_name.get() == &user2.last_name.get()) << endl;
}