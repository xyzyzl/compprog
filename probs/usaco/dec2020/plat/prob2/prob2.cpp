#include <bits/stdc++.h>

#define ll long long

using namespace std;

int N, K, Q;
bool adj[66][66];
int que[66][4];

const int MOD = 1000000007;

ll dp[126][126][66];
int main()
{
	cin >> N >> K >> Q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			char c; cin >> c;
			adj[i][j] = (c == '1');
		}
	for (int i = 0; i < Q; i++)
	{
		// starting button, start pos,  end button,   end pos
		cin >> que[i][0] >> que[i][1] >> que[i][2] >> que[i][3];
		--que[i][1]; --que[i][3]; // buttons 1-based, queries 0-based?
	}
	// maximum button
	for (int k = 1; k <= K; k++)
	{
		// we can ignore button k
		if (k > 1)
			for (int i = 0; i < N + Q; i++)
				for (int j = 0; j < N + Q; j++)
					dp[i][j][k] = dp[i][j][k - 1];
		// or we can take button k
		for (int x = 0; x < N; x++) // intermediate node
		{
			// number of ways to get TO x from i, FROM x to i
			vector<ll> L(N + Q), R(N + Q);
			L[x] = 1;
			for (int i = 0; i < Q; i++)
				if (k == que[i][0] && x == que[i][1])
					L[N + i] = 1;
			R[x] = 1;
			for (int i = 0; i < Q; i++)
				if (k == que[i][2] && x == que[i][3])
					R[N + i] = 1;
			if (k > 1)
			{
				for (int i = 0; i < N + Q; i++)
					for (int j = 0; j < N; j++)
					{
						// cannot use K because then (x, k) would be unavailable
						// cannot use anything greater than K because that would break the invariant
						if(adj[j][x]) L[i] = (L[i] + dp[i][j][k - 1]) % MOD;
					}
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N + Q; j++)
					{
						if(adj[x][i]) R[j] = (R[j] + dp[i][j][k - 1]) % MOD;
					}
			}
			for (int i = 0; i < N + Q; i++)
				for (int j = 0; j < N + Q; j++)
				{
					dp[i][j][k] = (dp[i][j][k] + (L[i] * R[j]) % MOD) % MOD;
				}
		}
	}
	for (int i = 0; i < Q; i++)
	{
		cout << dp[N + i][N + i][K] << endl;
	}
}