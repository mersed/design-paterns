#ifndef INC_5_ABSTRACTFACTORY_HOTDRINK_H
#define INC_5_ABSTRACTFACTORY_HOTDRINK_H

#include <iostream>
#include <memory>

struct HotDrink
{
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
    void prepare(int volume) override {
        std::cout << "Using tea bag, boil watter, pour " << volume
                  << "ml, add some lemon" << std::endl;
    }
};

struct Coffe : HotDrink
{
    void prepare(int volume) override {
        std::cout << "Grind some beans, boil watter, pour " << volume
                  << "ml, add cream, enjoy" << std::endl;
    }
};

#endif //INC_5_ABSTRACTFACTORY_HOTDRINK_H
