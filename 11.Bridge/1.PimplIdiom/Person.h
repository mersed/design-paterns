#ifndef INC_1_PIMPLIDIOM_PERSON_H
#define INC_1_PIMPLIDIOM_PERSON_H

#include <string>

class Person {
public:
    std::string name;

    class PersonImpl;
    PersonImpl* impl;

    Person(std::string name);

    ~Person();

    void greet();
};


#endif //INC_1_PIMPLIDIOM_PERSON_H
