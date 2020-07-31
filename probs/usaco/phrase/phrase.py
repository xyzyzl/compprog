"""
Solution by Albert Ye
AlphaStar 2020 Summer Camp: CC31AB
Problem: feb06-phrase
"""
# for binary search
import bisect
m, n = input().split(' ')
n = int(n)
m = int(m)
# phrasebook
book = []
for i in range(m) :
    book.append(input())
# sort phrasebook
book.sort()
# number of valid prefixes
ans = 0
for i in range(n) :
    s = input()
    # similar to c++'s lower_bound()
    x = bisect.bisect_left(book,s)
    # check if its index is out of bounds, in which case
    # it can't be a prefix
    if x >= len(book) :
        continue
    t = book[x]
    # match all characters of s, t and see if it's prefix
    is_prefix = True
    # check if characters match
    for j in range(min(len(t), len(s))) :
        if s[j] != t[j] :
            is_prefix = False
    # if they match, add to the answer
    if is_prefix :
        ans+=1
print(ans)
