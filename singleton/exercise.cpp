#include <functional>
#include <iostream>
using namespace std;

struct SingletonTester
{
  template <typename T>
  bool is_singleton(function<T*()> factory)
  {
    T* _1 = factory();
    T* _2 = factory();
    return _1 == _2;
  }
};

int main(int ac, char* av[])
{
  SingletonTester tester;

  cout << boolalpha;
  cout << "Is Singleton: " << tester.is_singleton<SingletonTester>([&]() -> SingletonTester* { return &tester; })
       << endl;
  cout << "Is Singleton: " << tester.is_singleton<SingletonTester>([]() { return new SingletonTester{}; }) << endl;
}