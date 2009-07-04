require 'test_helper'

class ModuleSampleTest < Test::Unit::TestCase
  
  def test_module_sample_is_a_module
    assert ModuleSample.is_a?(Module)
  end
  
end
