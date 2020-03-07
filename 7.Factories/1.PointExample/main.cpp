#include <cmath>

/**
 * Lets say that we want to create a class which will represent a Point.
 * Which coordinates we are going to use, cartesian on polar.
 *
 * How we will distinction this in the constructor? Maybe we can create an if
 * statement to make a difference between these two types during assigment?
 *
 * However, this is not a good solution. Both coordinates are assigned to x, y ...
 * What is assigned to x and what to y... Code is hard to follow and not really
 * readable. Sure, we could add some documentation, but that will not make this
 * example any more good, due to the fact that we will still have constructor
 * limitations.
 */
enum class PointType
{
    cartesian,
    polar
};

struct Point
{
    float x, y;

    // Point(float x, float y) : x(x), y(y) {}

    Point(float a, float b, PointType type = PointType::cartesian)
    {
        if(type == PointType::cartesian)
        {
            x = a;
            x = b;
        }
        else
        {
            x = a * cos(b);
            y = a * sin(b);
        }
    }
};

int main() {
    Point point = Point{5, 10};

    return 0;
}
