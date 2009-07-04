require 'test_helper'
require 'rack'
require 'rack/mock'
require 'benchmark'

# class << Benchmark
#   if !const_defined?(:Rails) or Rails::VERSION::STRING < '2.3.0'
#     def ms
#       1000 * realtime { yield }
#     end
#   end
# end

# class RackApplicationSampleRubyEquivalent
#   def call(env)
#     body = "OK"
#     [ 200,
#       { 'Content-Type'=>'text/plain',
#         'Content-Length'=> body.size.to_s },
#       body ]
#   end
# end

class RackApplicationSampleTest < Test::Unit::TestCase
  
  def setup
    @app = RackApplicationSample.new
  end
  
  def test_responds_to_call
    assert @app.respond_to?(:call)
  end
  
  def test_passes_lint
    request = Rack::MockRequest.new(@app)
    response = request.get('/', :lint => true)
    assert_equal 200, response.status
  end
  
  # FIXME: not a realistic test, necessarily, and no consistent outcome
  # 
  # def test_is_faster_than_ruby_equivalent
  #   ruby_app      = RackApplicationSampleRubyEquivalent.new
  #   c_runtime     = Benchmark.ms{ Rack::MockRequest.new(@app    ).get('/') }
  #   ruby_runtime  = Benchmark.ms{ Rack::MockRequest.new(ruby_app).get('/') }
  #   assert c_runtime < ruby_runtime
  # end
  
end
