#define OCAML_STACK_WOSIZE                64
#define OCAML_STATIC_HEAP_WOSIZE           3
#define OCAML_DYNAMIC_HEAP_WOSIZE        253
#define OCAML_FLASH_HEAP_WOSIZE          100
#define OCAML_STACK_INITIAL_WOSIZE         1
#define OCAML_RAM_GLOBDATA_NUMBER          1
#define OCAML_FLASH_GLOBDATA_NUMBER        7
#define OCAML_BYTECODE_BSIZE             313
#define OCAML_PRIMITIVE_NUMBER            10
#define OCAML_VIRTUAL_ARCH                32
#define OCAML_STARTING_OOID                0
#define OCAML_NO_FLASH_HEAP                0
#define OCAML_NO_FLASH_GLOBALS             0

#define OCAML_GC_MARK_AND_COMPACT

#include </home/ben/omicrob/src/byterun/vm/values.h>

#define OCAML_ACC0                        0
#define OCAML_ACC1                        1
#define OCAML_ACC3                        2
#define OCAML_ACC4                        3
#define OCAML_PUSH                        4
#define OCAML_PUSHACC1                    5
#define OCAML_PUSHACC2                    6
#define OCAML_PUSHACC3                    7
#define OCAML_PUSHACC4                    8
#define OCAML_POP                         9
#define OCAML_ENVACC2                    10
#define OCAML_PUSHENVACC2                11
#define OCAML_PUSHENVACC3                12
#define OCAML_PUSHENVACC4                13
#define OCAML_APPLY1                     14
#define OCAML_APPLY3                     15
#define OCAML_APPTERM1                   16
#define OCAML_APPTERM3                   17
#define OCAML_RETURN                     18
#define OCAML_RESTART                    19
#define OCAML_GRAB                       20
#define OCAML_CLOSURE_1B                 21
#define OCAML_CLOSURE_2B                 22
#define OCAML_CLOSUREREC_1B              23
#define OCAML_CLOSUREREC_2B              24
#define OCAML_PUSHOFFSETCLOSURE0         25
#define OCAML_GETFLASHGLOBAL_1B          26
#define OCAML_PUSHGETRAMGLOBAL_1B        27
#define OCAML_PUSHGETFLASHGLOBAL_1B      28
#define OCAML_SETRAMGLOBAL_1B            29
#define OCAML_MAKEBLOCK1                 30
#define OCAML_GETFIELD0                  31
#define OCAML_GETFIELD1                  32
#define OCAML_SETFIELD0                  33
#define OCAML_BRANCH_1B                  34
#define OCAML_BRANCH_2B                  35
#define OCAML_BRANCHIFNOT_1B             36
#define OCAML_BOOLNOT                    37
#define OCAML_PUSHTRAP_1B                38
#define OCAML_POPTRAP                    39
#define OCAML_RAISE                      40
#define OCAML_C_CALL1                    41
#define OCAML_C_CALL2                    42
#define OCAML_C_CALL3                    43
#define OCAML_CONST0                     44
#define OCAML_CONST1                     45
#define OCAML_CONST2                     46
#define OCAML_PUSHCONST0                 47
#define OCAML_PUSHCONST1                 48
#define OCAML_PUSHCONSTINT_2B            49
#define OCAML_EQ                         50
#define OCAML_STOP                       51

value ocaml_stack[OCAML_STACK_WOSIZE];
value ocaml_ram_heap[OCAML_STATIC_HEAP_WOSIZE + OCAML_DYNAMIC_HEAP_WOSIZE];
value ocaml_ram_global_data[OCAML_RAM_GLOBDATA_NUMBER];

