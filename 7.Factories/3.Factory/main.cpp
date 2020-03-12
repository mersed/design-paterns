#include <iostream>
#include <cmath>

/**
 * One of the ways to overcome this issue is to use factory method.
 * Instead of using constructor directly, we will:
 * - create privately constructor
 * - create two static methods for two types of coordinates
 * - use constructor within those methods and return created instance
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
