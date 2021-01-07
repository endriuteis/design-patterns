#pragma once
#include "hot_drink.h"

struct HotDrinkFactory
{
  virtual unique_ptr<HotDrink> make() const = 0;
};
