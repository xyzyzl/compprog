#include <bits/stdc++.h>

using namespace std;

#define pb push_back

#define pii pair<int, int>
#define f first
#define s second
#define mp make_pair

int n, p, dp[100005];
map<int, int> m;

void upd(int y, int k)
{
    auto x = prev(m.upper_bound(y));
    if(x->s <= k) return;
    x++;
    while(x != m.end() && x->s > k)
    {
	m.erase(x++);
    }
    m[y] = k;
}

int main()
{
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
    cin >> n >> p;
    vector<pair<pii, pii> > v;
    for(int i = 0; i < p; i++)
    {
	pii a, b;
	cin >> a.f >> a.s >> b.f >> b.s;
	v.pb(mp(a, mp(i, -1)));
	v.pb(mp(b, mp(i, 1)));

	// sort(v.begin(), v.end());
    }
    sort(v.begin(), v.end());
    m[0] = 0;
    for(auto x : v)
    {
	if(x.s.s == -1) // is a start point
	{
	    dp[x.s.f] = x.f.f+x.f.s + prev(m.upper_bound(x.f.s))->s; // search for the best j to recurse from in lg n
	} else // is an end point
	{
	    upd(x.f.s, dp[x.s.f]-x.f.f-x.f.s); // fill m[y_2[j]] = dp[j] - x_2[j] - y_2[j]
	}
    }
    cout << 2*n + m.rbegin() -> s << endl;
}
