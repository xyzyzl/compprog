#include <bits/stdc++.h>
using namespace std;

#define MAXN 7507

#define ll long long
typedef pair<int, int> pii;
#define f first
#define s second
#define rev reverse

int n,k;
ll d[MAXN];
bool vis[MAXN];
const ll A=2019201913, B=2019201949, M=2019201997;
ll F(int i, int j)
{
	int x = min(i,j);
	int y = max(i,j);
	return (A*x+B*y)%M;
}
void prim()
{
	for(int i = 1; i <= n; i++)
	{
		d[i] = M;
		vis[i]=0;
	}
	for(int i = 1; i < n; i++)
	{
		ll best = M;
		int ind = 0;
		// find minimum distance not already in mst
		for(int j = 1; j <= n; j++)
		{
			if(!vis[j] && d[j] < best)
			{
				best = d[j];
				ind  = j;
			}
		}
		// add to mst
		vis[ind] = 1;
		// find min edge length for each
		for(int j = 1; j <= n; j++)
		{
			if(F(ind, j) < d[j] && !vis[j])
				d[j] = F(ind, j);
		}
	}
}
int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	cin >> n >> k;
	// find mst, as only edges on the MST will be affected by any changes to groups.
	// we only remove edges from the MST until K-1 are left (to connect the K groups).
	// these K-1 edges will be the MST of the groups.
	prim();
	// cerr << F(1,2) << " " << F(1,3) << " " << F(2,3) << endl;
	sort(d+1,d+n+1);
	cout << d[n-k+1] << endl;
}
