#include "ruby.h"

// topics:
// * methods
// ** method definition equivalencies
// *** mandatory params
// *** optional params & handling defaults
// *** option-hashes
// *** blocks => intermediate samples
// ** method invocation
// * attributes
// ** instance variables
// ** attr_accessor
// ** getters and setters
// ** class variables=

VALUE MethodsAndAttributesSample = Qnil;

VALUE MethodsSample = Qnil;

VALUE AttributesSample = Qnil;
VALUE AttributesSample_one = Qnil;

void Init_methods_and_attributes_sample();

// Methods

// Equivalent Ruby Implementation:
/*
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

VALUE rb_methods_sample_fifth(int argc, VALUE *args, VALUE self) {
  VALUE a, options, default_options, keys, key;
  VALUE z = rb_str_new2("z");
  rb_scan_args(argc, args, "11", &a, &options);
  if(NIL_P(options)){ options = rb_hash_new(); }
  
  // default options
  default_options = rb_hash_new();
  rb_hash_aset(default_options, z, Qtrue);
  
  options = rb_funcall(default_options, rb_intern("merge"), 1, options);
  
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

// Attributes

// Equivalent Ruby Implementation:
/*
  class AttributesSample
    attr_accessor :one
    def first
      self.one
    end
    def first=(a)
      self.one = a
    end
  end
*/

VALUE rb_attributes_sample_first(VALUE self) {
  return rb_iv_get(self, "@one");
}

VALUE rb_attributes_sample_first_assign(VALUE self, VALUE value) {
  return rb_iv_set(self, "@one", value);
}

void Init_attributes_sample() {
  AttributesSample = rb_define_class("AttributesSample", rb_cObject);
  rb_define_method(AttributesSample, "first", rb_attributes_sample_first, 0);
  rb_define_method(AttributesSample, "first=", rb_attributes_sample_first_assign, 1);
  rb_define_attr(AttributesSample_one, "one", 1, 1); // read=1, write=1
}

///////////////////////////////////////////////////////////////////////////////

void Init_methods_and_attributes_sample() {
  MethodsAndAttributesSample = rb_define_class("MethodsAndAttributesSample", rb_cObject);
  Init_methods_sample();
  Init_attributes_sample();
}
