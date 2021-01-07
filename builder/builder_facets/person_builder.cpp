#include "person_builder.h"
#include "person_address_builder.h"
#include "person_job_builder.h"

using namespace std;

PersonJobBuilder PersonBuilderBase::works() const { return PersonJobBuilder{person}; }
PersonAddressBuilder PersonBuilderBase::lives() const { return PersonAddressBuilder{person}; }
