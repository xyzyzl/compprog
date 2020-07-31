"""
Solution by Albert Ye
AlphaStar 2020 Summer Camp: CC31AB
Problem: dec19-moobuzz
"""
n = int(input())
"""
key observation is that the fizzbuzz sequence
is periodic modulo 15, and that there are 8
numbers spoken in the first 15. the rest of the numbers
can just be put into an array and solved for that way
"""
# the answers for the first 8 numbers in sequence
mod8 = [1, 2, 4, 7, 8, 11, 13, 14, 16]
# floor((n-1)/8)* 15 counts the number of periods before we search for answer
# mod8[(n-1) mod 8] is the result from the residue modulo 8
print((n-1)//8 * 15 + mod8[(n-1)%8])
