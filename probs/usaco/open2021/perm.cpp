#include <bits/stdc++.h>

using namespace std;

const int MAXN = 45;
const int MOD = 1e9+7;

int N, fact[MAXN];
using pii = pair<int, int>;
using ll = long long;
pair<int, int> P[MAXN];
#define f first
#define s second

int cross(pii a, pii b, pii c)
{
	b.f -= a.f;
	b.s -= a.s;
	c.f -= a.f;
	c.s -= a.s;
	return b.f*c.s - b.s*c.f;
}

int area(array<int, 3> a)
{
	return abs(cross(P[a[0]], P[a[1]], P[a[2]]));
}

bool in(array<int, 3> a, int b)
{
	int sum = 0;
	for(int i = 0; i < 3; i++)
	{
		swap(a[i], b);
		sum += area(a);
		swap(a[i], b);
	}
	sum -= area(a);
	return sum == 0;
}

bool on(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{
	if (q.f <= max(p.f, r.f) && q.f >= min(p.f, r.f) &&
		q.s <= max(p.s, r.s) && q.s >= min(p.s, r.s))
		return true;

	return false;
}

int ort(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{
	int val = (q.s - p.s) * (r.f - q.f) - (q.f - p.f) * (r.s - q.s);
	if (val == 0)
		return 0;
	return (val > 0) ? 1 : 2;
}

bool inter(pair<pair<int, int>, pair<int, int> > l1, pair<pair<int, int>, pair<int, int> > l2)
{
	if(l1.f == l2.f || l1.f == l2.s || l1.s == l2.f || l1.s == l2.s) return 0; // endpoint
	int o1 = ort(l1.f, l1.s, l2.f);
	int o2 = ort(l1.f, l1.s, l2.s);
	int o3 = ort(l2.f, l2.s, l1.f);
	int o4 = ort(l2.f, l2.s, l1.s);
	if (o1 != o2 && o3 != o4)
		return 1;
	if(!o1 && on(l1.f, l2.f, l1.s)) return 1;
	if(!o2 && on(l1.f, l2.s, l1.s)) return 1;
	if(!o3 && on(l2.f, l1.f, l2.s)) return 1;
	if(!o4 && on(l2.f, l1.s, l2.s)) return 1;
	return 0;
}

vector<array<int, 3> > t;
vector<ll> dp[50][50][50];

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++) cin >> P[i].f >> P[i].s;
	for(int i = 0; i < N; i++) for(int j = i+1; j < N; j++) for(int k = j+1; k < N; k++) t.push_back({i,j,k});
	sort(t.begin(), t.end(), [&](array<int, 3> P, array<int, 3> Q)
	{
		return area(P) < area(Q);
	});

	// cerr << in({0, 1, 2}, 3) << endl;

	ll ans = 0;
	for(auto& x : t)
	{
		int tot_in = 0;
		vector<array<int, 3> > nxt;
		for(int i = 0; i < N; i++)
		{
			if(in(x, i)) ++tot_in;
			else
			{
				for(int j = 0; j < 3; j++) 
				{
					array<int, 3> nx = x;
					nx[j] = i;
					sort(nx.begin(), nx.end());
					if(in(nx, x[j]))
					{
						nxt.push_back(nx);
						cerr << nx[0] << " " << nx[1] << " " << nx[2] << endl;
					}
				}
			}
		}
		// cerr << tot_in << endl;
		tot_in -= 3;
		dp[x[0]][x[1]][x[2]].resize(1+tot_in);
		dp[x[0]][x[1]][x[2]][0] = 1;
		for(int i = 0; i <= tot_in; i++)
		{
			if(i < tot_in)
			{
				dp[x[0]][x[1]][x[2]][i+1] += (ll)(tot_in-i)*dp[x[0]][x[1]][x[2]][i];
				dp[x[0]][x[1]][x[2]][i+1] %= MOD;
			}
			for(auto y : nxt)
			{
				dp[x[0]][x[1]][x[2]][i+1] += dp[x[0]][x[1]][x[2]][i];
				dp[x[0]][x[1]][x[2]][i+1] %= MOD;
			}
		}
		if(tot_in == N-3)
		{
			ans += dp[x[0]][x[1]][x[2]][tot_in];
			ans %= MOD;
		}
	}
	cout << (6ll*ans)%MOD << endl;
}