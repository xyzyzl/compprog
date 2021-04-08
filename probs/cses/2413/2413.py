t = int(input())
mod = 1000000007

n = int(1e6+5)
dp = [[0 for i in range(2)] for i in range(n+1)]
def solve() :
	dp[1][0] = dp[1][1] = 1
	for i in range(2, n+1) :
		dp[i][0] = ((dp[i-1][0]*4)%mod + dp[i-1][1]) % mod
		dp[i][1] = (dp[i-1][0] + dp[i-1][1]*2) % mod

solve()
while t > 0 :
	m = int(input())
	print((dp[m][0]+dp[m][1])%mod)
	t-=1