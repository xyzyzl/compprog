MAXN = int(1e6+5)
n = int(input())
arr = list(map(int, input().split()))
p = [0 for i in range(MAXN)]

for i in range(n) :
    p[arr[i]] += 1

for i in range(MAXN, 1, -1) :
    div = 0
    for j in range(i, MAXN, i) : 
        div += p[j]
    if div >= 2 :
        print(i)
        break
