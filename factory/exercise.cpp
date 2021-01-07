#include <iostream>
#include <string>

using namespace std;

struct Person
{
  int id;
  string name;
};

class PersonFactory
{
 public:
  Person create_person(const string &name)
  {
    Person p;
    p.name = name;
    p.id = i++;
    return p;
  }
  int i = 0;
};

int main()
{
  PersonFactory pf;
  cout << pf.create_person("Andrea").id << endl;
  cout << pf.create_person("Leticia").id << endl;
  return 0;
}
