#pragma once

#include <mtpio/mtpio.hpp>

class [[mtpio::contract]] test_api_db : public mtpio::contract {
public:
   using mtpio::contract::contract;

   [[mtpio::action("pg")]]
   void primary_i64_general();

   [[mtpio::action("pl")]]
   void primary_i64_lowerbound();

   [[mtpio::action("pu")]]
   void primary_i64_upperbound();

   [[mtpio::action("s1g")]]
   void idx64_general();

   [[mtpio::action("s1l")]]
   void idx64_lowerbound();

   [[mtpio::action("s1u")]]
   void idx64_upperbound();

   [[mtpio::action("tia")]]
   void test_invalid_access( mtpio::name code, uint64_t val, uint32_t index, bool store );

   [[mtpio::action("sdnancreate")]]
   void idx_double_nan_create_fail();

   [[mtpio::action("sdnanmodify")]]
   void idx_double_nan_modify_fail();

   [[mtpio::action("sdnanlookup")]]
   void idx_double_nan_lookup_fail( uint32_t lookup_type );

   [[mtpio::action("sk32align")]]
   void misaligned_secondary_key256_tests();

};
