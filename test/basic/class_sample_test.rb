require 'test_helper'

class ClassSampleTest < Test::Unit::TestCase
  
  def test_class_sample_is_a_class
    assert ClassSample.is_a?(Class)
  end
  
end
