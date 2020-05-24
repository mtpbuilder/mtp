#pragma once

#include <mtpio/mtpio.hpp>
#include <mtpio/singleton.hpp>
#include <mtpio/asset.hpp>

// Extacted from mtpio.token contract:
namespace mtpio {
   class [[mtpio::contract("mtpio.token")]] token : public mtpio::contract {
   public:
      using mtpio::contract::contract;

      [[mtpio::action]]
      void transfer( mtpio::name        from,
                     mtpio::name        to,
                     mtpio::asset       quantity,
                     const std::string& memo );
      using transfer_action = mtpio::action_wrapper<"transfer"_n, &token::transfer>;
   };
}

// This contract:
class [[mtpio::contract]] proxy : public mtpio::contract {
public:
   proxy( mtpio::name self, mtpio::name first_receiver, mtpio::datastream<const char*> ds );

   [[mtpio::action]]
   void setowner( mtpio::name owner, uint32_t delay );

   [[mtpio::on_notify("mtpio.token::transfer")]]
   void on_transfer( mtpio::name        from,
                     mtpio::name        to,
                     mtpio::asset       quantity,
                     const std::string& memo );

   [[mtpio::on_notify("mtpio::onerror")]]
   void on_error( uint128_t sender_id, mtpio::ignore<std::vector<char>> sent_trx );

   struct [[mtpio::table]] config {
      mtpio::name owner;
      uint32_t    delay   = 0;
      uint32_t    next_id = 0;

      MTPLIB_SERIALIZE( config, (owner)(delay)(next_id) )
   };

   using config_singleton = mtpio::singleton< "config"_n,  config >;

protected:
   config_singleton _config;
};
