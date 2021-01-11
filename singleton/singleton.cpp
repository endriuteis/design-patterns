#include <boost/lexical_cast.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace boost;
using namespace std;

class Database
{
 public:
  virtual int get_population(const std::string& name) = 0;
};

class SingletonDatabase : public Database
{
  SingletonDatabase()
  {
    std::ifstream ifs("capitals.txt");

    std::string s, s2;
    while (getline(ifs, s))
    {
      getline(ifs, s2);
      int pop = boost::lexical_cast<int>(s2);
      capitals[s] = pop;
    }
  }

  std::map<std::string, int> capitals;

 public:
  SingletonDatabase(SingletonDatabase const&) = delete;
  void operator=(SingletonDatabase const&) = delete;

  static SingletonDatabase& get()
  {
    static SingletonDatabase db;
    return db;
  }

  int get_population(const std::string& name) { return capitals[name]; }
};

class DummyDatabase : public Database
{
  std::map<std::string, int> capitals;

 public:
  DummyDatabase()
  {
    capitals["alpha"] = 1;
    capitals["beta"] = 2;
    capitals["gamma"] = 3;
  }

  int get_population(const std::string& name) override { return capitals[name]; }
};

struct SingletonRecordFinder
{
  int total_population(std::vector<std::string> names)
  {
    int result = 0;
    for (auto& name : names) result += SingletonDatabase::get().get_population(name);
    return result;
  }
};

struct ConfigurableRecordFinder
{
  explicit ConfigurableRecordFinder(Database& db) : db{db} {}

  int total_population(std::vector<std::string> names) const
  {
    int result = 0;
    for (auto& name : names) result += db.get_population(name);
    return result;
  }

  Database& db;
};

int main()
{
  string city = "Tokyo";
  cout << city << " has population " << SingletonDatabase::get().get_population(city) << endl;

  SingletonRecordFinder rf;
  vector<string> names{"Seoul", "Mexico City"};
  cout << rf.total_population(names) << endl;

  DummyDatabase db;
  ConfigurableRecordFinder crf{db};
  cout << crf.total_population({"alpha", "gamma"}) << endl;
}