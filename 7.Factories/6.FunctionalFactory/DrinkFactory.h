#ifndef INC_5_ABSTRACTFACTORY_DRINKFACTORY_H
#define INC_5_ABSTRACTFACTORY_DRINKFACTORY_H

#include <map>
#include <functional>

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

/**
 * Adding functional factory here as an example
 * It simplifies adding default parameters per different factories
 */
class DrinkWithVolumeFactory
{
    std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factories;

public:
    DrinkWithVolumeFactory()
    {
        factories["tea"] = [] {
            auto tea = std::make_unique<Tea>();
            tea->prepare(200);
            return tea;
        };
    }

    std::unique_ptr<HotDrink> make_drink(const std::string& name)
    {
        return factories[name]();
    }
};

#endif //INC_5_ABSTRACTFACTORY_DRINKFACTORY_H
