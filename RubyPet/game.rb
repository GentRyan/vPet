#!/usr/bin/ruby
require 'socket'
x = 0
wins = 0
while x < 3
print "\e[H\e[2J"
card1 = rand(14)
puts("Pika-Card game!")
puts(card1.to_s + "  ?")
puts("Will the drawn card be (h)igher? Or (l)ower?")
choice = gets.chomp
card2 = rand(14)
print "\e[H\e[2J"
puts("Pika-Card game!")
puts(card1.to_s + "  " + card2.to_s)

if card2 > card1 and choice == 'h'
then
	sucess = true
elsif card2 < card1 and choice == 'l'
then
	sucess = true
else
	sucess = false
end

puts("Your guess was: " + choice)
if sucess == true then
	puts("Congradulations! You bet correctly!")
	wins = wins + 1
else
	puts("Sorry! You lost.")
end
gets
x = x + 1
end
puts("Wins: #{wins}")
if wins >= 2 then
	hostname = 'localhost'
	port = 30000
	vPet = TCPSocket.open(hostname, port)
	vPet.puts('m 2 -2')
	vPet.puts('m 1 1')
	vPet.close
end

