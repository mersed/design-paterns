#include "DrinkFactory.h"

int main() {
    DrinkFactory df;
    auto tea = df.make_drink("tea");
    auto coffe = df.make_drink("coffe");

    return 0;
}
