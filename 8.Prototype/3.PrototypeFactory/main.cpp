/**
 * Untill now, what we were doing is that - we created one contact (john) in main function
 * and we declared that one as our prototype (by using it for creation of another object).
 *
 * However, question is, how we will provide the prototype to the users who are going to use
 * our library? Do they know that they need to create a new object using a prototype? Do they
 * need to know how they will create a prototype by themself and similar?
 *
 * You could go with some half ass/bad solution like using a global variable .. creating prototype
 * as global - and allow anyone to copy from that ... however, there is a better and way which should
 * be used. It is Prototype factory
 */
#include <iostream>
#include <memory>


struct Address
{
    public:
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
public:
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

struct EmployeeFactory
{
    static std::unique_ptr<Contact> new_main_office_employee(const std::string &name, const int suite)
    {
        static Contact p{"", new Address{"123 East Dr", "London", 0}};
        return new_employee(name, suite, p);
    }

    static std::unique_ptr<Contact> new_employee(const std::string &name, int suite, const Contact &prototype)
    {
        auto result = std::make_unique<Contact>(prototype);
        result->name = name;
        result->address->suite = suite;
        return result;
    }
};

int main() {
    auto john = EmployeeFactory::new_main_office_employee("John", 123);

    std::cout << *john << std::endl;

    return 0;
}
