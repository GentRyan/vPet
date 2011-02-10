#!/usr/bin/ruby
require 'socket'

hostname = 'localhost'
port = 30000
vPet = TCPSocket.open(hostname, port)

vPet.puts('d')
message = vPet.recv(1024)
vPet.close()

message = message.split(" ")

puts("Stats:")
puts("Hunger: " + message[0])
puts("Happiness: " + message[1])
puts("Weight: " + message[2])
puts("Age: " + message[3])
