#pragma once

#include <mtpio/chain/wasm_mtpio_constraints.hpp>
#include <mtpio/chain/webassembly/mtp-vm-oc/mtp-vm-oc.hpp>
#include <mtpio/chain/webassembly/mtp-vm-oc/intrinsic_mapping.hpp>
#include <mtpio/chain/webassembly/mtp-vm-oc/gs_seg_helpers.h>

#include <stdint.h>
#include <stddef.h>

namespace mtpio { namespace chain { namespace mtpvmoc {

class memory {
      static constexpr uint64_t wasm_memory_size                  = mtpio::chain::wasm_constraints::maximum_linear_memory;
      static constexpr uint64_t intrinsic_count                   = boost::hana::length(intrinsic_table);
      //warning: changing the following 3 params will invalidate existing PIC
      static constexpr uint64_t mutable_global_size               = 8u  * mtpio::chain::wasm_constraints::maximum_mutable_globals/4u;
      static constexpr uint64_t table_size                        = 16u * mtpio::chain::wasm_constraints::maximum_table_elements;
      static constexpr size_t   wcb_allowance                     = 512u;
      static_assert(sizeof(control_block) <= wcb_allowance, "MTP VM OC memory doesn't set aside enough memory for control block");

      //round up the prologue to multiple of 4K page
      static constexpr uint64_t memory_prologue_size = ((memory::wcb_allowance + mutable_global_size + table_size + intrinsic_count*UINT64_C(8))+UINT64_C(4095))/UINT64_C(4096)*UINT64_C(4096);
      //prologue + 33MB + 4GB fault buffer + 4096 addtional buffer for safety
      static constexpr uint64_t total_memory_per_slice = memory_prologue_size + wasm_memory_size + UINT64_C(0x100000000) + UINT64_C(4096);

      static constexpr uint64_t number_slices = wasm_memory_size/(64u*1024u)+1u;

   public:
      memory();
      ~memory();

      uint8_t* const zero_page_memory_base() const { return zeropage_base; }
      uint8_t* const full_page_memory_base() const { return fullpage_base; }

      control_block* const get_control_block() const { return reinterpret_cast<control_block* const>(zeropage_base - cb_offset);}

      //these two are really only inteded for SEGV handling
      uint8_t* const start_of_memory_slices() const { return mapbase; }
      size_t size_of_memory_slice_mapping() const { return mapsize; }

      //to obtain memory protected for n wasm-pages, use the pointer computed from:
      //   zero_page_memory_base()+stride*n
      static constexpr size_t stride = total_memory_per_slice;

      //offsets to various interesting things in the memory
      static constexpr uintptr_t linear_memory = 0;
      static constexpr uintptr_t cb_offset = wcb_allowance + mutable_global_size + table_size;
      static constexpr uintptr_t first_intrinsic_offset = cb_offset + 8u;

      static_assert(-cb_offset == MTP_VM_OC_CONTROL_BLOCK_OFFSET, "MTP VM OC control block offset has slid out of place somehow");
      static_assert(stride == MTP_VM_OC_MEMORY_STRIDE, "MTP VM OC memory stride has slid out of place somehow");

   private:
      uint8_t* mapbase;
      uint64_t mapsize;

      uint8_t* zeropage_base;
      uint8_t* fullpage_base;
};

}}}

#define OFFSET_OF_CONTROL_BLOCK_MEMBER(M) (-(int)mtpio::chain::mtpvmoc::memory::cb_offset + (int)offsetof(mtpio::chain::mtpvmoc::control_block, M))
#define OFFSET_OF_FIRST_INTRINSIC ((int)-mtpio::chain::mtpvmoc::memory::first_intrinsic_offset)