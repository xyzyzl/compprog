# 2d bit but in python

n, q = map(int,input().split())

s = []
for i in range(n):
    s.append(input())


bit = [ [0 for i in range(n+5)] for i in range(n+5) ]

def updy(x, y, val):
    while y <= n:
        bit[x][y] += val 
        y += (y&-y)

def upd(x, y, val):
    while x <= n:
        updy(x, y, val)
        x += (x&-x)

def quey(x, y):
    ret = 0
    while y > 0: 
        ret += bit[x][y]
        y -= (y&-y)
    return ret 

def que(x, y):
    ret = 0
    while x > 0:
        ret += quey(x, y)
        x -= (x&-x)
    return ret 

def qu(x0, y0, x1, y1):
    if x1 < x0: 
        p = x1
        x1 = x0
        x0 = p 
    if y1 < y0:
        p = y1
        y1 = y0 
        y0 = p 
    x0 -= 1
    y0 -= 1
    b1 = que(x1, y1)
    b2 = que(x0, y1)
    b3 = que(x1, y0)
    b4 = que(x0, y0)
    return b1-b2-b3+b4 

A = [ [ 0 for i in range(n) ] for i in range(n) ]
for i in range(n):
    for j in range(n):
        if s[i][j] == '*':
            upd(i+1, j+1, 1)
            A[i][j] = 1

for i in range(q):
    inp = list(map(int, input().split()))
    if inp[0] == 1:
        x = inp[1]
        y = inp[2]
        upd(x, y, (-1 if A[x-1][y-1] == 1 else 1))
        A[x-1][y-1] = 1-A[x-1][y-1]
    else:
        x0 = inp[1]
        y0 = inp[2]
        x1 = inp[3]
        y1 = inp[4]
        print(qu(x0, y0, x1, y1))