#include "ruby.h"

#include "src/background_thread_sample.c"
#include "src/rack_application_sample.c"

///////////////////////////////////////////////////////////////////////////////

VALUE Advanced = Qnil;
void Init_advanced();

void Init_advanced() {
  Advanced = rb_define_module("Advanced");
  Init_background_thread_sample();
  Init_rack_application_sample();
}
