#!/usr/bin/ruby
require 'socket'

hostname = 'localhost'
port = 30000
vPet = TCPSocket.open(hostname, port)
if ARGV.length > 1 then puts("Too many arguments, mang!"); ARGV[0] = nil end
if ARGV.length < 1 then puts("No food selected. Options are Rice, Cake, and Tostadas") end

case ARGV[0]
	when "Rice" then
	vPet.puts('m 0 1')
	vPet.puts('m 1 0')
	vPet.puts('m 2 2')
	when "Cake" then
	vPet.puts('m 0 1')
	vPet.puts('m 1 2')
	vPet.puts('m 2 3')
	when "Tostada" then
	vPet.puts('m 0 2')
	vPet.puts('m 1 2')
	vPet.puts('m 2 4')
end

vPet.close