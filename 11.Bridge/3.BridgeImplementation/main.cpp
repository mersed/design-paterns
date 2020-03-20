/**
 * To ilustrate a Bridge patern principle, we will use example bellow.
 * Lets say that we want to have some kind of shapes, and we want to have
 * different ways of drawing those shapes.
 *
 * Square, Circle ... and we can have Raster and Vector rendering.
 * In standard implementation we would need to create 4 different classes
 * for this ... RasterSquare, VectorSquare, RasterCircle, VectorCircle ...
 *
 * Now, consider that we have 10 shapes... and 3 types of rendering. We would
 * need to have 30 different objects.
 *
 * Bridge allows us to implement this in much generic way.
 * We will create our Renderer as an interface, and then we will implement
 * every single of these Render ways.
 *
 * After that, we will implement a shape, as an interface, and within that
 * interface we will indicate right away, that any of the shapes we create
 * will accept a type of rendering in a constructor and will save that reference
 * for future usuage.
 *
 * Like that, intance of rendener will be created separately, will be passed
 * to the specific shape, and that shape will use that rendering in its own
 * methods (like draw).. That link between shapes and the renderers in this
 * kind of dependency injection way is called Bridge.
 */
#include <iostream>

struct Renderer
{
    virtual void render_circle(float x, float y, float radious) = 0;
};

struct VectorRenderer : Renderer
{
    void render_circle(float x, float y, float radious) override {
        std::cout << "Drawing circle of radious " << radious << std::endl;
    }
};

struct RasterRendered : Renderer
{
    void render_circle(float x, float y, float radious) override {
        std::cout << "Rasterizing circle of radious " << radious << std::endl;
    }
};

struct Shape
{
protected:
    Renderer& rendered;
    Shape(Renderer &rendered) : rendered(rendered) {}

public:
    virtual void draw() = 0;
    virtual void resize(float factor) = 0;

};

struct Circle : Shape
{
    float x, y, radious;

    Circle(Renderer &rendered, float x, float y, float radious) : Shape(rendered), x(x), y(y), radious(radious) {}

    void draw() override {
        rendered.render_circle(x, y, radious);
    }

    void resize(float factor) override {
        radious *= factor;
    }
};

int main() {
    RasterRendered rr;
    Circle raster_circle{rr, 5, 5, 5};
    raster_circle.draw();
    raster_circle.resize(2);
    raster_circle.draw();
    return 0;
}
