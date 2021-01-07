#include <cstdio>
#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
using namespace std;
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/serialization.hpp>

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

 private:
  friend class boost::serialization::access;

  template <class archive>
  void serialize(archive &ar, const unsigned version)
  {
    ar &street;
    ar &city;
    ar &suite;
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

 private:
  friend class boost::serialization::access;

  template <class archive>
  void serialize(archive &ar, const unsigned version)
  {
    ar &name;
    ar &address;
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
  auto clone = [](const Contact &c) {
    ostringstream oss;
    boost::archive::text_oarchive oa(oss);
    oa << c;
    string s = oss.str();
    cout << s << endl;

    istringstream iss(s);
    boost::archive::text_iarchive ia(iss);
    Contact result;
    ia >> result;
    return result;
  };
  auto john = EmployeeFactory::NewMainOfficeEmployee("John", 123);
  auto jane = clone(*john);

  cout << *john << endl << jane << endl;

  return 0;
}
