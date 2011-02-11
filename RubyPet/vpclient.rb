# The wrapper for the replacement vpclient program, client.rb

require 'rubygems'
require 'daemons'

puts("VPClient activated")
Daemons.run('client.rb')

