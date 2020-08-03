"""
Solution by Albert Ye
AlphaStar 2020 Summer Camp: CC31AB
Problem: nov13-nocow
"""
n, k = input().split(' ')
n = int(n)
k = int(k)
# input array
inp = []
for i in range(n) :
    # list of all words. ignore "cow." and "farmer john has no"
    ls = input().split(' ')
    inp.append(ls[4:-1])

# number of adjectives per cow. suffices to just count inp[0]
m = 0
for i in inp[0] :
    m += 1

# missing cows, but as a string
bad = []
for i in range(n) :
    # string
    bad.append(' '.join(x for x in inp[i]))

adj = [[] for i in range(m) ]
# check if the adjective has already been accounted for
def exists(ind, x) :
    match = False
    for a in adj[ind] :
        if a == x :
            match = True
            break

    return match

# add all inputs into the adjective array
for i in range(n) :
    for j in range(m) :
        if(not exists(j, inp[i][j])) :
            adj[j].append(inp[i][j])

# sort adjective lists
for i in range(m) :
    adj[i].sort()

# number of missing cows before string s
def num_before(s) :
    ret = 0
    for i in range(n) :
        if s >= bad[i] :
            ret += 1
    return ret

# number of combinations using adjectives from x to m-1
def comb(x) :
    ret = 1
    for i in range(x,m) :
        ret *= len(adj[i])
    return ret

# the xth cow
def find_cow(x) :
    # descriptor for the xth cow
    ret = ''
    for i in range(m) :
        if i > 0 : ret += ' '
        # number of combinations of cows from i+1 to m
        combos = comb(i+1)
        # add the appropriate adjective
        ret += adj[i][x//combos]
        # and consider modulo combos
        x %= combos
    return ret

# start with k cows
x = k-1
# add all of the missing cows
while x - num_before(find_cow(x)) < k - 1 :
    x += 1
print(find_cow(x)) 
