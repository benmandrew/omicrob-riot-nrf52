#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

#ifndef __ARCH_SPECIFIC__
#define __ARCH_SPECIFIC__

#define PROGMEM

#include "test_def.h"

/******************************************************************************/
/* Blocks */

#define Flash_field(val, i) (Flash_block_val(val)[i])
#define Flash_string_field(val, i) (((uint8_t *) Flash_block_val(val))[i])

void device_init(const char **argv);

void device_finish();

void uncaught_exception(value acc);

static inline char do_read_byte(const opcode_t *ocaml_bytecode, int pc);

static inline uint8_t do_read_byte_from_flash(const void *flash_ptr, int ind);

static inline void *do_get_primitive(void *const primitives[], uint8_t prim_ind);

static inline value do_read_flash_data_1B(const value flash_global_data[], uint8_t glob_ind);

static inline value do_read_flash_data_2B(const value flash_global_data[], uint8_t glob_ind);

void format_int64(char *buf, int bufsize, value v);

#if DEBUG >= 2
#define TRACE_INSTRUCTION(instr_name) printf("[%3d]: " instr_name "\n", pc - 1); cpt_instr++; fflush(stdout)
#elif DEBUG >=1
#define TRACE_INSTRUCTION(instr_name) cpt_instr++;
#else
#define TRACE_INSTRUCTION(instr_name)
#endif

#include "test_ext.h"

#endif
