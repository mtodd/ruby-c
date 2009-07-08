#include "ruby.h"

#include "src/blocks_sample.c"
#include "src/c_structs_in_ruby_sample.c"

///////////////////////////////////////////////////////////////////////////////

VALUE Intermediate = Qnil;
void Init_intermediate();

void Init_intermediate() {
  Intermediate = rb_define_module("Intermediate");
  Init_blocks_sample();
  Init_c_structs_in_ruby_sample();
}
