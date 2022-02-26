#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using obj = pair<pair<int, int>, pair<int, int> >;
#define f first
#define s second

void solve()
{
	int n; cin >> n;
	vector<obj> v(n);
	vector<pii> x, y;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i].f.f >> v[i].f.s >> v[i].s.f >> v[i].s.s;
		x.push_back(make_pair(v[i].f.f, -1));
		x.push_back(make_pair(v[i].s.f, 1));
		y.push_back(make_pair(v[i].f.s, -1));
		y.push_back(make_pair(v[i].s.s, 1));
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int a = 0;
	int b = n;
	int a_add = 0;
	int mx = 1e9+7;
	for(int i = 0; i < 2*n; )
	{
		if(i == 2*n-1) break;
		do
		{
			// continue that
			if(x[i].s == -1) b--;
			else a_add++;
		} while(i < 2*n-1 && x[i].f == x[++i].f);
		if(x[i-1].f != x[i].f)
		{
			a += a_add;
			a_add = 0;
			if(b-a <= 0)
			{
				// found optimal coord
				mx = x[i-1].f;
				break;
			}
		}
	}
	a = 0; b = n;
	a_add = 0;

	int my = 1e9+7;
	for(int i = 0; i < 2*n; )
	{
		if(i == 2*n-1) break;
		do
		{
			// continue that
			if(y[i].s == -1) b--;
			else a_add++;
		} while(i < 2*n-1 && y[i].f == y[++i].f);
		if(y[i-1].f != y[i].f)
		{
			a += a_add;
			a_add = 0;
			if(b-a <= 0)
			{
				// found optimal coord
				my = y[i-1].f;
				break;
			}
		}
	}
	cout << mx << " " << my << endl;
}

int main()
{
	int t; cin >> t;
	for(int i = 1; i <= t; i++) 
	{
		cout << "Case #" << i << ": ";
		solve();
	}
}
