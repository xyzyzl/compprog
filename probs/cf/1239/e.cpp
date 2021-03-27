// this sack of shit took two fucking hours. it's definitely NOT a 3100 in terms of difficulty
// there's some really nice observation over what is the best method to pick numbers
// first use knapsack to find the possible values

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30;
const int MAXA = 1300005; // max. total weight

int N, A[MAXN][2], L[2*MAXN];
int dp[MAXN][MAXA], p[MAXN][MAXA];
int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> A[i][0];
		++A[i][0]; // these should be 1-based indices
		L[i] = A[i][0];
	}
	for(int i = 0; i < N; i++)
	{
		cin >> A[i][1];
		++A[i][1]; // otherwise it'll confuse 0's with everything else
		L[N+i] = A[i][1];
	}
	sort(L, L+2*N);
	dp[0][0] = 1;
	// knapsack to find the largest values
	for(int i = 2; i < 2*N; i++)
	{
		for(int j = N-2; j >= 0; j--)
		{
			for(int k = MAXA; k >= 0; k--)
			{
				if(k + L[i] < MAXA && dp[j][k] && !dp[j+1][k+L[i]])
				{
					dp[j+1][k+L[i]]=1;
					p [j+1][k+L[i]]=L[i];
				}
			}
		}
	}
	int tot = 0;
	for(int i = 2; i < 2*N; i++)
	{
		tot += L[i];
	}
	vector<int> V;
	// then pick the largest possible sum, as turtle would do
	for(int j = tot/2; j >= 0; j--)
	{
		if(dp[N-1][j])
		{
			int i = N-1;
			int id = j;
			while(id != 0)
			{
				// go along the path outlined in the knapsack dp
				V.push_back(p[i][id]);
				id -= p[i][id];
				--i;
			}
			break;
		}
	}
	// sort all distances
	sort(V.begin(), V.end());
	A[0][0] = L[0];
	A[N-1][1] = L[1];
	// take this path as the "max path" for the top. should always be increasing
	for(int i = 1; i < N; i++)
	{
		A[i][0] = V[i-1];
	}
	multiset<int> ms;
	for(int i = 2; i < 2*N; i++)
	{
		ms.insert(L[i]);
	}
	// the rest should be in the bottom and decreasing
	for(int i = 0; i < V.size(); i++)
	{
		ms.erase(ms.find(V[i]));
	}
	auto it = ms.begin();
	for(int i = N-2; i >= 0; i--)
	{
		A[i][1] = *it;
		it++;
	}
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cout << A[j][i]-1 << " ";
		}
		cout << endl;
	}
	// took very long because well, i didn't index it right. and also i made a few typos here and there
}
