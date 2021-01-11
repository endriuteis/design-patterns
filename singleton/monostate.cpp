using namespace std;

class Printer
{
 public:
  int get_id() const { return id; };
  void set_id(int value) { id = value; }

 private:
  static int id;
};
int Printer::id = 1;

int main()
{
  Printer p;
  int id = p.get_id();

  Printer p2;
}