#include "Person.h"
#include <iostream>

class Person::PersonImpl
{
public:
    void greet(Person* person);
};

void Person::PersonImpl::greet(Person *person) {
    std::cout << "Hello, my name is " << person->name << std::endl;
}

Person::Person(std::string name) : impl(new PersonImpl), name(name) {}

Person::~Person() {
    delete impl;
}

void Person::greet()
{
    impl->greet(this);
}
