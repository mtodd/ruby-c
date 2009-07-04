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
  VALUE body      = rb_str_new2("OK");
  VALUE status    = INT2NUM(200);
  VALUE response  = rb_ary_new();
  VALUE headers   = rb_hash_new();
  
  rb_hash_aset(headers, rb_str_new2("Content-Type"), rb_str_new2("text/plain"));
  rb_hash_aset(headers, rb_str_new2("Content-Length"), rb_funcall(INT2NUM(RSTRING(body)->len), rb_intern("to_s"), 0));
  
  rb_ary_push(response, status);
  rb_ary_push(response, headers);
  rb_ary_push(response, body);
  
  return response;
}

void Init_rack_application_sample() {
  RackApplicationSample = rb_define_class("RackApplicationSample", rb_cObject);
  rb_define_method(RackApplicationSample, "call", rb_rack_application_call, 1);
}
