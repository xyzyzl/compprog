n = int(input())
dep = []
for i in range(n) :
    dep.append(0)
for i in range(n-1) :
    a, b = input().split(' ')
    a = int(a)
    b = int(b)
    dep[a-1] = dep[a-1]+1
    dep[b-1] = dep[b-1]+1

good = 1
for i in range(n) :
    if dep[i] == 2 :
        good = 0
if good == 1 :
    print('YES')
else :
    print('NO')
