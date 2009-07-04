#include "ruby.h"

// Equivalent Ruby Implementation:
// 
// module ModuleSample
// end

VALUE ModuleSample = Qnil;
void Init_module_sample();

void Init_module_sample() {
  ModuleSample = rb_define_module("ModuleSample");
}