PROGMEM value const ocaml_flash_heap[OCAML_FLASH_HEAP_WOSIZE] = {
  /*   0 */  Make_header(0, 0, Color_white),
  /*   1 */  Make_header(2, Object_tag, Color_white),
  /*   2 */  Val_flash_block(&ocaml_flash_heap[5]),
  /*   3 */  Val_int(-1),
  /*   4 */  Make_header(4, String_tag, Color_white),
  /*   5 */  Make_string_data('O', 'u', 't', '_'),
  /*   6 */  Make_string_data('o', 'f', '_', 'm'),
  /*   7 */  Make_string_data('e', 'm', 'o', 'r'),
  /*   8 */  Make_string_data('y', '\0', '\0', '\2'),
  /*   9 */  Make_header(2, Object_tag, Color_white),
  /*  10 */  Val_flash_block(&ocaml_flash_heap[13]),
  /*  11 */  Val_int(-3),
  /*  12 */  Make_header(2, String_tag, Color_white),
  /*  13 */  Make_string_data('F', 'a', 'i', 'l'),
  /*  14 */  Make_string_data('u', 'r', 'e', '\0'),
  /*  15 */  Make_header(2, Object_tag, Color_white),
  /*  16 */  Val_flash_block(&ocaml_flash_heap[19]),
  /*  17 */  Val_int(-4),
  /*  18 */  Make_header(5, String_tag, Color_white),
  /*  19 */  Make_string_data('I', 'n', 'v', 'a'),
  /*  20 */  Make_string_data('l', 'i', 'd', '_'),
  /*  21 */  Make_string_data('a', 'r', 'g', 'u'),
  /*  22 */  Make_string_data('m', 'e', 'n', 't'),
  /*  23 */  Make_string_data('\0', '\0', '\0', '\3'),
  /*  24 */  Make_header(2, Object_tag, Color_white),
  /*  25 */  Val_flash_block(&ocaml_flash_heap[28]),
  /*  26 */  Val_int(-6),
  /*  27 */  Make_header(5, String_tag, Color_white),
  /*  28 */  Make_string_data('D', 'i', 'v', 'i'),
  /*  29 */  Make_string_data('s', 'i', 'o', 'n'),
  /*  30 */  Make_string_data('_', 'b', 'y', '_'),
  /*  31 */  Make_string_data('z', 'e', 'r', 'o'),
  /*  32 */  Make_string_data('\0', '\0', '\0', '\3'),
  /*  33 */  Make_header(2, Object_tag, Color_white),
  /*  34 */  Val_flash_block(&ocaml_flash_heap[37]),
  /*  35 */  Val_int(-9),
  /*  36 */  Make_header(4, String_tag, Color_white),
  /*  37 */  Make_string_data('S', 't', 'a', 'c'),
  /*  38 */  Make_string_data('k', '_', 'o', 'v'),
  /*  39 */  Make_string_data('e', 'r', 'f', 'l'),
  /*  40 */  Make_string_data('o', 'w', '\0', '\1'),
  /*  41 */  Make_header(8, String_tag, Color_white),
  /*  42 */  Make_string_data('P', 'e', 'r', 'v'),
  /*  43 */  Make_string_data('a', 's', 'i', 'v'),
  /*  44 */  Make_string_data('e', 's', '.', 'a'),
  /*  45 */  Make_string_data('r', 'r', 'a', 'y'),
  /*  46 */  Make_string_data('_', 'b', 'o', 'u'),
  /*  47 */  Make_string_data('n', 'd', '_', 'e'),
  /*  48 */  Make_string_data('r', 'r', 'o', 'r'),
  /*  49 */  Make_string_data('\0', '\0', '\0', '\3'),
  /*  50 */  Make_header(5, String_tag, Color_white),
  /*  51 */  Make_string_data('i', 'n', 'd', 'e'),
  /*  52 */  Make_string_data('x', ' ', 'o', 'u'),
  /*  53 */  Make_string_data('t', ' ', 'o', 'f'),
  /*  54 */  Make_string_data(' ', 'b', 'o', 'u'),
  /*  55 */  Make_string_data('n', 'd', 's', '\0'),
  /*  56 */  Make_header(2, Object_tag, Color_white),
  /*  57 */  Val_flash_block(&ocaml_flash_heap[60]),
  /*  58 */  Val_int(-2),
  /*  59 */  Make_header(3, String_tag, Color_white),
  /*  60 */  Make_string_data('S', 'y', 's', '_'),
  /*  61 */  Make_string_data('e', 'r', 'r', 'o'),
  /*  62 */  Make_string_data('r', '\0', '\0', '\2'),
  /*  63 */  Make_header(1, Closure_tag, Color_white),
  /*  64 */  Val_codeptr(4),
  /*  65 */  Make_header(1, Closure_tag, Color_white),
  /*  66 */  Val_codeptr(38),
  /*  67 */  Make_header(1, Closure_tag, Color_white),
  /*  68 */  Val_codeptr(31),
  /*  69 */  Make_header(2, 0, Color_white),
  /*  70 */  Val_int(1),
  /*  71 */  Val_flash_block(&ocaml_flash_heap[73]),
  /*  72 */  Make_header(2, 0, Color_white),
  /*  73 */  Val_int(3),
  /*  74 */  Val_flash_block(&ocaml_flash_heap[76]),
  /*  75 */  Make_header(2, 0, Color_white),
  /*  76 */  Val_int(4),
  /*  77 */  Val_flash_block(&ocaml_flash_heap[79]),
  /*  78 */  Make_header(2, 0, Color_white),
  /*  79 */  Val_int(6),
  /*  80 */  Val_unit,
  /*  81 */  Make_header(2, 0, Color_white),
  /*  82 */  Val_int(1),
  /*  83 */  Val_flash_block(&ocaml_flash_heap[85]),
  /*  84 */  Make_header(2, 0, Color_white),
  /*  85 */  Val_int(3),
  /*  86 */  Val_flash_block(&ocaml_flash_heap[88]),
  /*  87 */  Make_header(2, 0, Color_white),
  /*  88 */  Val_int(4),
  /*  89 */  Val_flash_block(&ocaml_flash_heap[91]),
  /*  90 */  Make_header(2, 0, Color_white),
  /*  91 */  Val_int(7),
  /*  92 */  Val_unit,
  /*  93 */  Make_header(6, String_tag, Color_white),
  /*  94 */  Make_string_data('P', 'e', 'r', 'v'),
  /*  95 */  Make_string_data('a', 's', 'i', 'v'),
  /*  96 */  Make_string_data('e', 's', '.', 'd'),
  /*  97 */  Make_string_data('o', '_', 'a', 't'),
  /*  98 */  Make_string_data('_', 'e', 'x', 'i'),
  /*  99 */  Make_string_data('t', '\0', '\0', '\2')
};

