require 'rubygems'
require 'test/unit'

%w(basic intermediate advanced).each do |level|
  begin
    $:.unshift File.join(File.dirname(__FILE__), '..', 'samples', level)
    require level
  rescue LoadError => e
    STDERR.puts "Unable to load %s extension (all tests will fail): %s" % [level, e.message]
  end
end
