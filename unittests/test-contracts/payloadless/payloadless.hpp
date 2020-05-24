#pragma once

#include <mtpio/mtpio.hpp>

class [[mtpio::contract]] payloadless : public mtpio::contract {
public:
   using mtpio::contract::contract;

   [[mtpio::action]]
   void doit();
};
