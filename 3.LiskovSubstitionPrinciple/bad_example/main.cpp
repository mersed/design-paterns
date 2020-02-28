/**
 * Explanation:
 *
 * In order to show LiskovSubstitution principle, lets try to break it first.
 * Lets create one class Rectangle with width and height properties.
 * Lets create process function, which will, after using a setter, expect for rectangle
 * to have specific area (calculated inside the class and outside the class)
 *
 * Initial testing shows that, after setter is executed, and after Rectangle &r is processed
 * that area is equal indeed (statement we made is true).
 *
 * Now, lets make a Square class by inheriting from rectangle.
 * Lets make setWidth and setHeight virtual so we can override them in the Square class - and
 * lets override them in the manner that we are setting up height and with in both of these
 * based on the size (which is logical, that is the square).
 *
 * Unfortunately, what we did here, violates the LiskovSubstitution principle, which says:
 * - If you have for example a function which takes a base class as a parameter, any derived
 * class should be able to be substituted into that function without any problems.
 *
 * That is not the case what is happening here, because, if we create a new instance of
 * Square class and call process function on that instance, we will see that process function
 * will not behave as we expected.
 *
 */
#include <iostream>

using namespace std;

class Rectangle
{
protected:
    int width, height;
public:
    Rectangle(int width, int height) : width(width), height(height) {}

    virtual void setWidth(int width) {
        Rectangle::width = width;
    }

    virtual void setHeight(int height) {
        Rectangle::height = height;
    }

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

    int area() const {
        return height * width;
    }
};

class Square : public Rectangle
{
public:
    Square(int size): Rectangle(size, size) {}

    void setWidth(int width) override {
        this->width = this->height = width;
    }

    void setHeight(int height) override {
        this->width = this->height = width;
    }
};

void process(Rectangle &r)
{
    int w = r.getWidth();
    r.setHeight(10);

    cout << "expected area = " << (w*10) << ", we got " << r.area() << endl;
}

int main() {
    Rectangle r{3, 4};
    process(r);

    Square s{5};
    process(s);
    return 0;
}
