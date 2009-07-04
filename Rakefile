require 'rake'
require 'rake/testtask'
# require 'test/unit'

task :default => [:test]

desc "Run tests"
Rake::TestTask.new("test") { |t|
  t.pattern = 'test/*_test.rb'
  t.verbose = true
  t.warning = true
}

desc "Clean compile products"
task :clean do
  `rm -f Makefile`
  `rm -f *.{o,so,bundle}`
end

desc "Generate the Makefile used to compile"
task :generate_makefile do
  `ruby extconf.rb`
end

desc "Compile"
task :compile => [:generate_makefile] do
  `make`
end

desc "Clean then compile"
task :clean_and_compile => [:clean, :compile]
task :cnc => :clean_and_compile
