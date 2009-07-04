#include "ruby.h"

#include "src/module_sample.c"
#include "src/class_sample.c"
#include "src/method_sample.c"

///////////////////////////////////////////////////////////////////////////////

VALUE Basic = Qnil;
void Init_basic();

void Init_basic() {
  Basic = rb_define_module("Basic");
  Init_module_sample();
  Init_class_sample();
  Init_method_sample();
}
