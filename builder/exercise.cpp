#include <iostream>
#include <string>
using namespace std;

class CodeBuilder
{
public:
  CodeBuilder(const string &class_name)
  {
    output += "class " + class_name + "\n{\n";
  }

  CodeBuilder &add_field(const string &name, const string &type)
  {
    output += "  " + type + " " + name + ";\n";
    return *this;
  }

  friend ostream &operator<<(ostream &os, const CodeBuilder &obj)
  {
    return os << obj.output << "};\n";
    ;
  }

private:
  string output;
};

int main()
{
  auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
  cout << cb;
  return 0;
}
