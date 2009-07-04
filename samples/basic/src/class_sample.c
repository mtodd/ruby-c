#include "ruby.h"

// Equivalent Ruby Implementation:
// 
// class ClassSample
// end

VALUE ClassSample = Qnil;
void Init_class_sample();

void Init_class_sample() {
  ClassSample = rb_define_class("ClassSample", rb_cObject);
}