PROGMEM value const ocaml_initial_static_heap[OCAML_STATIC_HEAP_WOSIZE] = {
  /* 0 */  Make_header(2, 0, Color_white),
  /* 1 */  Val_flash_block(&ocaml_flash_heap[16]),
  /* 2 */  Val_flash_block(&ocaml_flash_heap[51])
};

PROGMEM value const ocaml_initial_stack[OCAML_STACK_INITIAL_WOSIZE] = {
  /* 0 */  Val_static_block(&ocaml_ram_heap[1])
};

PROGMEM value const ocaml_flash_global_data[OCAML_FLASH_GLOBDATA_NUMBER] = {
  /* 0 */  Val_flash_block(&ocaml_flash_heap[57]),
  /* 1 */  Val_flash_block(&ocaml_flash_heap[64]),
  /* 2 */  Val_flash_block(&ocaml_flash_heap[66]),
  /* 3 */  Val_flash_block(&ocaml_flash_heap[68]),
  /* 4 */  Val_flash_block(&ocaml_flash_heap[70]),
  /* 5 */  Val_flash_block(&ocaml_flash_heap[82]),
  /* 6 */  Val_flash_block(&ocaml_flash_heap[94])
};

value acc = Val_flash_block(&ocaml_flash_heap[42]);
value env = Val_unit;

