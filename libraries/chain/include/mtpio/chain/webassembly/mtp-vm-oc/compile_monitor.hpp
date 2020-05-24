#pragma once

#include <mtpio/chain/webassembly/mtp-vm-oc/config.hpp>

#include <boost/asio/local/datagram_protocol.hpp>
#include <mtpio/chain/webassembly/mtp-vm-oc/ipc_helpers.hpp>

namespace mtpio { namespace chain { namespace mtpvmoc {

wrapped_fd get_connection_to_compile_monitor(int cache_fd);

}}}