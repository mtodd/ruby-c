#include "ruby.h"

#include "src/classes_and_modules_sample.c"
#include "src/methods_and_attributes_sample.c"

///////////////////////////////////////////////////////////////////////////////

VALUE Basic = Qnil;
void Init_basic();

void Init_basic() {
  Basic = rb_define_module("Basic");
  Init_classes_and_modules_sample();
  Init_methods_and_attributes_sample();
}
