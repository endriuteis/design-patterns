#include <iostream>
using namespace std;

struct Command
{
  enum Action
  {
    deposit,
    withdraw
  } action;
  int amount{0};
  bool success{false};
};

struct Account
{
  int balance{0};

  void process(Command& cmd)
  {
    switch (cmd.action)
    {
      case Command::deposit:
        balance += cmd.amount;
        cmd.success = true;
        break;
      case Command::withdraw:
        cmd.success = (balance >= cmd.amount);
        if (cmd.success) balance -= cmd.amount;
        break;
    }
  }
};

int main()
{
  Account a;
  cout << boolalpha;
  cout << "Initial balance: " << a.balance << endl;
  Command command{Command::deposit, 100};
  a.process(command);

  cout << "Deposit of 100: " << a.balance << endl;
  cout << "Command succesfull: " << command.success << endl;

  command = Command{Command::withdraw, 50};
  a.process(command);

  cout << "Withdraw of 50: " << a.balance << endl;
  cout << "Command succesfull: " << command.success << endl;

  command = Command{Command::withdraw, 150};
  a.process(command);

  cout << "Withdraw of 150: " << a.balance << endl;
  cout << "Command succesfull: " << command.success << endl;
}