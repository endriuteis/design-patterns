#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

enum class PointType
{
  cartesian,
  polar
};

class Point
{
  /*Point(float a, float b, PointType type = PointType::cartesian)
{
  if (type == PointType::cartesian)
  {
    x = a; b = y;
  }
  else
  {
    x = a*cos(b);
    y = a*sin(b);
  }
}*/

  // use a factory method
  Point(float x, float y) : x(x), y(y) {}

 public:
  float x, y;

  friend class PointFactory;

  friend std::ostream &operator<<(std::ostream &os, const Point &obj)
  {
    return os << "x: " << obj.x << " y: " << obj.y;
  }
};

class PointFactory
{
 public:
  static Point NewCartesian(float x, float y) { return Point{x, y}; }

  static Point NewPolar(float r, float theta) { return Point{r * cos(theta), r * sin(theta)}; }
};

int main()
{
  // will not work
  // Point p{ 1,2 };

  auto p = PointFactory::NewPolar(5, M_PI_4);
  std::cout << p << std::endl;

  return 0;
}
