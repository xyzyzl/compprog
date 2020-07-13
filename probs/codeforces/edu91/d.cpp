#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	long long x,k,y;
	cin >> x >> k >> y;
	vector<int> a(n+5), id(m+5), ma(n+5);
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ma[a[i]] = i;
	}
	for(int i = 1; i <= m; i++)
	{
		int val; cin >> val;
		if(ma[val] == 0)
		{
			cout << -1 << endl;
			return 0;
		}
		id[i] = ma[val];
	}
	id[ 0 ] = 0;
	id[++m] = n+1;
	for(int i = 1; i <= m; i++)
	{
		if(id[i] < id[i-1])
		{
			cout << -1 << endl;
			return 0;
		}
	}
	bool berserk = y*k < x;
	long long ans = 0;
	for(int i = 1; i <= m; i++)
	{
		int most_stronk = 0;
		for(int j = id[i-1]+1; j < id[i]; j++)
		{
			most_stronk = max(most_stronk, a[j]);
		}
		long long diff = (id[i] - id[i-1] - 1);
		if(id[i] - id[i-1] - 1 < k)
		{
			// need to eliminate all w/ only berserk
			if(most_stronk > a[id[i]] && most_stronk > a[id[i-1]])
			{
				cout << -1 << endl;
				return 0;
			}
			// otherwise it works
			ans += y*(diff);
		} else 
		{
			if(!berserk)
			{
				// fireball is profitable
				ans += y*(diff % k) + x*(diff/k);
			} else 
			{
				if(most_stronk > a[id[i]] && most_stronk > a[id[i-1]])
				{
					ans += y*(diff % k) + y*(diff - diff%k - k) + x;
				} else 
				{
					ans += y*(diff);
				}
			}
		}
	}
	cout << ans << endl;
}
