#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int n, k;
	vector<int> adj[20];
	int dp[100005];

	int rec(int msk)
	{
		if(dp[msk] != -1) return dp[msk];
		vector<int> indeg(n);
		for(int i = 0; i < n; i++)
		{
			if((1 << i) & msk) for(int x : adj[i]) indeg[x]++;
		}
		int front = 0;
		for(int i = 0; i < n; i++) if(((1 << i) & msk) && indeg[i] == 0) front |= (1 << i);
		int n_f = __builtin_popcount(front), ans = INT_MAX;
		if(n_f <= k)
		{
			// can take all fronts in one sitting
			ans = 1 + rec(msk ^ front);
		} else
		{
			// need to pick off in groups of k
			for(int nxt = front; nxt; nxt = (nxt-1)&front)
			{
				if(__builtin_popcount(nxt) != k) continue;
				ans = min(ans, 1 + rec(msk ^ nxt));
			}
		}
		dp[msk] = ans;
		return dp[msk];	
	}
public:
	int minNumberOfSemesters(int n, vector<vector<int>> &edg, int k)
	{
        this->n=n;
        this->k=k;
		memset(dp, -1, sizeof dp);
		dp[0] = 0;
		for(vector<int> x : edg)
		{
			x[0]--; x[1]--;
			adj[x[0]].push_back(x[1]);
		}
		return rec((1 << n)-1);
	}
};