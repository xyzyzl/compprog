# use 2d bit or smth
n = int(input())

a = []
for i in range(n):
    l, w, h, p = map(int, input().split())
    if l < w:
        k = w
        w = l 
        l = k 
    a.append((h,l,w,p,i+1))

bit = [[(0, 0) for i in range(5005)] for i in range(5005)]

def updy(x, y, val):
    while y <= 5000:
        if val[0] > bit[x][y][0]:
            bit[x][y] = val
        y += (y&-y)

def upd(x, y, val):
    while x <= 5000:
        updy(x, y, val)
        x += (x&-x)

def quey(x, y):
    ret = 0
    val = -1
    while y > 0:
        if bit[x][y][0] > ret:
            ret = bit[x][y][0]
            val = bit[x][y][1]
        y -= (y&-y)
    return (ret,val)

def que(x, y):
    ret = 0
    val = -1
    while x > 0:
        k = quey(x,y)
        if k[0] > ret:
            ret = k[0]
            val = k[1]
        x -= (x&-x)
    return (ret,val)

a.sort()
last = [-1 for i in range(n)]
ans = [0 for i in range(n)]
for i in range(n):
    p = que(a[i][1], a[i][2])
    last[i] = p[1]
    tot = a[i][3]+p[0]
    ans[i] = tot
    upd(a[i][1], a[i][2], (tot, i))

mxi = -1
bes = 0
for i in range(n):
    if ans[i] > bes:
        mxi = i
        bes = ans[i]

print(bes)

l = []
while mxi != -1:
    l.append(a[mxi][4])
    mxi = last[mxi]

print(len(l))
print(*l, sep=' ')