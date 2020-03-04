#ifndef INC_5_BUILDERFACETS_PERSONBUILDER_H
#define INC_5_BUILDERFACETS_PERSONBUILDER_H

#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase
{
protected:
    Person& person;
public:
    PersonBuilderBase(Person& person);

    operator Person() const {
        return std::move(person);
    }

    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase
{
    Person p;
public:
    PersonBuilder();
};


#endif //INC_5_BUILDERFACETS_PERSONBUILDER_H
