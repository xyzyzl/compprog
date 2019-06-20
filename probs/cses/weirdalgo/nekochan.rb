start=gets.chomp.to_i
print (start.to_s() + " ")
while start != 1
	if (start % 2).zero?
		start = start/2
	else
		start = 3*start+1
	end
	print (start.to_s() + " ")
end