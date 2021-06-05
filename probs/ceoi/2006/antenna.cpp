#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<double, double>;
#define f first
#define s second

const int MAXN = 505;
const int INF = 1e9+7;
const double PI = 3.14159265;

int n, k;
pii a[MAXN];

ll sqd(int i, int j)
{
	ll dx = a[j].f-a[i].f;
	ll dy = a[j].s-a[i].s;
	return dx*dx+dy*dy;
}

pii work(ll raw)
{
	long double R = raw/(10000.0);
	for(int i = 0; i < n; i++)
	{
		// 0 is entering, 1 is leaving
		vector<pii> ev;
		// add all valid points as entering and leaving
		for(int j = 0; j < n; j++) if(j != i)
		{
			if(sqrt(sqd(i, j)) > 2.0*R) continue;
			// next we center around i and add j to a sweepline
			double ang = atan2(a[j].s-a[i].s, a[j].f-a[i].f);
			double var = acos(sqrt(sqd(i, j)) / (2*R));
			ev.push_back({ang-var, 0});
			ev.push_back({ang+var, 1});
			ev.push_back({ang-var+2.0*PI, 0});
			ev.push_back({ang+var+2.0*PI, 1});
		}
		sort(ev.begin(), ev.end());
		int count = 1; // current count = just the 1 point that we fixed
		for(auto e : ev)
		{
			if(e.s) --count;
			else ++count;
			if(count >= k)
			{
				return {a[i].f + R*cos(e.f), a[i].s + R*sin(e.f)};
			}
		}
	}
	return {INF, INF};
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].f >> a[i].s;
	}
	// we then perform a binary search on radius
	ll lo = -1;
	ll hi = 100000000;
	pii last = {0, 0};
	while(lo < hi - 1)
	{
		ll mid = (lo+hi)/2;
		last = work(mid);
		if(last.f < INF) hi = mid;
		else lo = mid;
	}
	last = work(hi);
	cout << setprecision(4) << fixed << (double)hi/10000.0 << endl;
	cout << setprecision(4) << fixed << last.f << " " << last.s << endl;
}
