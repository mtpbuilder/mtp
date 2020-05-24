#pragma once

#include <mtpio/mtpio.hpp>

class [[mtpio::contract]] noop : public mtpio::contract {
public:
   using mtpio::contract::contract;

   [[mtpio::action]]
   void anyaction( mtpio::name                       from,
                   const mtpio::ignore<std::string>& type,
                   const mtpio::ignore<std::string>& data );
};
