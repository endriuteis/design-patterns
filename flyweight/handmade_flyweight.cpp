#include <iostream>
#include <string>
#include <boost/bimap.hpp>
using namespace std;
using namespace boost;
typedef uint32_t key;

struct User
{
  User(const string& first_name, const string& last_name) : 
  first_name{add(first_name)},
  last_name{add(last_name)} {}

  const string& get_first_name() const{
    return names.left.find(first_name)->second;
  }

  const string& get_last_name() const{
    return names.left.find(last_name)->second;
  }
  protected:
    key first_name, last_name;
    static bimap<key, string> names;
    static key seed;

    static key add(const string& s)
    {
      auto it = names.right.find(s);
      if(it == names.right.end())
      {
        key id = ++seed;
        names.insert({seed, s});
        return id;
      }
      return it->second;
    }
};

ostream &operator<<(ostream &os, const User &user) {
  os << "first_name: " << user.get_first_name() << " last_name: " << user.get_last_name();
  return os;  
}

key User::seed{0};
bimap<key, string> User::names{};

int main(int ac, char* av[])
{
  User user1{"John", "Smith"};
  User user2{"Jane", "Smith"};
  cout << user1 << endl << user2 << endl;
}