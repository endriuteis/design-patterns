#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "person.h"
#include "person_address_builder.h"
#include "person_builder.h"
#include "person_job_builder.h"

using namespace std;

int main()
{
    Person p = Person::create()
                   .lives()
                   .at("123 London Road")
                   .with_postcode("SW1 1GB")
                   .in("London")
                   .works()
                   .at("FCA")
                   .as_a("Software Engineer")
                   .earning(1000);

    cout << p << endl;
    return 0;
}
