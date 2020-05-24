#pragma once

#include <mtpio/mtpio.hpp>

class [[mtpio::contract]] integration_test : public mtpio::contract {
public:
   using mtpio::contract::contract;

   [[mtpio::action]]
   void store( mtpio::name from, mtpio::name to, uint64_t num );

   struct [[mtpio::table("payloads")]] payload {
      uint64_t              key;
      std::vector<uint64_t> data;

      uint64_t primary_key()const { return key; }

      MTPLIB_SERIALIZE( payload, (key)(data) )
   };

   using payloads_table = mtpio::multi_index< "payloads"_n,  payload >;

};
