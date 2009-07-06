#include "ruby.h"
#include "st.h"

// topics:
// * methods
// ** method definition equivalencies
// *** mandatory params
// *** optional params & handling defaults
// *** option-hashes
// *** blocks
// ** method invocation
// * attributes
// ** instance variables
// ** attr_accessor
// ** getters and setters
// ** class variables=

// Equivalent Ruby Implementation:
/*
  class MethodsAndAttributesSample
  end
  
  class MethodsSample
    def first
      true
    end
    def second(a)
      a
    end
    def third(a, b = true)
      a if b
    end
    def fourth(a, *b)
      [a, b]
    end
    def fifth(a, options = {})
      options = {:z => true}.merge(options)
      a if options[:z]
    end
  end
  
  class AttributesSample
    #
  end
*/

VALUE MethodsAndAttributesSample = Qnil;

VALUE MethodsSample = Qnil;
VALUE AttributesSample = Qnil;

void Init_methods_and_attributes_sample();

// Methods

VALUE rb_methods_sample_first(VALUE self) {
  return Qtrue;
}

VALUE rb_methods_sample_second(VALUE self, VALUE a) {
  return a;
}

VALUE rb_methods_sample_third(int argc, VALUE *args, VALUE self) {
  VALUE a, b;
  rb_scan_args(argc, args, "11", &a, &b);
  if(!NIL_P(b)) { // if b
    return a;
  }
  return Qnil;
}

VALUE rb_methods_sample_fourth(int argc, VALUE *args, VALUE self) {
  VALUE response = rb_ary_new();
  VALUE a, rest;
  rb_scan_args(argc, args, "10*", &a, &rest);
  rb_ary_push(response, a);
  if(RARRAY(rest)->len > 0){ rb_ary_push(response, rest); }
  return response;
}

// def fifth(a, options = {})
//   options = {:z => true}.merge(options)
//   a if options[:z]
// end

// pulled from hash.c
static int
keys_i(key, value, ary)
    VALUE key, value, ary;
{
    if (key == Qundef) return ST_CONTINUE;
    rb_ary_push(ary, key);
    return ST_CONTINUE;
}

VALUE rb_methods_sample_fifth(int argc, VALUE *args, VALUE self) {
  VALUE a, options, default_options, keys, key;
  VALUE z = rb_str_new2("z");
  rb_scan_args(argc, args, "11", &a, &options);
  if(NIL_P(options)){ options = rb_hash_new(); }
  
  // default options
  default_options = rb_hash_new();
  rb_hash_aset(default_options, z, Qtrue);
  options = rb_funcall(default_options, rb_intern("merge"), 1, options);
  
  // options = {"z" => true}.merge(options)
  // keys = rb_hash_keys(options_input);
  // keys = rb_ary_new();
  // rb_hash_foreach(options_input, keys_i, keys);
  // while(key = rb_ary_pop(keys)) { rb_hash_aset(options, key, rb_hash_aref(options_input, key)); }
  
  // rb_hash_aset(options, rb_str_new2("value"), a); options.merge! "value" => a
  
  if(rb_hash_aref(options, z) == Qtrue){ return options; }
  return Qnil;
}

void Init_methods_sample() {
  MethodsSample = rb_define_class("MethodsSample", rb_cObject);
  rb_define_method(MethodsSample, "first", rb_methods_sample_first, 0);
  rb_define_method(MethodsSample, "second", rb_methods_sample_second, 1);
  rb_define_method(MethodsSample, "third", rb_methods_sample_third, -1);
  rb_define_method(MethodsSample, "fourth", rb_methods_sample_fourth, -1);
  rb_define_method(MethodsSample, "fifth", rb_methods_sample_fifth, -1);
}

///////////////////////////////////////////////////////////////////////////////

void Init_methods_and_attributes_sample() {
  MethodsAndAttributesSample = rb_define_class("MethodsAndAttributesSample", rb_cObject);
  Init_methods_sample();
}
