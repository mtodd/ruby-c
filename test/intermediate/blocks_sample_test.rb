require 'test_helper'

class BlocksSampleTest < Test::Unit::TestCase
  
  def setup
    @object = BlocksSample.new
  end
  
  def test_first_returns_lambda
    response = @object.first
    assert response.is_a?(Proc)
    assert response.respond_to?(:call)
  end
  
  def test_lambda_first_returns_returns_10_when_called_with_10
    assert_equal 10, @object.first.call(10)
  end
  
end
