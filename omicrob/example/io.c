
#include "values-32.h"

extern void gc(void);

value caml_gc_major(value v)
{
  gc();
  return Val_unit;
}