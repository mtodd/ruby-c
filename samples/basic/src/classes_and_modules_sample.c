#include "ruby.h"

// Equivalent Ruby Implementation:
/*
  class ClassesAndModulesSample
  end
  
  class Foo
    class Base
      def foo!
        # deep, dark magic here
        true
      end
    end
  end
  class Bar < Foo; end
  
  module ActsAsFoo
    def included(target)
      target.extend ClassMethods
    end
    def foo?
      true
    end
    module ClassMethods
      def foo?
        true
      end
    end
  end
  class Bar < Foo
    include ActsAsFoo
  end
  
*/

VALUE ClassesAndModulesSample = Qnil;

VALUE Foo = Qnil;
VALUE Foo_Base = Qnil;
VALUE Bar = Qnil;

VALUE ActsAsFoo = Qnil;
VALUE ActsAsFoo_ClassMethods = Qnil;

void Init_classes_and_modules_sample();

// Foo

VALUE rb_Foo_Base_find_b(VALUE self) {
  return Qtrue;
}

void Init_foo() {
  Foo = rb_define_class("Foo", rb_cObject);
  
  Foo_Base = rb_define_class_under(Foo, "Base", rb_cObject);
  rb_define_method(Foo_Base, "foo!", rb_Foo_Base_find_b, 0);
}

// Bar

void Init_bar() {
  Bar = rb_define_class("Bar", Foo_Base);
}

// ActsAsFoo

VALUE rb_ActsAsFoo_foo_q(VALUE self) {
  return Qtrue;
}

VALUE rb_ActsAsFoo_included(VALUE self, VALUE target) {
  rb_extend_object(target, ActsAsFoo_ClassMethods);
  return self;
}

void Init_acts_as_foo() {
  ActsAsFoo = rb_define_module("ActsAsFoo");
  rb_define_method(ActsAsFoo, "foo?", rb_ActsAsFoo_foo_q, 0);
  rb_define_singleton_method(ActsAsFoo, "included", rb_ActsAsFoo_included, 1);
  
  ActsAsFoo_ClassMethods = rb_define_module_under(ActsAsFoo, "ClassMethods");
  rb_define_method(ActsAsFoo_ClassMethods, "foo?", rb_ActsAsFoo_foo_q, 0);
  
  rb_include_module(Bar, ActsAsFoo);
  // call ActsAsFoo.included(Bar) manually since rb_include_module doesn't
  rb_funcall(ActsAsFoo, rb_intern("included"), 1, Bar);
}

///////////////////////////////////////////////////////////////////////////////

void Init_classes_and_modules_sample() {
  ClassesAndModulesSample = rb_define_class("ClassesAndModulesSample", rb_cObject);
  
  Init_foo();
  Init_bar(); // class Bar < Foo::Base; end
  
  Init_acts_as_foo();
}
