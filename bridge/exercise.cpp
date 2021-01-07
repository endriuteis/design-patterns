#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Renderer
{
    virtual string what_to_render_as() const = 0;
};

struct Shape
{
    public:
        Shape(const Renderer& renderer) : renderer(renderer){}
        const Renderer& renderer;
        string name;

        string str() const
        {
            ostringstream oss;
            oss << "Drawing " << name << " as "
            << renderer.what_to_render_as();
            return oss.str();
        }
};

struct Triangle : Shape
{
    Triangle(const Renderer& renderer) : Shape(renderer)
    {
        name = "Triangle";
    }
};

struct Square : Shape
{
    Square(const Renderer& renderer) : Shape(renderer)
    {
        name = "Square";
    }
};

struct VectorRenderer : Renderer
{
    string what_to_render_as() const override
    {
        return "lines";
    }
};

struct RasterRenderer : Renderer
{
    string what_to_render_as() const override
    {
        return "lines";
    }
};

// imagine e.g. VectorTriangle/RasterTriangle etc. here
