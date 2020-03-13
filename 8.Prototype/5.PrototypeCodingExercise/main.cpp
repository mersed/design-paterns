#include <iostream>

struct Point
{
    int x{ 0 }, y{ 0 };

    Point(){}

    Point(const int x, const int y) : x{x}, y{y} {}

    friend std::ostream &operator<<(std::ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
};

struct Line
{
    Point *start, *end;

    Line(Point* const start, Point* const end)
            : start(start), end(end)
    {
    }

    ~Line()
    {
        delete start;
        delete end;
    }

    Line deep_copy() const
    {
        Point *point1 = new Point{this->start->x,this->start->y};
        Point *point2 = new Point{this->end->x,this->end->y};
        return Line{point1, point2};
    }

    friend std::ostream &operator<<(std::ostream &os, const Line &line) {
        os << "start: " << *line.start << " end: " << *line.end;
        return os;
    }
};

int main() {
    std::cout << "Checking" << std::endl;
    Point *point1 = new Point{1,1};
    Point *point2 = new Point{2,2};

    Line line1 = Line{point1, point2};
    Line line2 = line1.deep_copy();
    line2.start->x = 50;

    std::cout << line1 << std::endl << line2 << std::endl;

    return 0;
}