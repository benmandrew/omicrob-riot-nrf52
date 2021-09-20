#ifndef __TEST_DEF__
#define __TEST_DEF__
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

#include </Users/ben/Desktop/Projects/riot-omicrob/omicrob/src/byterun/vm/values.h>

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

#endif