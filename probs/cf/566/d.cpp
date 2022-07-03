#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, q, p[MAXN], nxt[MAXN];
int find(int x)
{
	return p[x] == x ? x : p[x] = find(p[x]);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		p[i] = i;
		nxt[i] = i+1;
	}
	for(int que = 0; que < q; que++)
	{
		int t, x, y; cin >> t >> x >> y;
		int px = find(x);
		int py = find(y);
		if(t == 1) p[px] = py;
		else if(t == 2)
		{
			int to;
			// this evaluates to O(n) over the entire set
			// beecause you will reach all of the n points once
			// instead of going multiple times over each
			for(int i = x+1; i <= y; i = to)
			{
				p[find(i-1)] = find(i);
				to = nxt[i], nxt[i] = nxt[y];
			}
		} else 
		{
			cout << (px == py ? "YES" : "NO") << endl;
		}
	}
}