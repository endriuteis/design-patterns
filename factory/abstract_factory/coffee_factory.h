#pragma once
#include "hot_drink.h"
#include "hot_drink_factory.h"
#include <memory>

struct HotDrink;

struct CoffeeFactory : HotDrinkFactory
{
  unique_ptr<HotDrink> make() const override
  {
    return make_unique<Coffee>();
  }
};
