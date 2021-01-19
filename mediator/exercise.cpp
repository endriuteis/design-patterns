
#include <iostream>
#include <vector>
using namespace std;

struct IParticipant
{
  virtual ~IParticipant() = default;
  virtual void notify(IParticipant* sender, int value) = 0;
};

struct Mediator
{
  vector<IParticipant*> participants;
  void say(IParticipant* sender, int value)
  {
    for (auto p : participants) p->notify(sender, value);
  }
};

struct Participant : IParticipant
{
  int value{0};
  Mediator& mediator;

  Participant(Mediator& mediator) : mediator(mediator) { mediator.participants.push_back(this); }

  void notify(IParticipant* sender, int value) override
  {
    if (sender != this) this->value += value;
  }

  void say(int value) { mediator.say(this, value); }
};

int main()
{
  Mediator m;
  Participant p1{m}, p2{m};

  cout << "p1's value: " << p1.value << endl;
  cout << "p2's value: " << p2.value << endl;

  p1.say(2);

  cout << "p1's value: " << p1.value << endl;
  cout << "p2's value: " << p2.value << endl;

  p2.say(4);

  cout << "p1's value: " << p1.value << endl;
  cout << "p2's value: " << p2.value << endl;
}