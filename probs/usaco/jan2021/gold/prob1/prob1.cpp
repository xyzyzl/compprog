#include <bits/stdc++.h>

using namespace std;

int m;
int ct[25][25], fq[25];
set<int> k;
map<int, int> M;

int dp[(1 << 21)];

int main()
{
	string s; cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		s[i] -= 'a';
		k.insert(s[i]);
	}
	for(int x : k) M[x] = m++;
	for(int i = 1; i < s.length(); i++)
	{
		ct[M[s[i]]][M[s[i-1]]]++;
	}
	memset(dp, 0x7f, sizeof dp);
	dp[0] = 1;
	for(int msk = 0; msk < (1 << m); msk++)
	{
		for(int i = 0; i < m; i++) if(!(msk & (1 << i))) 
		{
			int c = 0;
			for(int j = 0; j < m; j++)
			{
				if(!(msk & (1 << j)))
				{
					c += ct[j][i];
				}
			}
			dp[msk | (1 << i)] = min(dp[msk | (1 << i)], c+dp[msk]);
		}
	}
	cout << dp[(1 << m) - 1] << endl;
}
