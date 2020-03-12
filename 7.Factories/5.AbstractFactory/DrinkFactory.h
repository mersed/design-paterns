#ifndef INC_5_ABSTRACTFACTORY_DRINKFACTORY_H
#define INC_5_ABSTRACTFACTORY_DRINKFACTORY_H

#include <map>

#include "HotDrink.h"
#include "HotDrinkFactory.h"

class DrinkFactory
{
    std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_factories;

public:
    DrinkFactory()
    {
        hot_factories["coffe"] = std::make_unique<CoffeFactory>();
        hot_factories["tea"] = std::make_unique<TeaFactory>();
    }

    std::unique_ptr<HotDrink> make_drink(const std::string type)
    {
        auto drink = hot_factories[type]->make();
        drink->prepare(200);
        return drink;
    }
};

#endif //INC_5_ABSTRACTFACTORY_DRINKFACTORY_H
