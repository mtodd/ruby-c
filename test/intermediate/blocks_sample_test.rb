require 'test_helper'

class BlocksSampleTest < Test::Unit::TestCase
  
  def setup
    @object = BlocksSample.new
  end
  
  # How do we create lambdas in C?
  # 
  # def test_first_returns_lambda
  #   response = @object.first
  #   assert response.is_a?(Proc)
  #   assert response.respond_to?(:call)
  # end
  # 
  # def test_lambda_first_returns_returns_10_when_called_with_10
  #   assert_equal 10, @object.first(10).call
  # end
  
  def test_second_requires_a_block
    assert_raise LocalJumpError do
      @object.second
    end
  end
  
  def test_second_returns_result_from_block
    assert_equal 124, @object.second{ 124 }
  end
  
  def test_second_yields_argument_to_block
    @object.second(44) do |n|
      assert_equal 44, n
    end
  end
  
  def test_third_returns_default_value_if_no_argument_or_block_is_provided
    assert_nothing_raised do
      assert_equal 10, @object.third
    end
  end
  
  def test_third_passes_argument_to_lambda_and_returns_result_of_lambda
    assert_equal 4 * 2, @object.third(4){ |n| n * 2 }
  end
  
end
