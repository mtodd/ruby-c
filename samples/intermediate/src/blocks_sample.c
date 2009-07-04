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

void Init_blocks_sample() {
  BlocksSample = rb_define_class("BlocksSample", rb_cObject);
}
