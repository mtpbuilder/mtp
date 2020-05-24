#pragma once

#include <mtpio/chain/types.hpp>
#include <mtpio/chain/contract_types.hpp>

namespace mtpio { namespace chain {

   class apply_context;

   /**
    * @defgroup native_action_handlers Native Action Handlers
    */
   ///@{
   void apply_mtpio_newaccount(apply_context&);
   void apply_mtpio_updateauth(apply_context&);
   void apply_mtpio_deleteauth(apply_context&);
   void apply_mtpio_linkauth(apply_context&);
   void apply_mtpio_unlinkauth(apply_context&);

   /*
   void apply_mtpio_postrecovery(apply_context&);
   void apply_mtpio_passrecovery(apply_context&);
   void apply_mtpio_vetorecovery(apply_context&);
   */

   void apply_mtpio_setcode(apply_context&);
   void apply_mtpio_setabi(apply_context&);

   void apply_mtpio_canceldelay(apply_context&);
   ///@}  end action handlers

} } /// namespace mtpio::chain
