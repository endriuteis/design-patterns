#include <iostream>

struct Point
{
  int x{0}, y{0};

  Point() {}

  Point(const int x, const int y) : x{x}, y{y} {}
};

struct Line
{
  Point *start, *end;

  Line(Point *const start, Point *const end) : start(start), end(end) {}

  ~Line()
  {
    delete start;
    delete end;
  }

  Line deep_copy() const
  {
    Line line(new Point{this->start->x, this->start->y}, new Point{this->end->x, this->end->y});
    return line;
  }
};

int main()
{
  Line line(new Point{1, 2}, new Point{3, 4});
  std::cout << line.start->x << std::endl;
  Line line2 = line.deep_copy();
  std::cout << line2.start->x << std::endl;
}
