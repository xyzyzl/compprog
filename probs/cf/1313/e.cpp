#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1000005;

int N, M;
string A, B, S;

int fa[MAXN], fb[MAXN];

void za()
{
	string c = S+"$"+A;
	vector<int> Z(c.length());
	for(int i = 1, l = 0, r = 0; i < c.length(); i++)
	{
		if(i <= r) Z[i] = min(r-i+1, Z[i-l]);
		while(i+Z[i] < c.length() && c[Z[i]] == c[i+Z[i]]) ++Z[i];
		if(i+Z[i]-1 > r) l=i, r=i+Z[i]-1;
	}
	for(int i = M+1; i < c.length(); i++) fa[i-M-1]=Z[i];
}

void zb()
{
	string Bp = B;
	string Sp = S;
	reverse(Bp.begin(), Bp.end());
	reverse(Sp.begin(), Sp.end());
	string c = Sp+"$"+Bp;
	vector<int> Z(c.length());
	for(int i = 1, l = 0, r = 0; i < c.length(); i++)
	{
		if(i <= r) Z[i] = min(r-i+1, Z[i-l]);
		while(i+Z[i] < c.length() && c[Z[i]] == c[i+Z[i]]) ++Z[i];
		if(i+Z[i]-1 > r) l=i, r=i+Z[i]-1;
	}
	for(int i = M+1; i < c.length(); i++) fb[N-1-(i-M-1)]=Z[i];
}

pair<ll, int> bit[MAXN];

void upd(int ind, int val)
{
	int x = ind;
	while(ind <= M)
	{
		bit[ind].first += x*val;
		bit[ind].second += val;
		ind |= (ind+1);
	}
}

pair<ll, int> sum(int ind)
{
	pair<ll, int> ret = {0ll,0};
	while(ind >= 0)
	{
		ret.first += bit[ind].first;
		ret.second += bit[ind].second;
		ind = (ind&(ind+1))-1;
	}
	return ret;
}

pair<ll, int> sum(int l, int r)
{
	pair<ll, int> s1 = sum(r), s2 = sum(l-1);
	return {s1.first-s2.first, s1.second-s2.second};
}

int main()
{
	cin >> N >> M;
	cin >> A >> B >> S;
	// let fa[i] = LCP of a[i:n], s[1:m-1]
	// let fb[i] = LCSuf of b[1:i], s[2:m]
	// find sum (l_1 = 1 to n, sum(r2 = l_1 to min(l1+n-2, n), max(fa[l1], fb[r2] -m+1, 0))).
	// first need to find fa[i], fb[i], w/ z-algo
	za();
	zb();
	// then to find the sum, we maintain two BITs.
	ll ans = 0;
	for(int l1 = 0, r2 = -1; l1 < N; l1++)
	{
		while(r2 < min(l1+M-2, N-1))
		{
			++r2; upd(fb[r2], 1);
		}
		if(l1 != 0) upd(fb[l1-1], -1);
		int top = min(fa[l1], M-1);
		pair<ll, int> a1 = sum(M-fa[l1], M-1), a2 = sum(M, M);
		ans += (1ll * top * a1.second - 1ll * M * a1.second + a1.first + a1.second)
			+ 1ll*a2.second*top;
	}
	cout << ans << endl;
}
