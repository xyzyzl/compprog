import sys

a, b, c = input().split(' ')
a = int(a)
b = int(b)
c = int(c)

l = [0, a, b, c]

print('First')

def interact(addend) :
    print(addend)
    sys.stdout.flush()
    ret = int(input())
    return ret

place = [0, 0, 0, 0]
mx    = [0, 0, 0, 0]
if a > b  and  b > c :
    place[1] = 3
    mx[3]    = 1
    place[2] = 2
    mx[2]    = 2
    place[3] = 1
    mx[1]    = 3
elif a > c and c > b :
    place[1] = 3
    mx[3]    = 1
    place[2] = 1
    mx[1]    = 2
    place[3] = 2
    mx[2]    = 3
elif b > a and a > c :
    place[1] = 2
    mx[2]    = 1
    place[2] = 3
    mx[3]    = 2
    place[3] = 1
    mx[1]    = 3
elif b > c and c > a :
    place[1] = 1
    mx[1]    = 1
    place[2] = 3
    mx[3]    = 2
    place[3] = 2
    mx[2]    = 3
elif c > a and a > b :
    place[1] = 2
    mx[2]    = 1
    place[2] = 1
    mx[1]    = 2
    place[3] = 3
    mx[3]    = 3
elif c > b and b > a :
    place[1] = 1
    mx[1]    = 1
    place[2] = 2
    mx[2]    = 2
    place[3] = 3
    mx[3]    = 3

x = interact(l[mx[3]]*2 - l[mx[2]] - l[mx[1]])
l[x] += (l[mx[3]]*2 - l[mx[2]] - l[mx[1]])
if   place[x] == 1 :
    l[interact(l[mx[3]] - l[mx[2]])] += l[mx[3]] - l[mx[2]]
elif place[x] == 2 :
    l[interact(l[mx[3]] - l[mx[1]])] += l[mx[3]] - l[mx[1]]
else :
    y = interact(l[mx[3]]*2 - l[mx[2]] - l[mx[1]])    
    l[y] += (l[mx[3]]*2 - l[mx[2]] - l[mx[1]])
    if place[y] == 1 :
        l[interact(l[mx[3]] - l[mx[2]])] += l[mx[3]] - l[mx[2]]
    elif place[y] == 2 :
        l[interact(l[mx[3]] - l[mx[1]])] += l[mx[3]] - l[mx[1]]

