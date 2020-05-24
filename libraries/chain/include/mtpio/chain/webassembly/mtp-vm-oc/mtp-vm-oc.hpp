#pragma once

#include <mtpio/chain/types.hpp>
#include <mtpio/chain/webassembly/mtp-vm-oc/mtp-vm-oc.h>

#include <exception>

#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>

#include <vector>
#include <list>

namespace mtpio { namespace chain {

class apply_context;

namespace mtpvmoc {

using control_block = mtp_vm_oc_control_block;

struct no_offset{};
struct code_offset{ size_t offset; };    //relative to code_begin
struct intrinsic_ordinal{ size_t ordinal; };

using mtpvmoc_optional_offset_or_import_t = fc::static_variant<no_offset, code_offset, intrinsic_ordinal>;

struct code_descriptor {
   digest_type code_hash;
   uint8_t vm_version;
   uint8_t codegen_version;
   size_t code_begin;
   mtpvmoc_optional_offset_or_import_t start;
   unsigned apply_offset;
   int starting_memory_pages;
   size_t initdata_begin;
   unsigned initdata_size;
   unsigned initdata_prologue_size;
};

enum mtpvmoc_exitcode : int {
   MTPVMOC_EXIT_CLEAN_EXIT = 1,
   MTPVMOC_EXIT_CHECKTIME_FAIL,
   MTPVMOC_EXIT_SEGV,
   MTPVMOC_EXIT_EXCEPTION
};

}}}

FC_REFLECT(mtpio::chain::mtpvmoc::no_offset, );
FC_REFLECT(mtpio::chain::mtpvmoc::code_offset, (offset));
FC_REFLECT(mtpio::chain::mtpvmoc::intrinsic_ordinal, (ordinal));
FC_REFLECT(mtpio::chain::mtpvmoc::code_descriptor, (code_hash)(vm_version)(codegen_version)(code_begin)(start)(apply_offset)(starting_memory_pages)(initdata_begin)(initdata_size)(initdata_prologue_size));

#define MTPVMOC_INTRINSIC_INIT_PRIORITY __attribute__((init_priority(198)))