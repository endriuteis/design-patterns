#pragma once
#include <iostream>
#include <string>

using namespace std;

class PersonBuilder;

class Person
{
    //address
    string street_address, post_code, city;

    //employment
    string company_name, position;
    int annual_income{0};

public:
    static PersonBuilder create();

    friend std::ostream &operator<<(std::ostream &os, const Person &obj)
    {
        return os
               << "street_address: " << obj.street_address
               << " post_code: " << obj.post_code
               << " city: " << obj.city
               << " company_name: " << obj.company_name
               << " position: " << obj.position
               << " annual_income: " << obj.annual_income;
    }

    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;
};
