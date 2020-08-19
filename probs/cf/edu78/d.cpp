#include <bits/stdc++.h>
 
#define MAXN 500005
 
using namespace std;
 
int n, l[MAXN], r[MAXN];
vector<pair<int, int> > states;
 
vector<int> adj[MAXN];
bool vis[MAXN];
void vibecheck(int x)
{
	vis[x] = 1;
	for(int y : adj[x])
	{
		if(!vis[y]) vibecheck(y);
	}
}
 
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
	for(int i = 0; i < n; i++)
	{
		states.push_back(make_pair(l[i], i));
		states.push_back(make_pair(r[i], i));
	}
	sort(states.begin(), states.end());
	int n_edges = 0;
	set<pair<int, int> > open;
	for(pair<int, int> x : states)
	{
		if(n_edges >= n) break; // this is obvious fail
		if(!open.count(x))
		{
			for(pair<int, int> y : open)
			{
				// see if y is entirely in x or not
				if(y.first > r[x.second]) break;
				// cout << x.second << " " << y.second << endl;
				adj[y.second].push_back(x.second);
				adj[x.second].push_back(y.second);
				n_edges++;
				if(n_edges >= n) goto here; // failed
			}
			open.insert(make_pair(r[x.second], x.second));
		}
		else open.erase(x); // no multiset needed since 
		// there is guaranteed no duplicates
 
		// check which ones are overlapped.
		
	}
	here:
	if(n_edges != n-1) 
	{
		cout << "NO" << endl;
		return 0;
	}
	vibecheck(0);
	// check if all are connected
	for(int i = 0; i < n; i++)
	{
		if(!vis[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}
