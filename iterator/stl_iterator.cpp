#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  vector<string> names{"john", "jane", "jill", "jack"};
  vector<string>::iterator it = names.begin();  // or std::begin(names)
  cout << "first name is " << *it << endl;

  ++it;
  it->append(string(" goodall "));
  cout << "second name is " << *it << endl;

  while (++it != names.end())
  {
    cout << "another name: " << *it << endl;
  }

  for (auto ri = rbegin(names); ri != rend(names); ++ri)
  {
    cout << *ri;
    if (ri + 1 != rend(names)) cout << ",";
  }
  cout << endl;

  vector<string>::const_reverse_iterator jack = crbegin(names);
  //*jack += string("reacher") // not allowed

  // begin/end need to be implemented
  // auto&& name = *it
  for (auto&& name : names) cout << "name = " << name << endl;
  return 0;
}