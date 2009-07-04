#include "ruby.h"

// Equivalent Ruby Implementation:
// 
// class MethodSample
//   def first
//     10
//   end
// end

VALUE MethodSample = Qnil;
void Init_method_sample();

VALUE rb_method_sample_first(VALUE self);

void Init_method_sample() {
  MethodSample = rb_define_class("MethodSample", rb_cObject);
  rb_define_method(MethodSample, "first", rb_method_sample_first, 0);
}

VALUE rb_method_sample_first(VALUE self) {
  int x = 10;
  return INT2NUM(x);
}
