#ifndef INC_5_BUILDERFACETS_PERSON_H
#define INC_5_BUILDERFACETS_PERSON_H

#include <string>
#include <ostream>

class PersonBuilder;

class Person
{
    // address
    std::string street_address, post_code, city;

    // employment
    std::string company_name, position;
    int annual_income{0};

public:
    static PersonBuilder create();

    friend std::ostream &operator<<(std::ostream &os, const Person &person);

    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;
};


#endif //INC_5_BUILDERFACETS_PERSON_H
