#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CombinationLock
{
  vector<int> combination;
  int digits_entered{0};
  bool failed{false};

  void reset()
  {
    status = "LOCKED";
    digits_entered = 0;
    failed = false;
  }

 public:
  string status;

  CombinationLock(const vector<int> &combination) : combination(combination) { reset(); }

  void enter_digit(int digit)
  {
    if (status == "LOCKED") status = "";
    status += to_string(digit);
    if (combination[digits_entered] != digit)
    {
      failed = true;
    }
    digits_entered++;

    if (digits_entered == combination.size()) status = failed ? "ERROR" : "OPEN";
  }
};

int main()
{
  // TestSuccess
  CombinationLock cl1({1, 2, 3});
  cout << cl1.status << endl;
  ;

  cl1.enter_digit(1);
  cout << cl1.status << endl;
  ;

  cl1.enter_digit(2);
  cout << cl1.status << endl;
  ;

  cl1.enter_digit(3);
  cout << cl1.status << endl;
  ;

  // TestFailure
  CombinationLock cl2({1, 2, 3});
  cout << cl2.status << endl;
  ;
  cl2.enter_digit(1);
  cout << cl2.status << endl;
  ;
  cl2.enter_digit(2);
  cout << cl2.status << endl;
  ;
  cl2.enter_digit(5);
  cout << cl2.status << endl;
  ;
}