#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

const int MAXN = 5005;

int N, K, a[MAXN], b[MAXN], dp[MAXN][MAXN];

vector<int> S;

void f(int i, int j)
{
	if(!i) return;
	if(dp[i-1][j]) f(i-1, j);
	else 
	{
		S.push_back(i);
		f(i-1, (j-b[i]+K)%K);
	}
}

int main()
{
	int V;
	cin >> N >> K >> V;
	int W = V%K;
	for(int i = 1; i <= N; i++)
	{
		cin >> a[i];
		b[i] = a[i]%K;
	}
	dp[0][0] = 1;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 0; j < K; j++)
		{
			dp[i][j] |= dp[i-1][j];
			dp[i][(j+a[i])%K] |= dp[i-1][j];
		}
	}

	vector<pair<int, pair<int, int> > > ans;
	if(dp[N][W])
	{
		int sm = 0;
		for(int i = 1; i <= N; i++) sm += a[i];
		if((sm-W)/K >= V/K)
		{
			f(N, W);
			cout << "YES" << endl;
			if(S.empty())
			{
				S.push_back(1);
				ans.push_back({(a[1]+K-1)/K, {1, 2}});
				a[2] += a[1];
				a[1] = 0;
			} else 
			{
				bool first = 1;
				for(int x : S)
				{
					if(first)
					{
						first = 0;
						continue;
					}
					ans.push_back(mp((a[x]+K-1)/K, mp(x, S[0])));
					a[S[0]] += a[x];
					a[x] = 0;
				}
			}
			int f = S[0];
			int s = 1;
			if(s==f)s++;
			for(int i = 1; i <= N; i++)
			{
				if(i != s && i != f && a[i])
				{
					ans.push_back(mp((a[i]+K-1)/K, mp(i, s)));
					a[s] += a[i];
					a[i] = 0;
				}
			}
			ans.push_back({a[s]/K, {s,f}});
			a[f] += a[s]/K*K;
			a[s] = 0;
			ans.push_back({(a[f]-V)/K, {f,s}});
			a[s] += (a[f]-V)/K*K;
			a[f] -= (a[f]-V)/K*K;
			for(auto x : ans)
			{
				if(x.first)
				{
					cout << x.first << " " << x.second.first << " " << x.second.second << endl;
				}
			}
			for(int i = 1; i <= N; i++)
			{
				cerr << a[i] << endl;
			}
		}
		else  // too small
		{
			cout << "NO" << endl;
		}
	} else cout << "NO" << endl; // cant reach
}