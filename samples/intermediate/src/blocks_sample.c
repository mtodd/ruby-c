#include "ruby.h"

// Equivalent Ruby Implementation:
// 
// class BlocksSample
//   def first(x = 10)
//     lambda{ x }
//   end
//   def second(x = 10, &block)
//     block.call(x) if block
//   end
//   def third(x = 10)
//     yield x if block_defined?
//   end
// end

VALUE BlocksSample = Qnil;
void Init_blocks_sample();

VALUE rb_blocks_sample_first(int argc, VALUE *argv, VALUE self) {
  VALUE x = INT2NUM(10);
  VALUE lambda = Qnil;
  
  rb_scan_args(argc, argv, "01", &x);
  
  // How do we create lambdas in C?
  
  // this is equivalent to Proc.new with no block
  // assumes current scope's block, fails if none is specified
  // lambda = rb_block_proc();
  
  return lambda;
}

VALUE rb_blocks_sample_second(int argc, VALUE *argv, VALUE self) {
  VALUE x;
  rb_need_block();
  rb_scan_args(argc, argv, "01", &x);
  if(NIL_P(x)) { x = INT2NUM(10); }
  return rb_yield(x);
}

VALUE rb_blocks_sample_third(int argc, VALUE *argv, VALUE self) {
  VALUE x;
  rb_scan_args(argc, argv, "01", &x);
  if(NIL_P(x)) { x = INT2NUM(10); }
  if(rb_block_given_p()) {
    return rb_yield(x);
  }
  return x;
}

void Init_blocks_sample() {
  BlocksSample = rb_define_class("BlocksSample", rb_cObject);
  rb_define_method(BlocksSample, "first", rb_blocks_sample_first, -1);
  rb_define_method(BlocksSample, "second", rb_blocks_sample_second, -1);
  rb_define_method(BlocksSample, "third", rb_blocks_sample_third, -1);
}
