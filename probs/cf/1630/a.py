def solve():
    n, k = map(int, input().split())
    if k == 0: 
        for i in range(n//2):
            print(i, n-i-1)
        return 
    elif k < n-1:
        for i in range(1, n//2):
            if (i != k and i != n-k-1):
                print(i, n-i-1)
        print(0, n-k-1)
        print(k, n-1)
    else: # k = n-1
        if n == 4:
            print(-1)
            return
        for i in range(1, n//2):
            if (i != 1 and i != 3):
                print(i, n-i-1)
        print(n-1,n-2)
        print(1,3)
        print(0,n-4)


t = int(input())
for i in range(t):
    solve()