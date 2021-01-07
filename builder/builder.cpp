/*
    "When piecewise object construction is complicated, provide an API for doing it succintly."
*/

#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

struct HtmlBuilder;

// Utility class for modeling HTML element in an object oriented way
class HtmlElement
{
  friend HtmlBuilder;

  string name, text;
  vector<HtmlElement> elements;

  const size_t indent_size = 2;

  HtmlElement(){};
  HtmlElement(const string &name, const string &text) : name(name), text(text) {}

 public:
  string str(int indent = 0) const
  {
    ostringstream oss;
    string i(indent_size * indent, ' ');
    oss << i << "<" << name << ">" << endl;
    if (text.size() > 0) oss << string(indent_size * (indent + 1), ' ') << text << endl;

    for (const auto &e : elements) oss << e.str(indent + 1);

    oss << i << "</" << name << ">" << endl;
    return oss.str();
  }

  static unique_ptr<HtmlBuilder> create(string root_name) { return make_unique<HtmlBuilder>(root_name); }
};

// Builder
struct HtmlBuilder
{
  HtmlElement root;

  HtmlBuilder(string root_name) { root.name = root_name; }

  HtmlBuilder &add_child(string child_name, string child_text)
  {
    HtmlElement e{child_name, child_text};
    root.elements.emplace_back(e);
    return *this;
  }

  HtmlBuilder *add_child_2(string child_name, string child_text)
  {
    HtmlElement e{child_name, child_text};
    root.elements.emplace_back(e);
    return this;
  }

  string str() const { return root.str(); }

  operator HtmlElement() const { return root; }

  HtmlElement build() { return root; }
};

int main()
{
  // first approach
  auto text = "hello";
  string output;
  output += "<p>";
  output += text;
  output += "</p>";
  cout << output << endl;

  // secong approach
  string words[] = {"hello", "world"};
  ostringstream oss;
  oss << "<ul>";
  for (auto w : words) oss << " <li> " << w << "</li>";
  oss << "</ul>";
  cout << oss.str() << endl;

  // builder
  HtmlBuilder builder{"ul"};
  builder.add_child("li", "hello").add_child("li", "world");
  cout << builder.str() << endl;

  HtmlElement elem = HtmlElement::create("ul")->add_child("", "").build();
}
