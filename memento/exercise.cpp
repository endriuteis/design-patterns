#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct Token
{
  int value;

  Token(int value) : value(value) {}
};

struct Memento
{
  vector<shared_ptr<Token>> tokens;
};

struct TokenMachine
{
  vector<shared_ptr<Token>> tokens;

  Memento add_token(int value)
  {
    return add_token(make_shared<Token>(value));
  }

  // adds the token to the set of tokens and returns the
  // snapshot of the entire system
  Memento add_token(const shared_ptr<Token> &token)
  {
    tokens.push_back(token);
    Memento m;
    for (auto t : tokens)
      m.tokens.emplace_back(make_shared<Token>(t->value));
    return m;
  }

  // reverts the system to a state represented by the token
  void revert(const Memento &m)
  {
    tokens.clear();
    for (auto t : m.tokens)
      tokens.emplace_back(make_shared<Token>(t->value));
  }
};

int main()
{
  TokenMachine tm;
  Memento m1 = tm.add_token(111);
  Memento m2 = tm.add_token(333);
  cout << tm.tokens.back()->value << endl;
  tm.revert(m1);
  cout << tm.tokens.back()->value << endl;
  shared_ptr<Token> token_ptr = make_shared<Token>(222);
  tm.add_token(token_ptr);
  cout << tm.tokens.back()->value << endl;
  token_ptr->value = 444;
  cout << tm.tokens.back()->value << endl;
  return 0;
}
