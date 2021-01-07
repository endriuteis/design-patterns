#include <string>
#include <sstream>
#include <iostream>
#include <concepts>

using namespace std;

struct Shape
{
    virtual string str() const = 0;
};

struct Circle : Shape
{
    float radius;

    Circle() {}

    Circle(float radius) : radius(radius) {}

    void resize(float factor)
    {
        radius *= factor;
    }

    string str() const override {
        ostringstream oss;
        oss << "A circle of radius " << radius;
        return oss.str();
    }
};

struct Square : Shape
{
    float side;

    Square()  {}

    Square(float side) : side(side) {}

    string str() const override {
        ostringstream oss;
        oss << "A square with side " << side;
        return oss.str();
    }
};

template <typename T>
concept IsAShape = std::is_base_of<Shape, T>::value;

template <IsAShape T>
struct ColoredShape : T
{
    string color;

    ColoredShape(){}

    template <typename...Args>
    ColoredShape(const string &color, Args ...args) : T(std::forward<Args>(args)...), color(color)
    {}

    string str() const override {
        ostringstream oss;
        oss << shape.str() << " has the color " << color;
        return oss.str();
    }
};

template <IsAShape T>
struct TransparentShape : T
{
    Shape& shape;
    uint8_t transparency;

    TransparentShape(uint8_t transparency) : Args ...args) : T(std::forward<Args>(args)...), transparency(transparency)
    {}

    string str() const override {
        ostringstream oss;
        oss << shape.str() << " has "
            << static_cast<float>(transparency) / 255.f * 100.f
            << "% transparency";
        return oss.str();
    }
};

int main()
{
    ColoredShape<Circle> green_circle{"green", 5};
    cout << green_circle.str() << endl;

    TransparentShape<ColoredShape<Square>> bis{0, "blue", 10};
    bis.color = "light blue";
    bis.side = 21;
    cout << bis.str() std::endl;
}