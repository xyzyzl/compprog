#include <bits/stdc++.h>

using namespace std;

int n;
long long m, f[100005], s[100005];
int main()
{
	freopen("hayfeast.in", "r", stdin);
	freopen("hayfeast.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> f[i] >> s[i];
	multiset<long long> k;
	int l = 0, r = 0;
	long long sm = f[0];
	k.insert(s[0]);
	long long mn = LLONG_MAX;
	while(r < n)
	{
		while(sm < m)
		{
			r ++;
			if(r>=n) break;
			sm += f[r];
			k.insert(s[r]);
		}
		if(sm >= m && r < n)
		{
			long long mx = *k.rbegin();
			mn = min(mn, mx);
		}
		k.erase(k.find(s[l]));
		sm -= f[l];
		l++;
	}
	cout << mn << endl;
}
