#include "ruby.h"

// Equivalent Ruby Implementation:
// 
// class RackApp
//   def call(env)
//     body = "OK"
//     [ 200,
//       { 'Content-Type'=>'text/plain',
//         'Content-Length'=> body.size.to_s },
//       body ]
//   end
// end

VALUE RackApplicationSample = Qnil;
void Init_rack_application_sample();

VALUE rb_rack_application_call(VALUE env);
VALUE rb_rack_application_call(VALUE env) {
  VALUE response = Qnil;
  return response;
}

void Init_rack_application_sample() {
  RackApplicationSample = rb_define_class("RackApplicationSample", rb_cObject);
  rb_define_method(RackApplicationSample, "call", rb_rack_application_call, 1);
}
