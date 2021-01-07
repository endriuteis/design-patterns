/*
    "Don't put too much into an interface; spit into separate interfaces."
*/

#include <boost/lexical_cast.hpp>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace boost;

struct Document;

struct IMachine
{
  virtual void print(Document &doc) = 0;
  virtual void scan(Document &doc) = 0;
  virtual void fax(Document &doc) = 0;
};

struct MultiFunctionPrinter : IMachine
{
  void print(Document &doc) override
  {
    // ok
  }
  void scan(Document &doc) override
  {
    // ok
  }
  void fax(Document &doc) override
  {
    // ok
  }
};

struct Scanner : IMachine
{
  void print(Document &doc) override
  {
    // not ok
  }
  void scan(Document &doc) override
  {
    // ok
  }
  void fax(Document &doc) override
  {
    // not ok
  }
};

struct IPrinter
{
  virtual void print(Document &doc) = 0;
};

struct IScanner
{
  virtual void scan(Document &doc) = 0;
};

struct IFax
{
  virtual void fax(Document &doc) = 0;
};

struct Printer : IPrinter
{
  void print(Document &doc) override
  {
    // not ok
  }
};

struct IDevice : IPrinter, IScanner
{
};

struct Device : IDevice
{
  IPrinter &printer;
  IScanner &scanner;

  Device(IPrinter &printer, IScanner &scanner) : printer(printer), scanner(scanner) {}

  void print(Document &doc) override { printer.print(doc); }
  void scan(Document &doc) override { scanner.scan(doc); }
};

int main() { return 0; }
