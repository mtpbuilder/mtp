#pragma once

#include <mtpio/mtpio.hpp>
#include <vector>

class [[mtpio::contract]] deferred_test : public mtpio::contract {
public:
   using mtpio::contract::contract;

   [[mtpio::action]]
   void defercall( mtpio::name payer, uint64_t sender_id, mtpio::name contract, uint64_t payload );

   [[mtpio::action]]
   void delayedcall( mtpio::name payer, uint64_t sender_id, mtpio::name contract,
                     uint64_t payload, uint32_t delay_sec, bool replace_existing );

   [[mtpio::action]]
   void deferfunc( uint64_t payload );
   using deferfunc_action = mtpio::action_wrapper<"deferfunc"_n, &deferred_test::deferfunc>;

   [[mtpio::action]]
   void inlinecall( mtpio::name contract, mtpio::name authorizer, uint64_t payload );

   [[mtpio::action]]
   void fail();

   [[mtpio::on_notify("mtpio::onerror")]]
   void on_error( uint128_t sender_id, mtpio::ignore<std::vector<char>> sent_trx );
};
