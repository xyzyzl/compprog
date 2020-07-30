n = int(input()) # number of dance lines
for _ in range(n) :
    m, s = input().split(' ') # m = length of string, s = string of cows
    m = int(m)
    delta = 0 # number of '>' cows minus number of '<' cows.
    legal = True # if the configuration is legal
    for c in s :
        if c == '>' :
            delta += 1
        else :
            delta -= 1
        if delta < 0 :
            legal = False
            break
    # Must have equal number of '>' cows and '<' cows.
    if delta != 0 :
        legal = False
    ret = 'legal'
    if not legal :
        ret = 'illegal'
    print(ret)
