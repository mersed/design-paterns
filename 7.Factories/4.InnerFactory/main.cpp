#include <iostream>
#include <cmath>

/**
 * One more possibility / way to organize things factory related is to
 * place factory class as inner class of the original class (if factory is planed
 * to be used originally - in order to avoid violation of open closed principle later).
 *
 * Reason why maybe this would be better, is mostly because of usage of library by another
 * developer.
 *
 * If someone use Point class, he will see that most of the methods are private, however he
 * will see that there is a factory within it -> which he can use to create an instance.
 * Otherwise, user needs to be aware that there is a Point and separate Factory class.
 */
enum class PointType
{
    cartesian,
    polar
};

class Point
{
private:
    float x, y;

    Point(float x, float y) : x(x), y(y) {}

    class PointFactory
    {
    public:
        static Point NewCartesian(float x, float y)
        {
            return Point{x, y};
        }

        static Point NewPolar(float r, float theta)
        {
            return Point{static_cast<float>(r * cos(theta)), static_cast<float>(r * sin(theta))};
        }
    };

public:
    static PointFactory Factory;

    friend std::ostream &operator<<(std::ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
};

int main() {
    Point point = Point::Factory.NewPolar(5, M_PI_4);
    std::cout << point << std::endl;

    return 0;
}
