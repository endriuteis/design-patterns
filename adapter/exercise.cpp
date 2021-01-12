#include <iostream>

using namespace std;

struct Square
{
  int side{0};

  explicit Square(const int side) : side(side) {}
};

struct Rectangle
{
  virtual int width() const = 0;
  virtual int height() const = 0;

  int area() const { return width() * height(); }
};

struct SquareToRectangleAdapter : Rectangle
{
  SquareToRectangleAdapter(const Square& square)
  {
    w = square.side;
    h = square.side;
  }

  int width() const override { return w; }
  int height() const override { return h; }

 private:
  int w;
  int h;
};

int main()
{
  Square sq{11};
  SquareToRectangleAdapter adapter{sq};
  cout << adapter.area() << endl;
}