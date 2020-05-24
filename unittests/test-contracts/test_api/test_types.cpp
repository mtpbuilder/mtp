#include <mtpiolib/mtpio.hpp>

#include "test_api.hpp"

void test_types::types_size() {

   mtpio_assert( sizeof(int64_t)   ==  8, "int64_t size != 8"   );
   mtpio_assert( sizeof(uint64_t)  ==  8, "uint64_t size != 8"  );
   mtpio_assert( sizeof(uint32_t)  ==  4, "uint32_t size != 4"  );
   mtpio_assert( sizeof(int32_t)   ==  4, "int32_t size != 4"   );
   mtpio_assert( sizeof(uint128_t) == 16, "uint128_t size != 16");
   mtpio_assert( sizeof(int128_t)  == 16, "int128_t size != 16" );
   mtpio_assert( sizeof(uint8_t)   ==  1, "uint8_t size != 1"   );

   mtpio_assert( sizeof(mtpio::name) ==  8, "name size !=  8");
}

void test_types::char_to_symbol() {

   mtpio_assert( mtpio::name::char_to_value('1') ==  1, "mtpio::char_to_symbol('1') !=  1" );
   mtpio_assert( mtpio::name::char_to_value('2') ==  2, "mtpio::char_to_symbol('2') !=  2" );
   mtpio_assert( mtpio::name::char_to_value('3') ==  3, "mtpio::char_to_symbol('3') !=  3" );
   mtpio_assert( mtpio::name::char_to_value('4') ==  4, "mtpio::char_to_symbol('4') !=  4" );
   mtpio_assert( mtpio::name::char_to_value('5') ==  5, "mtpio::char_to_symbol('5') !=  5" );
   mtpio_assert( mtpio::name::char_to_value('a') ==  6, "mtpio::char_to_symbol('a') !=  6" );
   mtpio_assert( mtpio::name::char_to_value('b') ==  7, "mtpio::char_to_symbol('b') !=  7" );
   mtpio_assert( mtpio::name::char_to_value('c') ==  8, "mtpio::char_to_symbol('c') !=  8" );
   mtpio_assert( mtpio::name::char_to_value('d') ==  9, "mtpio::char_to_symbol('d') !=  9" );
   mtpio_assert( mtpio::name::char_to_value('e') == 10, "mtpio::char_to_symbol('e') != 10" );
   mtpio_assert( mtpio::name::char_to_value('f') == 11, "mtpio::char_to_symbol('f') != 11" );
   mtpio_assert( mtpio::name::char_to_value('g') == 12, "mtpio::char_to_symbol('g') != 12" );
   mtpio_assert( mtpio::name::char_to_value('h') == 13, "mtpio::char_to_symbol('h') != 13" );
   mtpio_assert( mtpio::name::char_to_value('i') == 14, "mtpio::char_to_symbol('i') != 14" );
   mtpio_assert( mtpio::name::char_to_value('j') == 15, "mtpio::char_to_symbol('j') != 15" );
   mtpio_assert( mtpio::name::char_to_value('k') == 16, "mtpio::char_to_symbol('k') != 16" );
   mtpio_assert( mtpio::name::char_to_value('l') == 17, "mtpio::char_to_symbol('l') != 17" );
   mtpio_assert( mtpio::name::char_to_value('m') == 18, "mtpio::char_to_symbol('m') != 18" );
   mtpio_assert( mtpio::name::char_to_value('n') == 19, "mtpio::char_to_symbol('n') != 19" );
   mtpio_assert( mtpio::name::char_to_value('o') == 20, "mtpio::char_to_symbol('o') != 20" );
   mtpio_assert( mtpio::name::char_to_value('p') == 21, "mtpio::char_to_symbol('p') != 21" );
   mtpio_assert( mtpio::name::char_to_value('q') == 22, "mtpio::char_to_symbol('q') != 22" );
   mtpio_assert( mtpio::name::char_to_value('r') == 23, "mtpio::char_to_symbol('r') != 23" );
   mtpio_assert( mtpio::name::char_to_value('s') == 24, "mtpio::char_to_symbol('s') != 24" );
   mtpio_assert( mtpio::name::char_to_value('t') == 25, "mtpio::char_to_symbol('t') != 25" );
   mtpio_assert( mtpio::name::char_to_value('u') == 26, "mtpio::char_to_symbol('u') != 26" );
   mtpio_assert( mtpio::name::char_to_value('v') == 27, "mtpio::char_to_symbol('v') != 27" );
   mtpio_assert( mtpio::name::char_to_value('w') == 28, "mtpio::char_to_symbol('w') != 28" );
   mtpio_assert( mtpio::name::char_to_value('x') == 29, "mtpio::char_to_symbol('x') != 29" );
   mtpio_assert( mtpio::name::char_to_value('y') == 30, "mtpio::char_to_symbol('y') != 30" );
   mtpio_assert( mtpio::name::char_to_value('z') == 31, "mtpio::char_to_symbol('z') != 31" );

   for(unsigned char i = 0; i<255; i++) {
      if( (i >= 'a' && i <= 'z') || (i >= '1' || i <= '5') ) continue;
      mtpio_assert( mtpio::name::char_to_value((char)i) == 0, "mtpio::char_to_symbol() != 0" );
   }
}

void test_types::string_to_name() {
   return;
   mtpio_assert( mtpio::name("a") == "a"_n, "mtpio::string_to_name(a)" );
   mtpio_assert( mtpio::name("ba") == "ba"_n, "mtpio::string_to_name(ba)" );
   mtpio_assert( mtpio::name("cba") == "cba"_n, "mtpio::string_to_name(cba)" );
   mtpio_assert( mtpio::name("dcba") == "dcba"_n, "mtpio::string_to_name(dcba)" );
   mtpio_assert( mtpio::name("edcba") == "edcba"_n, "mtpio::string_to_name(edcba)" );
   mtpio_assert( mtpio::name("fedcba") == "fedcba"_n, "mtpio::string_to_name(fedcba)" );
   mtpio_assert( mtpio::name("gfedcba") == "gfedcba"_n, "mtpio::string_to_name(gfedcba)" );
   mtpio_assert( mtpio::name("hgfedcba") == "hgfedcba"_n, "mtpio::string_to_name(hgfedcba)" );
   mtpio_assert( mtpio::name("ihgfedcba") == "ihgfedcba"_n, "mtpio::string_to_name(ihgfedcba)" );
   mtpio_assert( mtpio::name("jihgfedcba") == "jihgfedcba"_n, "mtpio::string_to_name(jihgfedcba)" );
   mtpio_assert( mtpio::name("kjihgfedcba") == "kjihgfedcba"_n, "mtpio::string_to_name(kjihgfedcba)" );
   mtpio_assert( mtpio::name("lkjihgfedcba") == "lkjihgfedcba"_n, "mtpio::string_to_name(lkjihgfedcba)" );
   mtpio_assert( mtpio::name("mlkjihgfedcba") == "mlkjihgfedcba"_n, "mtpio::string_to_name(mlkjihgfedcba)" );
}
