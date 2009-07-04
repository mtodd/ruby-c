require 'test_helper'

class ClassesAndModulesSampleTest < Test::Unit::TestCase
  
  # class Bar < Foo::Base; include ActsAsFoo; end
  
  def setup
    @bar = Bar.new
  end
  
  def test_bar_is_a_foo
    assert @bar.is_a?(Foo::Base)
  end
  
  def test_bar_inherits_methods_from_foo_base
    assert @bar.respond_to?(:foo!)
    assert @bar.foo!
  end
  
  def test_bar_acts_like_foo
    assert @bar.kind_of?(ActsAsFoo)
    
    assert @bar.respond_to?(:foo?)
    assert @bar.foo?
    
    assert Bar.respond_to?(:foo?)
    assert Bar.foo?
  end
  
end
