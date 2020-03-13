/**
 * Best way to implement deep copy is to implement copy constructor.
 * Constructor will take another contact as its argument and will simply attemt to relicate
 * all the members/properties of the contact.
 */
#include <iostream>


struct Address
{
    std::string street, city;
    int suite;

    Address(const std::string &street, const std::string &city, int suite) : street(street), city(city), suite(suite) {}

    Address(const Address &address) : street(address.street), city(address.city), suite(address.suite) {}

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

    Contact(const Contact &other) : name{other.name}, address{new Address{*other.address}} {}

    ~Contact() { delete address; }

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
    delete address;

    return 0;
}
