# doubly serves as implementation of derangement function

n = gets.chomp.to_i()

j1=0
j2=0
for i in 2..n
	j2=(i*j1+((i % 2).zero? ? 1 : -1)) % 1000000007
	j1=j2
end
puts j2 % 1000000007
