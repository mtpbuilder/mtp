#pragma once

#include <mtpio/mtpio.hpp>

class [[mtpio::contract]] ram_restrictions_test : public mtpio::contract {
public:
   struct [[mtpio::table]] data {
      uint64_t           key;
      std::vector<char>  value;

      uint64_t primary_key() const { return key; }
   };

   typedef mtpio::multi_index<"tablea"_n, data> tablea;
   typedef mtpio::multi_index<"tableb"_n, data> tableb;

public:
   using mtpio::contract::contract;

   [[mtpio::action]]
   void noop();

   [[mtpio::action]]
   void setdata( uint32_t len1, uint32_t len2, mtpio::name payer );

   [[mtpio::action]]
   void notifysetdat( mtpio::name acctonotify, uint32_t len1, uint32_t len2, mtpio::name payer );

   [[mtpio::on_notify("tester2::notifysetdat")]]
   void on_notify_setdata( mtpio::name acctonotify, uint32_t len1, uint32_t len2, mtpio::name payer );

   [[mtpio::action]]
   void senddefer( uint64_t senderid, mtpio::name payer );

   [[mtpio::action]]
   void notifydefer( mtpio::name acctonotify, uint64_t senderid, mtpio::name payer );

   [[mtpio::on_notify("tester2::notifydefer")]]
   void on_notifydefer( mtpio::name acctonotify, uint64_t senderid, mtpio::name payer );

};
