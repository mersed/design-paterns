#ifndef INC_5_ABSTRACTFACTORY_HOTDRINKFACTORY_H
#define INC_5_ABSTRACTFACTORY_HOTDRINKFACTORY_H

#include "HotDrink.h"

struct HotDrinkFactory
{
    virtual std::unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory : HotDrinkFactory
{
    std::unique_ptr<HotDrink> make() const override {
        return std::make_unique<Tea>();
    }
};

struct CoffeFactory : HotDrinkFactory
{
    std::unique_ptr<HotDrink> make() const override {
        return std::make_unique<Coffe>();
    }
};

#endif //INC_5_ABSTRACTFACTORY_HOTDRINKFACTORY_H
