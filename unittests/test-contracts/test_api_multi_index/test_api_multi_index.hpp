#pragma once

#include <mtpio/mtpio.hpp>

class [[mtpio::contract]] test_api_multi_index : public mtpio::contract {
public:
   using mtpio::contract::contract;

   [[mtpio::action("s1g")]]
   void idx64_general();

   [[mtpio::action("s1store")]]
   void idx64_store_only();

   [[mtpio::action("s1check")]]
   void idx64_check_without_storing();

   [[mtpio::action("s1findfail1")]]
   void idx64_require_find_fail();

   [[mtpio::action("s1findfail2")]]
   void idx64_require_find_fail_with_msg();

   [[mtpio::action("s1findfail3")]]
   void idx64_require_find_sk_fail();

   [[mtpio::action("s1findfail4")]]
   void idx64_require_find_sk_fail_with_msg();

   [[mtpio::action("s1pkend")]]
   void idx64_pk_iterator_exceed_end();

   [[mtpio::action("s1skend")]]
   void idx64_sk_iterator_exceed_end();

   [[mtpio::action("s1pkbegin")]]
   void idx64_pk_iterator_exceed_begin();

   [[mtpio::action("s1skbegin")]]
   void idx64_sk_iterator_exceed_begin();

   [[mtpio::action("s1pkref")]]
   void idx64_pass_pk_ref_to_other_table();

   [[mtpio::action("s1skref")]]
   void idx64_pass_sk_ref_to_other_table();

   [[mtpio::action("s1pkitrto")]]
   void idx64_pass_pk_end_itr_to_iterator_to();

   [[mtpio::action("s1pkmodify")]]
   void idx64_pass_pk_end_itr_to_modify();

   [[mtpio::action("s1pkerase")]]
   void idx64_pass_pk_end_itr_to_erase();

   [[mtpio::action("s1skitrto")]]
   void idx64_pass_sk_end_itr_to_iterator_to();

   [[mtpio::action("s1skmodify")]]
   void idx64_pass_sk_end_itr_to_modify();

   [[mtpio::action("s1skerase")]]
   void idx64_pass_sk_end_itr_to_erase();

   [[mtpio::action("s1modpk")]]
   void idx64_modify_primary_key();

   [[mtpio::action("s1exhaustpk")]]
   void idx64_run_out_of_avl_pk();

   [[mtpio::action("s1skcache")]]
   void idx64_sk_cache_pk_lookup();

   [[mtpio::action("s1pkcache")]]
   void idx64_pk_cache_sk_lookup();

   [[mtpio::action("s2g")]]
   void idx128_general();

   [[mtpio::action("s2store")]]
   void idx128_store_only();

   [[mtpio::action("s2check")]]
   void idx128_check_without_storing();

   [[mtpio::action("s2autoinc")]]
   void idx128_autoincrement_test();

   [[mtpio::action("s2autoinc1")]]
   void idx128_autoincrement_test_part1();

   [[mtpio::action("s2autoinc2")]]
   void idx128_autoincrement_test_part2();

   [[mtpio::action("s3g")]]
   void idx256_general();

   [[mtpio::action("sdg")]]
   void idx_double_general();

   [[mtpio::action("sldg")]]
   void idx_long_double_general();

};
