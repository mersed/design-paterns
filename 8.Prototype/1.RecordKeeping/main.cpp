/**
 * Motivation for having a patern in first place is copying the object (cloning).
 * Lets say that we want to create two contacts bellow ... Contacts are going to be decently similar ...
 * Both persons will live in the same city and the street and building, just apartment will be different.
 *
 * We can construct these two by invoking the constructor for both of the objects ... and create them
 * independently ... or we could create them using "prototype", by copying one object to another
 * and then changing the objects properties ... like that making two independent different objects using the
 * "short" way.
 *
 * Now, obviously, this is a trivial example. However, this is really beneficial, when we are talking about
 * the objects for which construction more processing power is needed or something like that. Or for a huge and
 * large objects or for a lot of objects where we can create one prototype and rest of the objects from that
 * prototype.
 */
#include <iostream>


struct Address
{
    std::string street, city;
    int suite;

    Address(const std::string &street, const std::string &city, int suite) : street(street), city(city), suite(suite) {}

    friend std::ostream &operator<<(std::ostream &os, const Address &address) {
        os << "street: " << address.street << " city: " << address.city << " suite: " << address.suite;
        return os;
    }
};

struct Contact
{
    std::string name;
    Address address;

    Contact(const std::string &name, const Address &address) : name(name), address(address) {}

    friend std::ostream &operator<<(std::ostream &os, const Contact &contact) {
        os << "name: " << contact.name << " address: " << contact.address;
        return os;
    }
};
int main() {
    Contact john{"John Doe", Address{"123 East Dr", "London", 123}};
    // Contact jane{"Jane Smith", Address{"123 East Dr", "London", 103}};
    Contact jane = john;
    jane.name = "Jane Smith";
    jane.address.suite = 103;


    std::cout << john << std::endl << jane << std::endl;

    return 0;
}
