#pragma once
#include <memory>
#include "hot_drink.h"
#include "hot_drink_factory.h"

struct HotDrink;

struct CoffeeFactory : HotDrinkFactory
{
  unique_ptr<HotDrink> make() const override { return make_unique<Coffee>(); }
};
