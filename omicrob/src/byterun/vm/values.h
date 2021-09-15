

#ifndef VALUES_H
#define VALUES_H

// #define PROGMEM

// #include <stdio.h>
// #include <inttypes.h>
// #include <assert.h>

/******************************************************************************/

#if OCAML_VIRTUAL_ARCH == 16
#include "values-16.h"
#elif OCAML_VIRTUAL_ARCH == 32
#include "values-32.h"
#elif OCAML_VIRTUAL_ARCH == 64
#include "values-64.h"
#else
#error "Invalid virtual architecture, please define OCAML_VIRTUAL_ARCH"
#endif

// #include "arch-specific.h"

/******************************************************************************/

#define INT32_CUSTOM_FLAG 132
#define INT64_CUSTOM_FLAG 164

/******************************************************************************/

#endif
