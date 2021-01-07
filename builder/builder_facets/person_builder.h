/*
    "When piecewise object construction is complicated, provide an API for doing it succintly."
*/

#pragma once

#include "person.h"

using namespace std;

class PersonJobBuilder;
class PersonAddressBuilder;

class PersonBuilderBase
{
protected:
    Person &person;
    PersonBuilderBase(Person &person) : person(person) {}

public:
    operator Person() const
    {
        return std::move(person);
    }

    PersonJobBuilder works() const;
    PersonAddressBuilder lives() const;
};

class PersonBuilder : public PersonBuilderBase
{
    Person p;

public:
    PersonBuilder() : PersonBuilderBase{p}
    {
    }
};
