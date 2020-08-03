"""
Solution by Albert Ye
AlphaStar 2020 Summer Camp: CC31AB
Problem: jan17-cowcode
"""
s, n = input().split(' ')
n = int(n)
m = len(s)
while m*2 < n :
    m *= 2
while n > len(s) :
    ###################################################
    # remap n to first half but remember cyclic shift #
    # m+1 maps to m and m+2...2m go to 1...m-1.       #
    ###################################################
    if n == m+1 :
        n = m
    else :
        n -= m+1
    ###################################################
    # decrease m for the next step                    #
    ###################################################
    while m >= n :
        m //= 2

# total complexity: O(lg n)
print(s[n-1])
