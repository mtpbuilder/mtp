#include <mtpio/chain/webassembly/mtp-vm-oc.hpp>
#include <mtpio/chain/wasm_mtpio_constraints.hpp>
#include <mtpio/chain/wasm_mtpio_injection.hpp>
#include <mtpio/chain/apply_context.hpp>
#include <mtpio/chain/exceptions.hpp>

#include <vector>
#include <iterator>

namespace mtpio { namespace chain { namespace webassembly { namespace mtpvmoc {

class mtpvmoc_instantiated_module : public wasm_instantiated_module_interface {
   public:
      mtpvmoc_instantiated_module(const digest_type& code_hash, const uint8_t& vm_version, mtpvmoc_runtime& wr) :
         _code_hash(code_hash),
         _vm_version(vm_version),
         _mtpvmoc_runtime(wr)
      {

      }

      ~mtpvmoc_instantiated_module() {
         _mtpvmoc_runtime.cc.free_code(_code_hash, _vm_version);
      }

      void apply(apply_context& context) override {
         const code_descriptor* const cd = _mtpvmoc_runtime.cc.get_descriptor_for_code_sync(_code_hash, _vm_version);
         MTP_ASSERT(cd, wasm_execution_error, "MTP VM OC instantiation failed");

         _mtpvmoc_runtime.exec.execute(*cd, _mtpvmoc_runtime.mem, context);
      }

      const digest_type              _code_hash;
      const uint8_t                  _vm_version;
      mtpvmoc_runtime&               _mtpvmoc_runtime;
};

mtpvmoc_runtime::mtpvmoc_runtime(const boost::filesystem::path data_dir, const mtpvmoc::config& mtpvmoc_config, const chainbase::database& db)
   : cc(data_dir, mtpvmoc_config, db), exec(cc) {
}

mtpvmoc_runtime::~mtpvmoc_runtime() {
}

std::unique_ptr<wasm_instantiated_module_interface> mtpvmoc_runtime::instantiate_module(const char* code_bytes, size_t code_size, std::vector<uint8_t> initial_memory,
                                                                                     const digest_type& code_hash, const uint8_t& vm_type, const uint8_t& vm_version) {

   return std::make_unique<mtpvmoc_instantiated_module>(code_hash, vm_type, *this);
}

//never called. MTP VM OC overrides mtpio_exit to its own implementation
void mtpvmoc_runtime::immediately_exit_currently_running_module() {}

}}}}
