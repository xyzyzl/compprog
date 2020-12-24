#include <bits/stdc++.h>

using namespace std;

int n, k, dp[105];
bool vs[105][105][105];
bool dp1[105][105][105];
string str;
typedef pair<int, int> pii;
#define f first
#define s second
vector<pii> adj[10005];

// can you start with C and end with interval [l,r]?
bool work(char C, int l, int r)
{
	if(vs[C][l][r]) return dp1[C][l][r];
	vs[C][l][r] = 1;
	if(l == r && C == str[l]) return dp1[C][l][r] = 1;
	for(int i = l; i < r; i++)
	{
		for(pii x : adj[C])
		{
			if(work(x.f, l, i) && work(x.s, i+1, r)) return dp1[C][l][r] = 1;
		}
	}
	return 0;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		char A, B, C;
		cin >> A >> B >> C;
		adj[A].push_back({B, C});
	}
	cin >> k; // the Chinese and English problem statements literally contradict themselves and
	// I don't know what to expect!!
	while(k--)
	{
		cin >> str;
		int m = str.length();
		str = '.'+str;
		memset(dp, 0x7f, sizeof dp);
		memset(dp1, 0, sizeof dp1);
		memset(vs, 0, sizeof vs);
		dp[0] = 0; // length 0 strings
		for(int i = 1; i <= m; i++)
		{
			for(int j = 0; j < i; j++) // can we make this string with some moves?
			{
				if(dp[i] > dp[j]+1) // try to update dp only if less than
				{
					if(work('S', j+1, i))
					{
						dp[i] = dp[j]+1; // and only update if this combination works
					}
				}
			}
		}
		if(dp[m] >= 1e9)
		{
			cout << "NIE" << endl;
		} else
		{
			cout << dp[m] << endl;
		}
		
	}
}