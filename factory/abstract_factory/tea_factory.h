#pragma once
#include "hot_drink_factory.h"

struct TeaFactory : HotDrinkFactory
{
  unique_ptr<HotDrink> make() const override { return make_unique<Tea>(); }
};
