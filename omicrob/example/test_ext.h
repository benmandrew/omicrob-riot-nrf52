#ifndef __TEST_EXT__
#define __TEST_EXT__

#include "../ocaml/runtime/caml/compatibility.h"
#include "test_def.h"
value ocaml_stack[OCAML_STACK_WOSIZE];
value ocaml_ram_heap[OCAML_STATIC_HEAP_WOSIZE + OCAML_DYNAMIC_HEAP_WOSIZE];
value ocaml_ram_global_data[OCAML_RAM_GLOBDATA_NUMBER];

PROGMEM value const ocaml_flash_heap[OCAML_FLASH_HEAP_WOSIZE] = {
  /*  0 */  Make_header(0, 0, Color_white),
  /*  1 */  Make_header(2, Object_tag, Color_white),
  /*  2 */  Val_flash_block(&ocaml_flash_heap[5]),
  /*  3 */  Val_int(-1),
  /*  4 */  Make_header(4, String_tag, Color_white),
  /*  5 */  Make_string_data('O', 'u', 't', '_'),
  /*  6 */  Make_string_data('o', 'f', '_', 'm'),
  /*  7 */  Make_string_data('e', 'm', 'o', 'r'),
  /*  8 */  Make_string_data('y', '\0', '\0', '\2'),
  /*  9 */  Make_header(2, Object_tag, Color_white),
  /* 10 */  Val_flash_block(&ocaml_flash_heap[13]),
  /* 11 */  Val_int(-3),
  /* 12 */  Make_header(2, String_tag, Color_white),
  /* 13 */  Make_string_data('F', 'a', 'i', 'l'),
  /* 14 */  Make_string_data('u', 'r', 'e', '\0'),
  /* 15 */  Make_header(2, Object_tag, Color_white),
  /* 16 */  Val_flash_block(&ocaml_flash_heap[19]),
  /* 17 */  Val_int(-4),
  /* 18 */  Make_header(5, String_tag, Color_white),
  /* 19 */  Make_string_data('I', 'n', 'v', 'a'),
  /* 20 */  Make_string_data('l', 'i', 'd', '_'),
  /* 21 */  Make_string_data('a', 'r', 'g', 'u'),
  /* 22 */  Make_string_data('m', 'e', 'n', 't'),
  /* 23 */  Make_string_data('\0', '\0', '\0', '\3'),
  /* 24 */  Make_header(2, Object_tag, Color_white),
  /* 25 */  Val_flash_block(&ocaml_flash_heap[28]),
  /* 26 */  Val_int(-6),
  /* 27 */  Make_header(5, String_tag, Color_white),
  /* 28 */  Make_string_data('D', 'i', 'v', 'i'),
  /* 29 */  Make_string_data('s', 'i', 'o', 'n'),
  /* 30 */  Make_string_data('_', 'b', 'y', '_'),
  /* 31 */  Make_string_data('z', 'e', 'r', 'o'),
  /* 32 */  Make_string_data('\0', '\0', '\0', '\3'),
  /* 33 */  Make_header(2, Object_tag, Color_white),
  /* 34 */  Val_flash_block(&ocaml_flash_heap[37]),
  /* 35 */  Val_int(-9),
  /* 36 */  Make_header(4, String_tag, Color_white),
  /* 37 */  Make_string_data('S', 't', 'a', 'c'),
  /* 38 */  Make_string_data('k', '_', 'o', 'v'),
  /* 39 */  Make_string_data('e', 'r', 'f', 'l'),
  /* 40 */  Make_string_data('o', 'w', '\0', '\1')
};

PROGMEM value const ocaml_initial_static_heap[OCAML_STATIC_HEAP_WOSIZE] = {
};

PROGMEM value const ocaml_initial_stack[OCAML_STACK_INITIAL_WOSIZE] = {
};

PROGMEM value const ocaml_flash_global_data[OCAML_FLASH_GLOBDATA_NUMBER] = {
};

value acc = Val_unit;
value env = Val_unit;

#define OCAML_Out_of_memory        Val_flash_block(&ocaml_flash_heap[2])
#define OCAML_Failure              Val_flash_block(&ocaml_flash_heap[10])
#define OCAML_Invalid_argument     Val_flash_block(&ocaml_flash_heap[16])
#define OCAML_Division_by_zero     Val_flash_block(&ocaml_flash_heap[25])
#define OCAML_Stack_overflow       Val_flash_block(&ocaml_flash_heap[34])

#define OCAML_atom0                Val_flash_block(&ocaml_flash_heap[1])

PROGMEM opcode_t const ocaml_bytecode[OCAML_BYTECODE_BSIZE] = {
  /* 0 */  OCAML_STOP
};

#include </Users/ben/Desktop/Projects/riot-omicrob/omicrob/src/byterun/vm/runtime.c>

PROGMEM void * const ocaml_primitives[OCAML_PRIMITIVE_NUMBER] = {
};

#endif