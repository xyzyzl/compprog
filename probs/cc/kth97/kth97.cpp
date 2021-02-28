#include <bits/stdc++.h>

#define MAXN 100005
#define ll long long

const int MOD = 1000000007;
int ad(int a, int b, int mod = MOD) { return (a + b) % mod; }
int mul(int a, int b, int mod = MOD) { return (ll)a * b % mod; }
int po(int b, int p, int mod = MOD) { return !p ? 1 : mul(po(mul(b, b, mod), p / 2, mod), p & 1 ? b : 1, mod); }
int inv(int b, int mod = MOD) { return po(b, mod - 2, mod); }

using namespace std;

int n, fact[MAXN], A[MAXN], p2[MAXN];
void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	vector<int> sum(n);
	for (int i = 0; i < n; i++)
	{
		for(int k = 0; k <= i; k++) sum[k] = ad(sum[k], mul(A[i], mul(p2[n-i-1], mul(fact[i], inv(mul(fact[k], fact[i-k]))))));
	}
	for(int i = 0; i < n; i++) cout << sum[i] << " ";
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	fact[0] = 1;
	for (int i = 1; i < 100005; i++)
	{
		fact[i] = mul(fact[i-1], i);
	}
	p2[0] = 1;
	for (int i = 1; i < 100005; i++)
	{
		p2[i] = mul(p2[i-1],2);
	}
	while (t--)
	{
		solve();
	}
}