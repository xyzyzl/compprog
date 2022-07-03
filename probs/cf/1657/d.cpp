#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 300005;

int n, m, C;
ll bestu[4*MAXN];
int main()
{
	cin >> n >> C;
	for(int i = 0; i < n; i++)
	{
		int c, d; ll h; cin >> c >> d >> h;
		bestu[c] = max(bestu[c], h*d);
	}
	for(int i = 1; i <= C; i++) for(int j = i; j <= C; j += i)
	{
		bestu[j] = max(bestu[j], bestu[i] * (j/i));
	}
	for(int i = 0; i < C; i++)
	{
		bestu[i+1] = max(bestu[i+1], bestu[i]);
	}
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int d; ll h; cin >> d >> h;
		int mn = upper_bound(bestu, bestu+C+1, h*d) - bestu;
		if(mn > C) cout << -1 << " ";
		else cout << mn << " ";
	}
	cout << endl;
}