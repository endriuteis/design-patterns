#include <iostream>
#include <string>

using namespace std;

class Person
{
  friend class ResponsiblePerson;
  int age;

 public:
  Person(int age) : age(age) {}

  int get_age() const { return age; }
  void set_age(int age) { this->age = age; }

  string drink() const { return "drinking"; }
  string drive() const { return "driving"; }
  string drink_and_drive() const { return "driving while drunk"; }
};

class ResponsiblePerson
{
 public:
  ResponsiblePerson(const Person &person) : person(person) {}
  string drink() const
  {
    if (get_age() < 18) return "too young";
    return person.drink();
  }

  string drive() const
  {
    if (get_age() < 16) return "too young";
    return person.drive();
  }

  string drink_and_drive() const { return "dead"; }

  int get_age() const { return person.get_age(); }
  void set_age(int age) { return person.set_age(age); }

 private:
  Person person;
};

int main()
{
  Person p{10};
  ResponsiblePerson rp{p};

  cout << rp.drive() << endl;
  cout << rp.drink() << endl;
  cout << rp.drink_and_drive() << endl;

  rp.set_age(20);

  cout << rp.drive() << endl;
  cout << rp.drink() << endl;
  cout << rp.drink_and_drive() << endl;
}
