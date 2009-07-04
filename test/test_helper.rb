require 'rubygems'
require 'test/unit'

%w(basic intermediate advanced).each do |level|
  $:.unshift File.join(File.dirname(__FILE__), '..', 'samples', level)
  require level
end
