require 'rake'
require 'rake/testtask'

task :default => [:test]

desc "Run tests"
Rake::TestTask.new("test") { |t|
  t.pattern = 'test/**/*_test.rb'
  t.libs << "test"
  t.libs << "samples/basic"
  t.libs << "samples/intermediate"
  t.libs << "samples/advanced"
  t.verbose = true
  t.warning = true
}

desc "Clean compile products"
task :clean do
  do_run "make clean"
  do_run "rm Makefile"
end

desc "Generate the Makefile used to compile"
task :generate_makefile => [:clean] do
  do_run "ruby extconf.rb"
end

desc "Compile"
task :compile => [:generate_makefile] do
  do_run "make"
end

desc "Clean then compile"
task :clean_and_compile => [:clean, :compile]
task :cnc => :clean_and_compile

task :all do
  %w(basic intermediate advanced).each do |level|
    %x{env EXT=#{level} rake generate_makefile}
    %x{env EXT=#{level} rake compile}
  end
  puts %x{rake}
end

def do_run cmd, context = "samples/#{ENV['EXT']}"
  pwd = Dir.pwd
  # cmd += " --trace" if cmd =~ /rake/ && true
  cmd = %(cd "#{context}" && env EXT=#{ENV['EXT']} #{cmd}; cd "#{pwd}")
  puts cmd
  puts "=> %s" % %x{#{cmd}}
end
