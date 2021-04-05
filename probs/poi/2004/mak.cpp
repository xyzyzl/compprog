#include <bits/stdc++.h>

using namespace std;
using xd = long long;

#define OwO(i, j, k) for(int i = j; i <= k; i++)
#define OwU(i, j, k) for(int i = j; i <  k; i++)
#define UwU(i, j, k) for(int i = k; i >= j; i--)
#define QwQ(i, j, k, s) for(int i = j; i <= k; i+=s)
#define iwi(i, j, k, d) for(int i = k; i >= j; i-=s)
#define uwu(a) sort(a.begin(), a.end())
#define owo(a,b) sort(a, a+b)

int n;
bool vs[10005][71];
double dp[10005][71];
// we use the recurrence dp[i][p] = max(dp[i][p-1], max(dp[i-P[p]^k][j-1] * P[j]^k))
// except we take the logs to prevent overflow
int dp2[10005][71]; // log of dp as described
vector<int> P;

double rec(int i, int p = 0)
{
	if(p == P.size() || P[p] > i) return 0;
	if(vs[i][p]) return dp[i][p];

	double ans = rec(i, p+1); // does not matter in which order we iterate through primes
	dp2[i][p] = 0;
	for(int po = P[p], ex = 1; po <= i; po*=P[p], ex++)
	{
		// we add P[p]^ex.
		double a2 = ex * log(P[p]) + rec(i-po, p+1);
		if(ans < a2)
		{
			ans = a2;
			dp2[i][p] = po; // try to fit as much as possible in a capacity of i such that ans is maximized.
		}
	}
	vs[i][p] = 1;
	return dp[i][p] = ans;
}

void solve()
{
	memset(vs, 0, sizeof vs);
	cin >> n;
	rec(n);
	vector<int> L;
	OwU(p, 0, P.size())
	{
		if(dp2[n][p]) L.push_back(dp2[n][p]);
		n -= dp2[n][p];
	}
	while(n--) L.push_back(1);
	uwu(L);
	for(int i = 0, j = 1; i < L.size(); j += L[i++])
	{
		OwU(k, 1, L[i]) cout << j+k << " ";
		cout << j << " ";
	}
	cout << endl;
}

signed main()
{
	vector<int> V(351);
	OwO(i, 2, 350)
	{
		if(!V[i])
		{
			QwQ(j, i, 350, i) V[j] = 1;
			P.push_back(i);
		}
	}
	int d; cin >> d;
	while(d--) solve();
}
