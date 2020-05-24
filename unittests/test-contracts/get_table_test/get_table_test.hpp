/**
 *  @file
 *  @copyright defined in mtp/LICENSE
 */
#pragma once

#include <mtpio/mtpio.hpp>
#include <mtpio/crypto.hpp>

using namespace mtpio;

class [[mtpio::contract]] get_table_test : public mtpio::contract {
    public:
    using mtpio::contract::contract;

    // Number object
    struct [[mtpio::table]] numobj {
        uint64_t        key;
        uint64_t        sec64;
        uint128_t       sec128;
        double          secdouble;
        long double     secldouble;

        uint64_t primary_key() const { return key; }
        uint64_t sec64_key() const { return sec64; }
        uint128_t sec128_key() const { return sec128; }
        double secdouble_key() const { return secdouble; }
        long double secldouble_key() const { return secldouble; }
    };

    // Hash object
    struct [[mtpio::table]] hashobj {
        uint64_t        key;
        std::string     hash_input;
        checksum256     sec256;
        checksum160     sec160;

        uint64_t primary_key() const { return key; }
        checksum256 sec256_key() const { return sec256; }
        checksum256 sec160_key() const { return checksum256(sec160.get_array()); }
    };

    typedef mtpio::multi_index< "numobjs"_n, numobj, 
                                indexed_by<"bysec1"_n, const_mem_fun<numobj, uint64_t, &numobj::sec64_key>>,
                                indexed_by<"bysec2"_n, const_mem_fun<numobj, uint128_t, &numobj::sec128_key>>,
                                indexed_by<"bysec3"_n, const_mem_fun<numobj, double, &numobj::secdouble_key>>,
                                indexed_by<"bysec4"_n, const_mem_fun<numobj, long double, &numobj::secldouble_key>>
                                > numobjs;

    typedef mtpio::multi_index< "hashobjs"_n, hashobj, 
                            indexed_by<"bysec1"_n, const_mem_fun<hashobj, checksum256, &hashobj::sec256_key>>,
                            indexed_by<"bysec2"_n, const_mem_fun<hashobj, checksum256, &hashobj::sec160_key>>
                            > hashobjs;

   [[mtpio::action]]
   void addnumobj(uint64_t input);


   [[mtpio::action]]
   void addhashobj(std::string hashinput);


};