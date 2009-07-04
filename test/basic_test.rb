require 'test_helper'
require 'basic'

class BasicTest < Test::Unit::TestCase
  def test_basics
    assert ModuleSample.is_a?(Module)
    assert ClassSample.is_a?(Class)
    assert MethodSample.is_a?(Class)
    assert m = MethodSample.new
    assert m.respond_to?(:first)
    assert m.first == 10
  end
end
