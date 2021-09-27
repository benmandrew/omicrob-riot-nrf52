#ifndef __TEST_DEF__
#define __TEST_DEF__
#define OCAML_STACK_WOSIZE                64
#define OCAML_STATIC_HEAP_WOSIZE           0
#define OCAML_DYNAMIC_HEAP_WOSIZE        256
#define OCAML_FLASH_HEAP_WOSIZE           41
#define OCAML_STACK_INITIAL_WOSIZE         0
#define OCAML_RAM_GLOBDATA_NUMBER          0
#define OCAML_FLASH_GLOBDATA_NUMBER        0
#define OCAML_BYTECODE_BSIZE               1
#define OCAML_PRIMITIVE_NUMBER             0
#define OCAML_VIRTUAL_ARCH                32
#define OCAML_STARTING_OOID                0
#define OCAML_NO_FLASH_HEAP                0
#define OCAML_NO_FLASH_GLOBALS             0

#define OCAML_GC_MARK_AND_COMPACT

#include </Users/ben/Desktop/Projects/riot-omicrob/omicrob/src/byterun/vm/values.h>

#define OCAML_STOP                        0

#endif