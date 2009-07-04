#include "ruby.h"

// Equivalent Ruby Implementation:
// 
// Thread.new{ loop{ puts "hi!"; sleep 1 }}

VALUE BackgroundThreadSample = Qnil;
void Init_background_thread_sample();

void Init_background_thread_sample() {
  BackgroundThreadSample = rb_define_class("BackgroundThreadSample", rb_cObject);
}
