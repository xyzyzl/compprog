#include <bits/stdc++.h>

using namespace std;

int n, q, a[200005], s[200005], ret[200005];
pair<int, int> l[200005];
struct que
{
	int t, i, x;
} qq[200005];
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> q;
	fill(l, l+n, pair<int, int>(-1, -1));
	for(int i = 0; i < q; i++)
	{
		int t;
		cin >> t;
		if(t==1)
		{
			int p, x;
			cin >> p >> x;
			--p;
			qq[i].t = t;
			qq[i].i = p;
			qq[i].x = x;
			l[qq[i].i] = make_pair(qq[i].x, i);
		} else
		{
			int x;
			cin >> x;
			qq[i].t = t;
			qq[i].i = -1;
			qq[i].x = x;
		}
	}
	for(int i = q-1; i >= 0; i--)
	{
		if(qq[i].t == 2)
		{
			s[i] = max(s[i+1], qq[i].x);
		} else
		{
			s[i] = s[i+1];
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(l[i].second == -1)
		{
			ret[i] = max(a[i], s[0]);
		} else
		{
			ret[i] = max(l[i].first, s[l[i].second]);
		}	
	}
	for(int i = 0; i < n; i++) cout << ret[i] << " ";
	cout << endl;
}