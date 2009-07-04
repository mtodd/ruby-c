require 'test_helper'
require 'rack'

class RackApplicationSampleTest < Test::Unit::TestCase
  
  def setup
    @app = RackApplicationSampleTest.new
  end
  
  def test_responds_to_call
    @app.respond_to?(:call)
  end
  
  def test_passes_lint
    Rack::Lint.new(@app)
  end
  
end
