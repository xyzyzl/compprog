#include <bits/stdc++.h>

using ll=long long;
using namespace std;
#define int ll

const int MAXN = 1005;
const int MAXK = 55;
const int INF = 1e15+7;

int N, K, b[MAXN], S[MAXK][MAXK], wt[MAXN], vis[MAXN];
int mat[MAXN][MAXN];

void dijk(int src)
{
	fill(wt, wt+N, INF);
	wt[src] = 0;
	for(int c = 0; c < N-1; c++)
	{
		int mn = INF, ind = 0;
		for(int i = 0; i < N; i++)
		{
			if(!vis[i] && wt[i] <= mn) mn = wt[i], ind = i;
		}
		vis[ind] = 1;
		for(int i = 0; i < N; i++) if(!vis[i] && wt[ind] + mat[ind][i] < wt[i]) wt[i] = wt[ind]+mat[ind][i];
	}
}

signed main()
{
	cin >> N >> K;
	if(N > 1000)
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < N; i++)
	{
		cin >> b[i];
		--b[i];
	}
	for(int i = 0; i < K; i++) for(int j = 0; j < K; j++)
	{
		char c; cin >> c;
		S[i][j] = (c=='1');
	}
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		mat[i][j] = (S[b[i]][b[j]] ? abs(i-j) : INF);
	}
	dijk(0);
	if(wt[N-1] == INF) cout << -1 << endl;
	else cout << wt[N-1] << endl;
}
