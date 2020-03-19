#include <iostream>

struct Square
{
    int side{ 0 };


    explicit Square(const int side)
            : side(side)
    {
    }
};

struct Rectangle
{
    virtual int width() const = 0;
    virtual int height() const = 0;

    int area() const
    {
        return width() * height();
    }
};

struct SquareToRectangleAdapter : Rectangle
{
    Square square;

    SquareToRectangleAdapter(const Square& square) : square(square.side) {}

    int width() const override {
        return square.side;
    }

    int height() const override {
        return square.side;
    }
};

int main() {
    Square square{3};
    SquareToRectangleAdapter sqTrA{square};


    return 0;
}
