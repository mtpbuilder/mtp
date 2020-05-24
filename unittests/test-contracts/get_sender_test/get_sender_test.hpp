#pragma once

#include <mtpio/mtpio.hpp>

namespace mtpio {
   namespace internal_use_do_not_use {
      extern "C" {
         __attribute__((mtpio_wasm_import))
         uint64_t get_sender();
      }
   }
}

namespace mtpio {
   name get_sender() {
      return name( internal_use_do_not_use::get_sender() );
   }
}

class [[mtpio::contract]] get_sender_test : public mtpio::contract {
public:
   using mtpio::contract::contract;

   [[mtpio::action]]
   void assertsender( mtpio::name expected_sender );
   using assertsender_action = mtpio::action_wrapper<"assertsender"_n, &get_sender_test::assertsender>;

   [[mtpio::action]]
   void sendinline( mtpio::name to, mtpio::name expected_sender );

   [[mtpio::action]]
   void notify( mtpio::name to, mtpio::name expected_sender, bool send_inline );

   // mtpio.cdt 1.6.1 has a problem with "*::notify" so hardcode to tester1 for now.
   // TODO: Change it back to "*::notify" when the bug is fixed in mtpio.cdt.
   [[mtpio::on_notify("tester1::notify")]]
   void on_notify( mtpio::name to, mtpio::name expected_sender, bool send_inline );

};
