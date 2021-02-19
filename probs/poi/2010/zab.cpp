/*input
5 2 4
1 2 4 7 10
*/
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
const int MAXN=1000005;
const int MAXK=22;

int n, k, nx[MAXN][MAXK], cyc[MAXN], col[MAXN];
ll m;
ll p[MAXN];
int main()
{
	// fast input
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k >> m;
	for(int i = 0; i < n; i++) cin >> p[i];
	int r = k;
	for(int i = 0; i < n; i++)
	{
		while(r < n-1 && p[r+1]-p[i] < p[i]-p[r-k])
		{
			r++;
		}
		if(p[i] - p[r-k] >= p[r] - p[i])
			nx[i][0] = r-k;
		else
			nx[i][0] = r;
	}
	for(int j = 1; j < MAXK; j++) for(int i = 0; i < n; i++) nx[i][j] = nx[nx[i][j-1]][j-1];
	fill(col, col+n, -1);
	for(int i = 0; i < n; i++)
	{
		int id = i;
		for(id;col[id] == -1;id=nx[id][0]) col[id] = i;
		if(col[id] != i) continue; // not a cycle, or in an already visited cycle
		int sz = 0;
		for(id;col[id] == i;id=nx[id][0])
		{
			sz++;
			col[id]+=n;
		}
		for(id;col[id] == i+n;id=nx[id][0])
		{
			cyc[id]=sz;
			col[id]-=n;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(m <= n)
		{
			int dest = i;
			for(int i = MAXK-1; i >= 0; i--)
			{
				if((1LL << i) & m) dest = nx[dest][i];
			}
			cout << dest+1 << " ";
		} else
		{
			int dest = i;
			for(int i = MAXK-1; i >= 0; i--)
			{
				if((1LL << i) & n) dest = nx[dest][i];
			}
			// dest is now *definitely* in a cycle
			ll rem = (m-n)%cyc[dest];
			
			for(int i = MAXK-1; i >= 0; i--)
			{
				if((1LL << i) & rem) dest = nx[dest][i];
			}
			cout << dest+1 << " ";
		}
	}
	cout << endl;
}