#include <iostream>
#include <memory>
using namespace std;

struct BankAccount
{
  virtual ~BankAccount() = default;
  virtual void deposit(int amount) = 0;
  virtual void withdraw(int amount) = 0;
};

struct CurrentAccount : BankAccount  // checking
{
  explicit CurrentAccount(const int balance) : balance(balance) {}

  void deposit(int amount) override { balance += amount; }

  void withdraw(int amount) override
  {
    if (amount <= balance) balance -= amount;
  }

  friend ostream& operator<<(ostream& os, const CurrentAccount& obj) { return os << "balance: " << obj.balance; }

 private:
  int balance;
};

int main()
{
  BankAccount* a = new CurrentAccount(123);
  a->deposit(321);
  delete a;

  // getting a smart pointer that behaves just as an ordinary pointer
  auto b = make_shared<CurrentAccount>(123);
  BankAccount* actual = b.get();
  b->deposit(321);

  return 0;
}