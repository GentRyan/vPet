#!/usr/bin/ruby
require 'socket'
$stats = [0,0,0,0]
def parser(message)
	message = message.split(" ")
	$stats[0] = message[0].to_i
	$stats[1] = message[1].to_i
	$stats[2] = message[2].to_i
	$stats[3] = message[3].to_i
end

def adjust(a,b)
	message = "m" + a.to_s + b.to_s
	
	hostname = 'localhost'
	port = 30000
	vPet = TCPSocket.open(hostname, port)

	vPet.puts(message)
	report = vPet.recv(1024)
	vPet.close()
end

def messanger()
	hostname = 'localhost'
	port = 30000
	vPet = TCPSocket.open(hostname, port)

	vPet.puts('d')
	message = vPet.recv(1024)
	vPet.close()
	message
end

def main

	ageTimeout = 0
	year = 0

	while true
		if year > 43200
		then
			adjust(3,1)
		end
		parser(messanger())
		ageTimeout = $stats[3] * 599 unless (ageTimeout = $stats[3] * 599) > 7200
		
		
		if (ageTimeout = $stats[3] * 599) > 7200
		then
			ageTimeout = 7200
		end
		
		sleep(ageTimeout)
		year = ageTimeout + year
		adjust(0,-1)
		parser(messanger())
		if year > 43200
		then
			adjust(3,1)
		end
		
		sleep(ageTimeout-(ageTimeout/2))
		adjust(1,-1)
		parser(messanger)
		year = year + ageTimeout
		 
		if year > 43200
		then
			adjust(3,1)
		
		end
	
	end
end

main()
