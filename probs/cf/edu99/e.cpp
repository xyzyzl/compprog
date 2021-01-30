#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define f first
#define s second
int main()
{
	int t; cin >> t;
	while(t--)
	{
		vector<int> it = {-1, 1};
		vector<pii> v(4);
		for(int i = 0; i < 4; i++) cin >> v[i].f >> v[i].s;
		for(int i1 = 0; i1 < 4; i1++)
		{
			for(int i2 = 0; i2 < 4; i2++)
			{
				for(int j1 = 0; j1 < 4; j1++)
				{
					ll x1 = v[i1].f;
					ll x2 = v[i2].f;
					ll y1 = v[j1].s;
					if(x1 > x2) continue;
				}
			}
		}
	}
}
