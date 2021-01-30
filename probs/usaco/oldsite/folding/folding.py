"""
Solution by Albert Ye
AlphaStar 2020 Summer Camp: CC31AB
Problem: feb12-folding
"""
n, l = input().split(' ')
n = int(n) # number of knots in rope
l = int(l) # length of rope
pos = [] # position of knots in rope
diff = [] # distance between adjacent knots
for i in range(n) :
    pos.append(int(input()))
pos.sort()
for i in range(n-1) :
    diff.append(pos[i+1] - pos[i])
"""
Key observation is that valid positions correspond
to palindromes in the diff array.
"""
# number of valid positions
ans = 0
# check for palindromes on the left or the right
# left palindromes
for i in range(n-1) :
    works = True
    for j in range(n) :
        if j > i - j :
            break
        if diff[j] != diff[i-j] :
            works = False
            break
    if works :
        ans += 1
# right palindromes
for i in range(1, n-1) :
    works = True
    for j in range(n) :
        if i + j > n-2 - j :
            break
        if diff[i+j] != diff[n-2-j] :
            works = False
            break
    if works :
        ans += 1
print(ans)
