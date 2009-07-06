require 'test_helper'

# class MethodsAndAttributesSampleTest < Test::Unit::TestCase
# end

class MethodsSampleTest < Test::Unit::TestCase
  
  def setup
    @methods = MethodsSample.new
  end
  
  def test_first_takes_no_arguments_and_returns_true
    assert_equal 0, @methods.method(:first).arity
    assert @methods.first
  end
  
  def test_second_takes_one_argument_and_returns_the_argument_passed_in
    assert_equal 1, @methods.method(:second).arity
    assert_equal 1, @methods.second(1)
  end
  
  def test_third_takes_one_argument_and_one_optional_argument_and_returns_first_argument_if_second_is_provided
    assert_equal(-1, @methods.method(:third).arity)
    assert_equal nil, @methods.third(1)
    assert_equal 1, @methods.third(1, true)
  end
  
  def test_fourth_requires_one_argument_and_puts_the_rest_in_an_array
    assert_equal(-1, @methods.method(:fourth).arity)
    assert_equal [1], @methods.fourth(1)
    assert_equal [1, [2, 3]], @methods.fourth(1, 2, 3)
  end
  
  def test_fifth_accepts_an_options_hash_and_returns_it_if_z_is_true
    assert_equal( -1, @methods.method(:fifth).arity )
    assert_equal( {"z" => true}, @methods.fifth(10) )
    assert_equal( {"z" => true, "y" => false}, @methods.fifth(10, "z" => true, "y" => false) )
    assert_equal( nil, @methods.fifth(10, "z" => false) )
  end
  
end
