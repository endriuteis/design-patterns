/*
    "You should be able to substitute a base type for a subtype."
*/

#include <boost/lexical_cast.hpp>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace boost;

class Rectangle
{
 protected:
  int width, height;

 public:
  Rectangle(int width, int height) : width(width), height(height) {}

  int getWidth() const { return width; }

  virtual int setWidth(int width) { Rectangle::width = width; }

  int getHeigth() const { return height; }

  virtual int setHeight(int height) { Rectangle::height = height; }

  int area() const { return width * height; }
};

class Square : public Rectangle
{
 public:
  Square(int size) : Rectangle(size, size) {}

  int setWidth(int width) override { this->width = this->height = width; }

  int setHeight(int height) override { this->width = this->height = height; }
};

void process(Rectangle &r)
{
  int w = r.getWidth();
  r.setHeight(10);

  cout << "expected area = " << (w * 10) << ", got " << r.area() << endl;
}

struct RectangleFActory
{
  static Rectangle create_rectangle(int w, int h);
  static Rectangle create_sqaure(int size);
};

int main()
{
  Rectangle r{3, 4};
  process(r);

  Square sq{5};
  process(sq);
  return 0;
}
