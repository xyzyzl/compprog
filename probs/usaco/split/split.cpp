#include <bits/stdc++.h>

using namespace std;

int n;
typedef pair<long long, long long> pii;
#define f first
#define s second
#define ll long long
pii loc[50005];
ll pmx[50005], pmn[50005], smx[50005], smn[50005];
int main()
{
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> loc[i].f >> loc[i].s;
	}
	ll ans = 0;
	for(int i = 0; i < 2; i++)
	{
		sort(loc, loc+n);
		pmx[0] = pmn[0] = loc[0].s;
		for(int i = 1; i < n; i++)
		{
			pmx[i] = max(pmx[i-1], loc[i].s);
			pmn[i] = min(pmn[i-1], loc[i].s);
		}
		smx[n-1] = smn[n-1] = loc[n-1].s;
		for(int i = n-2; i >= 0; i--)
		{
			smx[i] = max(smx[i+1], loc[i].s);
			smn[i] = min(smn[i+1], loc[i].s);
		}
		ll big = (smx[0] - smn[0]) * (loc[n-1].f - loc[0].f);
		// cerr << big << endl;
		ll sml = LLONG_MAX;
		for(int k = 0; k < n-1; k++)
		{
			ll cur = (pmx[k]-pmn[k])*(loc[k].f-loc[0].f) +
				(smx[k+1]-smn[k+1])*(loc[n-1].f-loc[k+1].f);
			sml = min(sml, cur);
		}
		ans = max(ans, big-sml);
		for(int i = 0; i < n; i++) swap(loc[i].f, loc[i].s);
	}
	cout << ans << endl;
}
