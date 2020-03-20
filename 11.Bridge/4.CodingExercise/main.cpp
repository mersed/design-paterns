#include <string>
using namespace std;


struct Renderer
{
    virtual string what_to_render_as(string name) const = 0;
};

struct VectorRenderer : Renderer
{
    string what_to_render_as(string name) const override {
        return "Drawing " + name + " as lines";
    }
};

struct RasterRenderer : Renderer
{
    string what_to_render_as(string name) const override {
        return "Drawing " + name + " as pixels";
    }
};

struct Shape
{
protected:
    const Renderer& renderer;
    string name;

    Shape(const string name, const Renderer& renderer) : name(name), renderer(renderer) {}

public:
    string str()
    {
        return renderer.what_to_render_as(name);
    }
};

struct Triangle : Shape
{
    Triangle(const Renderer& renderer) : Shape("Circle", renderer) {}
};

struct Square : Shape
{
    Square(const Renderer& renderer) : Shape("Square", renderer) {}
};

#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
