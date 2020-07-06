#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005
#define endl '\n'

typedef pair<int, int> pii;
#define f first
#define s second

int n, pos[MAXN];
pii a[MAXN], sa[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		a[i].s = i;
		cin >> a[i].f;
		sa[i].f = a[i].f;
		sa[i].s = a[i].s;
	}
	sort(sa, sa+n);
	for(int i = 0; i < n; i++)
	{
		pos[i] = sa[i].s;
		a[sa[i].s].f = i;
	}
	/*
	for(int i = 0; i < n; i++) cout << pos[i] << " ";
	cout << endl;
	*/
	vector<pii> ret;
	for(int y = n; y >= 1; y--)
	{
		int q = a[y-1].f;
		for(int x = q+1; x < y; x++)
		{
			ret.push_back({pos[x]+1, y});
			pos[a[y-1].f] = pos[x];
			swap(a[pos[x]], a[y-1]);
			pos[x] = y-1;
		}
	}
	cout << ret.size() << endl;
	for(pii p : ret)
	{
		cout << p.f << " " << p.s << endl;
	}
}
