#include <iostream>
#include <cmath>

/**
 * Instead of just using a separate methods within our original class,
 * as in previous example, what we can do is - we can extract these methods
 * in the separate class -> and make that class as a Factory class
 * which will be used to access to the private constructs of the original class
 */
enum class PointType
{
    cartesian,
    polar
};

class Point
{
    friend class PointFactory;

    float x, y;

    Point(float x, float y) : x(x), y(y) {}

public:
    friend std::ostream &operator<<(std::ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
};

struct PointFactory
{
    static Point NewCartesian(float x, float y)
    {
        return Point{x, y};
    }

    static Point NewPolar(float r, float theta)
    {
        return Point{static_cast<float>(r * cos(theta)), static_cast<float>(r * sin(theta))};
    }
};

int main() {
    Point point = PointFactory::NewPolar(5, M_PI_4);
    std::cout << point << std::endl;

    return 0;
}
