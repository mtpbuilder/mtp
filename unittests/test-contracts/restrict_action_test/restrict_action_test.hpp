#pragma once

#include <mtpio/mtpio.hpp>

class [[mtpio::contract]] restrict_action_test : public mtpio::contract {
public:
   using mtpio::contract::contract;

   [[mtpio::action]]
   void noop( );

   [[mtpio::action]]
   void sendinline( mtpio::name authorizer );

   [[mtpio::action]]
   void senddefer( mtpio::name authorizer, uint32_t senderid );


   [[mtpio::action]]
   void notifyinline( mtpio::name acctonotify, mtpio::name authorizer );

   [[mtpio::action]]
   void notifydefer( mtpio::name acctonotify, mtpio::name authorizer, uint32_t senderid );

   [[mtpio::on_notify("testacc::notifyinline")]]
   void on_notify_inline( mtpio::name acctonotify, mtpio::name authorizer );

   [[mtpio::on_notify("testacc::notifydefer")]]
   void on_notify_defer( mtpio::name acctonotify, mtpio::name authorizer, uint32_t senderid );
};
