#include "ruby.h"

#include "src/blocks_sample.c"

///////////////////////////////////////////////////////////////////////////////

VALUE Intermediate = Qnil;
void Init_intermediate();

void Init_intermediate() {
  Intermediate = rb_define_module("Intermediate");
  Init_blocks_sample();
}
