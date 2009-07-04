require 'test_helper'

class MethodSampleTest < Test::Unit::TestCase
  
  def test_method_sample_is_a_class
    assert MethodSample.is_a?(Class)
  end
  
  def test_method_sample_instance_responds_to_first
    m = MethodSample.new
    assert m.respond_to?(:first)
  end
  
  def test_method_sample_instance_method_first_returns_10
    m = MethodSample.new
    assert m.first == 10
  end
  
end
