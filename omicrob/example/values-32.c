#include "test_def.h"

void assign_Field(value* val, int i, value newval) {
  if (Is_in_ram(val)) {
    Ram_field(val, i) = newval;
  } else {
    Flash_field(val, i) = newval;
  }
}

void assign_Hd_val(value* val, value newval) {
  if (Is_in_ram(val)) {
    Ram_field(val, -1) = newval;
  } else {
    Flash_field(val, -1) = newval;
  }
}

void assign_Hd_op(value* val, value newval) {
  if (Is_in_ram(val)) {
    Ram_field(val, -1) = newval;
  } else {
    Flash_field(val, -1) = newval;
  }
}

void assign_Closinfo_val(value* val, value newval) {
  if (Is_in_ram(val)) {
    Ram_field(val, 1) = newval;
  } else {
    Flash_field(val, 1) = newval;
  }
}