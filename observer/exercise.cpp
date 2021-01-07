#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct IRat
{
    virtual void SetAttack(int num) = 0;
};

struct Game
{
    std::vector<IRat *> rats;

    void subscribe(IRat *rat)
    {
        rats.push_back(rat);
        for (auto rat : rats)
            rat->SetAttack(rats.size());

    }

    void unsubscribe(IRat *rat)
    {
        rats.erase(
            remove(rats.begin(), rats.end(), rat),
            rats.end());
        for (auto rat : rats)
            rat->SetAttack(rats.size());
    }
};

struct Rat : public IRat
{
    Game &game;
    int attack{1};

    Rat(Game &game) : game(game)
    {
        game.subscribe(this);
    }

    ~Rat()
    {
        game.unsubscribe(this);
    }

    void SetAttack(int num) override { attack = num; };
};

int main(int ac, char *av[])
{
    Game game;
    Rat rat1{game};
    Rat rat2{game};
    cout << rat1.attack << endl;
    cout << rat2.attack << endl;
}
