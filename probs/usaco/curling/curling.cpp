#include <bits/stdc++.h>

#define MAXN 50005

using namespace std;

#define int long long
#define double long double
typedef pair<int, int> pii;
#define f first
#define s second
int n;
pii a[2][MAXN];
vector<pii> l[2], u[2];

// compares if p, q, r are ccw
bool ccw(pii z, pii p, pii q)
{
	return ((p.f - z.f) * (q.s - z.s) - (p.s - z.s) * (q.f - z.f)) < 0;
}

signed main()
{
	freopen("curling.in", "r", stdin);
	freopen("curling.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[0][i].f >> a[0][i].s;
	}
	sort(a[0], a[0]+n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[1][i].f >> a[1][i].s;
	}
	sort(a[1], a[1]+n);
	for(int it = 0; it < 2; it++)
	{
		for(int i = 0; i < n; i++)
		{
			while(l[it].size() >= 2 && ccw(l[it][l[it].size() - 2], l[it][l[it].size() - 1], a[it][i]))
				l[it].pop_back();
			l[it].push_back(a[it][i]);
		}

		for(int i = n-1; i >= 0; i--)
		{
			while(u[it].size() >= 2 && ccw(u[it][u[it].size() - 2], u[it][u[it].size() - 1], a[it][i]))
				u[it].pop_back();
			u[it].push_back(a[it][i]);
		}
		
		sort(l[it].begin(), l[it].end());
		sort(u[it].begin(), u[it].end());
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			pii ins = a[!it][i];
			int li = (upper_bound(l[it].begin(), l[it].end(), ins)) - l[it].begin();
			--li;
			int ui = (upper_bound(u[it].begin(), u[it].end(), ins)) - u[it].begin(); 
			--ui;
			// cout << li << " " << ui << endl;
			if(li < 0 || ui < 0 || li >= l[it].size()-1 || ui >= u[it].size()-1) continue;
			double m1, m2;
			if(l[it][li].f == l[it][li+1].f) m1 = 1e9; // this also shouldn't happen
			else m1 = ((double)l[it][li+1].s - l[it][li].s)/((double)l[it][li+1].f - l[it][li].f);
			if(u[it][ui].f == u[it][ui+1].f) m2 = 1e9; // this also shouldn't happen
			else m2 = ((double)u[it][ui+1].s - u[it][ui].s)/((double)u[it][ui+1].f - u[it][ui].f);
			// cout << m1 << " " << m2 << endl;
			double ld = ins.f - l[it][li].f;
			double ud = ins.f - u[it][ui].f;
			if(m1 > 1e6 || m2 > 1e6)
			{
				double mxy = (*(lower_bound(l[it].begin(), l[it].end(), ins))).s;
				double mny = (*(prev(upper_bound(l[it].begin(), l[it].end(), ins)))).s;
				if(mny <= ins.s && ins.s <= mxy) ans++;
				continue;
			}
			double mny = ld * m1 + l[it][li].s;
			double mxy = ud * m2 + u[it][ui].s;
			if(mny <= (double)ins.s && (double)ins.s <= mxy)
				ans++;
		}
		if(it == 0) cout << ans << ' ';
		else        cout << ans << endl;
	}
}
