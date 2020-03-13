/**
 * Now, in main.cpp we made an ideal scenario, where everything is working - and everything is kept as
 * an value (for example an address).
 *
 * Now, situation decently complicates if we have an object which does not contain only values as its
 * own properties. What if that object contains property which is a pointer to another object in memory?
 *
 * This makes copying (creating an object from a prototype much harder). And this is - usually - a real life
 * scenario which we can encounter.
 *
 * You can see the same example bellow, just address is stored as a pointer - and if we use the same method
 * as we did in main.cpp, we will have an issue. Because when we start changing values for the second object
 * we will change values for the first object as well (because both of them are using same pointer for address)
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
    Address *address;

    Contact(const std::string &name, Address *address) : name(name), address(address) {}

    friend std::ostream &operator<<(std::ostream &os, const Contact &contact) {
        os << "name: " << contact.name << " address: " << *contact.address;
        return os;
    }
};
int main() {
    Address *address = new Address{"123 East Dr", "London", 123};
    Contact john{"John Doe", address};
    // Contact jane{"Jane Smith", Address{"123 East Dr", "London", 103}};
    Contact jane = john;
    jane.name = "Jane Smith";
    jane.address->suite = 103;


    std::cout << john << std::endl << jane << std::endl;

    return 0;
}