#define OCAML_Out_of_memory        Val_flash_block(&ocaml_flash_heap[2])
#define OCAML_Failure              Val_flash_block(&ocaml_flash_heap[10])
#define OCAML_Invalid_argument     Val_flash_block(&ocaml_flash_heap[16])
#define OCAML_Division_by_zero     Val_flash_block(&ocaml_flash_heap[25])
#define OCAML_Stack_overflow       Val_flash_block(&ocaml_flash_heap[34])

#define OCAML_atom0                Val_flash_block(&ocaml_flash_heap[1])

PROGMEM opcode_t const ocaml_bytecode[OCAML_BYTECODE_BSIZE] = {
  /*   0 */  OCAML_BRANCH_2B, 0, 231,
  /*   3 */  OCAML_RESTART,
  /*   4 */  OCAML_GRAB, 0, 0, 0, 2,
  /*   9 */  OCAML_ACC0,
  /*  10 */  OCAML_GETFIELD0,
  /*  11 */  OCAML_PUSHACC2,
  /*  12 */  OCAML_PUSHACC1,
  /*  13 */  OCAML_EQ,
  /*  14 */  OCAML_BRANCHIFNOT_1B, 11,
  /*  16 */  OCAML_ACC3,
  /*  17 */  OCAML_PUSHACC2,
  /*  18 */  OCAML_SETFIELD0,
  /*  19 */  OCAML_CONST1,
  /*  20 */  OCAML_RETURN, 0, 0, 0, 4,
  /*  25 */  OCAML_CONST0,
  /*  26 */  OCAML_RETURN, 0, 0, 0, 4,
  /*  31 */  OCAML_ACC0,
  /*  32 */  OCAML_GETFIELD0,
  /*  33 */  OCAML_RETURN, 0, 0, 0, 1,
  /*  38 */  OCAML_ACC0,
  /*  39 */  OCAML_MAKEBLOCK1, 0,
  /*  41 */  OCAML_RETURN, 0, 0, 0, 1,
  /*  46 */  OCAML_CONST0,
  /*  47 */  OCAML_PUSHCONST1,
  /*  48 */  OCAML_PUSHENVACC3,
  /*  49 */  OCAML_PUSHGETFLASHGLOBAL_1B, 1,
  /*  51 */  OCAML_APPLY3,
  /*  52 */  OCAML_BRANCHIFNOT_1B, 5,
  /*  54 */  OCAML_CONST0,
  /*  55 */  OCAML_PUSHENVACC2,
  /*  56 */  OCAML_APPLY1,
  /*  57 */  OCAML_CONST0,
  /*  58 */  OCAML_PUSHENVACC4,
  /*  59 */  OCAML_APPTERM1, 0, 0, 0, 2,
  /*  64 */  OCAML_CONST1,
  /*  65 */  OCAML_PUSHGETFLASHGLOBAL_1B, 2,
  /*  67 */  OCAML_APPLY1,
  /*  68 */  OCAML_PUSHENVACC2,
  /*  69 */  OCAML_PUSHGETFLASHGLOBAL_1B, 3,
  /*  71 */  OCAML_APPLY1,
  /*  72 */  OCAML_PUSH,
  /*  73 */  OCAML_PUSHACC2,
  /*  74 */  OCAML_PUSHACC4,
  /*  75 */  OCAML_CLOSURE_1B, 3, (opcode_t) -29,
  /*  78 */  OCAML_PUSH,
  /*  79 */  OCAML_PUSHACC2,
  /*  80 */  OCAML_PUSHENVACC2,
  /*  81 */  OCAML_PUSHGETFLASHGLOBAL_1B, 1,
  /*  83 */  OCAML_APPLY3,
  /*  84 */  OCAML_PUSH,
  /*  85 */  OCAML_BOOLNOT,
  /*  86 */  OCAML_BRANCHIFNOT_1B, 9,
  /*  88 */  OCAML_ACC4,
  /*  89 */  OCAML_PUSHOFFSETCLOSURE0,
  /*  90 */  OCAML_APPTERM1, 0, 0, 0, 6,
  /*  95 */  OCAML_RETURN, 0, 0, 0, 5,
  /* 100 */  OCAML_ACC0,
  /* 101 */  OCAML_C_CALL1, 0,
  /* 103 */  OCAML_RETURN, 0, 0, 0, 1,
  /* 108 */  OCAML_CONST0,
  /* 109 */  OCAML_PUSHENVACC2,
  /* 110 */  OCAML_PUSHGETFLASHGLOBAL_1B, 3,
  /* 112 */  OCAML_APPLY1,
  /* 113 */  OCAML_APPTERM1, 0, 0, 0, 2,
  /* 118 */  OCAML_ACC0,
  /* 119 */  OCAML_BRANCHIFNOT_1B, 39,
  /* 121 */  OCAML_ACC0,
  /* 122 */  OCAML_GETFIELD1,
  /* 123 */  OCAML_PUSHACC1,
  /* 124 */  OCAML_GETFIELD0,
  /* 125 */  OCAML_PUSH,
  /* 126 */  OCAML_PUSHTRAP_1B, 8,
  /* 128 */  OCAML_ACC4,
  /* 129 */  OCAML_C_CALL1, 1,
  /* 131 */  OCAML_POPTRAP,
  /* 132 */  OCAML_BRANCH_1B, 19,
  /* 134 */  OCAML_PUSH,
  /* 135 */  OCAML_GETFIELD0,
  /* 136 */  OCAML_PUSHENVACC2,
  /* 137 */  OCAML_PUSHACC1,
  /* 138 */  OCAML_EQ,
  /* 139 */  OCAML_BRANCHIFNOT_1B, 5,
  /* 141 */  OCAML_CONST0,
  /* 142 */  OCAML_BRANCH_1B, 4,
  /* 144 */  OCAML_ACC1,
  /* 145 */  OCAML_RAISE,
  /* 146 */  OCAML_POP, 0, 0, 0, 2,
  /* 151 */  OCAML_ACC1,
  /* 152 */  OCAML_PUSHOFFSETCLOSURE0,
  /* 153 */  OCAML_APPTERM1, 0, 0, 0, 4,
  /* 158 */  OCAML_CONST0,
  /* 159 */  OCAML_RETURN, 0, 0, 0, 1,
  /* 164 */  OCAML_ENVACC2,
  /* 165 */  OCAML_CLOSUREREC_1B, 0, 0, 0, 1, 0, 0, 0, 1, (opcode_t) -47,
  /* 175 */  OCAML_CONST0,
  /* 176 */  OCAML_C_CALL1, 2,
  /* 178 */  OCAML_PUSHACC1,
  /* 179 */  OCAML_APPTERM1, 0, 0, 0, 3,
  /* 184 */  OCAML_ACC0,
  /* 185 */  OCAML_PUSHCONSTINT_2B, 1, 182,
  /* 188 */  OCAML_PUSHGETFLASHGLOBAL_1B, 4,
  /* 190 */  OCAML_PUSHENVACC2,
  /* 191 */  OCAML_APPTERM3, 0, 0, 0, 4,
  /* 196 */  OCAML_ACC0,
  /* 197 */  OCAML_PUSHCONSTINT_2B, 1, 182,
  /* 200 */  OCAML_PUSHGETFLASHGLOBAL_1B, 5,
  /* 202 */  OCAML_PUSHENVACC2,
  /* 203 */  OCAML_APPTERM3, 0, 0, 0, 4,
  /* 208 */  OCAML_RESTART,
  /* 209 */  OCAML_GRAB, 0, 0, 0, 2,
  /* 214 */  OCAML_ACC1,
  /* 215 */  OCAML_PUSHACC1,
  /* 216 */  OCAML_PUSHACC4,
  /* 217 */  OCAML_C_CALL3, 3,
  /* 219 */  OCAML_C_CALL1, 4,
  /* 221 */  OCAML_PUSHACC3,
  /* 222 */  OCAML_PUSHACC1,
  /* 223 */  OCAML_C_CALL2, 5,
  /* 225 */  OCAML_ACC0,
  /* 226 */  OCAML_RETURN, 0, 0, 0, 4,
  /* 231 */  OCAML_C_CALL2, 6,
  /* 233 */  OCAML_CONST0,
  /* 234 */  OCAML_C_CALL1, 7,
  /* 236 */  OCAML_GETFLASHGLOBAL_1B, 0,
  /* 238 */  OCAML_PUSHCONST0,
  /* 239 */  OCAML_C_CALL1, 8,
  /* 241 */  OCAML_CONST1,
  /* 242 */  OCAML_C_CALL1, 4,
  /* 244 */  OCAML_CONST2,
  /* 245 */  OCAML_C_CALL1, 4,
  /* 247 */  OCAML_CLOSURE_1B, 0, (opcode_t) -38,
  /* 250 */  OCAML_PUSH,
  /* 251 */  OCAML_CLOSURE_1B, 1, (opcode_t) -55,
  /* 254 */  OCAML_PUSHACC1,
  /* 255 */  OCAML_CLOSURE_1B, 1, (opcode_t) -71,
  /* 258 */  OCAML_PUSHACC3,
  /* 259 */  OCAML_CLOSURE_1B, 1, (opcode_t) -95,
  /* 262 */  OCAML_PUSH,
  /* 263 */  OCAML_PUSHGETFLASHGLOBAL_1B, 2,
  /* 265 */  OCAML_APPLY1,
  /* 266 */  OCAML_PUSH,
  /* 267 */  OCAML_CLOSUREREC_2B, 0, 0, 0, 1, 0, 0, 0, 1, (opcode_t) -1, 53,
  /* 278 */  OCAML_ACC1,
  /* 279 */  OCAML_CLOSURE_2B, 1, (opcode_t) -1, 85,
  /* 283 */  OCAML_PUSH,
  /* 284 */  OCAML_PUSHGETFLASHGLOBAL_1B, 6,
  /* 286 */  OCAML_C_CALL2, 6,
  /* 288 */  OCAML_CONST0,
  /* 289 */  OCAML_C_CALL1, 9,
  /* 291 */  OCAML_BRANCHIFNOT_1B, 8,
  /* 293 */  OCAML_CLOSURE_2B, 0, (opcode_t) -1, 63,
  /* 297 */  OCAML_PUSHACC2,
  /* 298 */  OCAML_APPLY1,
  /* 299 */  OCAML_ACC0,
  /* 300 */  OCAML_PUSH,
  /* 301 */  OCAML_SETRAMGLOBAL_1B, 0,
  /* 303 */  OCAML_POP, 0, 0, 0, 8,
  /* 308 */  OCAML_CONST0,
  /* 309 */  OCAML_PUSHGETRAMGLOBAL_1B, 0,
  /* 311 */  OCAML_APPLY1,
  /* 312 */  OCAML_STOP
};

#include </home/ben/omicrob/src/byterun/vm/runtime.c>

PROGMEM void * const ocaml_primitives[OCAML_PRIMITIVE_NUMBER] = {
  /*  0 */  (void *) &caml_gc_major,
  /*  1 */  (void *) &caml_ml_flush,
  /*  2 */  (void *) &caml_ml_out_channels_list,
  /*  3 */  (void *) &caml_sys_open,
  /*  4 */  (void *) &caml_ml_open_descriptor_out,
  /*  5 */  (void *) &caml_ml_set_channel_name,
  /*  6 */  (void *) &caml_register_named_value,
  /*  7 */  (void *) &caml_fresh_oo_id,
  /*  8 */  (void *) &caml_ml_open_descriptor_in,
  /*  9 */  (void *) &caml_sys_const_naked_pointers_checked,
};
