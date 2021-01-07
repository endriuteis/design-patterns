#include <cstdio>
#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
using namespace std;

struct Address
{
  string street;
  string city;
  int suite;

  Address() {}

  Address(const string &street, const string &city, const int suite) : street{street}, city{city}, suite{suite} {}

  Address(const Address &address) : street{address.street}, city{address.city}, suite{address.suite} {}

  friend ostream &operator<<(ostream &os, const Address &address)
  {
    return os << "street: " << address.street << " city: " << address.city << " suite: " << address.suite;
  }
};

struct Contact
{
  string name;
  Address *address;

  Contact() {}

  Contact(const string &name, Address *address) : name{name}, address{address} {}

  Contact(const Contact &other) : name{other.name}, address{new Address{*other.address}} {}

  ~Contact() { delete address; }

  friend ostream &operator<<(ostream &os, const Contact &contact)
  {
    os << "name: " << contact.name << " address: " << *contact.address;
    return os;
  }
};

struct EmployeeFactory
{
  static unique_ptr<Contact> NewMainOfficeEmployee(const string &name, const int suite)
  {
    static Contact p{"", new Address{"123 East Dr", "London", 0}};
    return NewEmployee(name, suite, p);
  }

 private:
  static unique_ptr<Contact> NewEmployee(const string &name, const int suite, const Contact &prototype)
  {
    auto result = make_unique<Contact>(prototype);
    result->name = name;
    result->address->suite = suite;
    return result;
  }
};

int main()
{
  auto john = EmployeeFactory::NewMainOfficeEmployee("John", 123);
  cout << *john << endl;

  return 0;
}
