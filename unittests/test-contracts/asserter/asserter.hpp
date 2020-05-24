#pragma once

#include <mtpio/mtpio.hpp>

class [[mtpio::contract]] asserter : public mtpio::contract {
public:
   using mtpio::contract::contract;

   [[mtpio::action]]
   void procassert( int8_t condition, std::string message );

   [[mtpio::action]]
   void provereset();
};
