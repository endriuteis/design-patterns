#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;

int main()
{
  // pimpl
  // binary interfaces are fragile; this removes most of the internals to a separate class
  // prevents recompilation of sources reliant on the header

  Person p;
  p.greet();

  getchar();
  return 0;
}
