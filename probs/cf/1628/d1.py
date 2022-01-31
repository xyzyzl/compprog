MOD = int(1e9+7)
def mul(i, j):
    return (i*j)%MOD

def po(i, j):
    if j==0:
        return 1
    k = po(mul(i, i), j//2)
    if j%2 == 1:
        k = mul(k, i)
    return k

def inv(i):
    return po(i, MOD-2)

def solve():
    n, m, k = input().split()
    n = int(n)
    m = int(m)
    k = int(k)
    dp = [ [ 0 for i in range(m+1) ] for i in range(n+1)]
    for i in range(m+1): 
        dp[i][0] = 0
        dp[i][i] = i*k
    for i in range(1,n+1):
        for j in range(1,min(m+1,i)):
            dp[i][j] = mul((dp[i-1][j] + dp[i-1][j-1])%MOD,inv(2))
    print(dp[n][m]%MOD)

t = int(input())
for te in range(t):
    solve()

# deez.py