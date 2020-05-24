#pragma once
#include <fc/variant.hpp>
#include <mtpio/trace_api/trace.hpp>
#include <mtpio/chain/abi_def.hpp>
#include <mtpio/chain/protocol_feature_activation.hpp>

namespace mtpio { namespace trace_api {

   using data_log_entry = fc::static_variant<
      block_trace_v0
   >;

}}
