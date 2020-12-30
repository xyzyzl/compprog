#include <bits/stdc++.h>

using namespace std;

#define MAXA 26
#define MAXN 200005

int n, trie[MAXN][MAXA], freq[MAXN], ans;
void dfs(int v, int tn)
{
	bool not_lf=0;
	for(int i = 0; i < MAXA; i++)
	{
		if(trie[v][i] == 0) continue;
		not_lf = 1;
		dfs(trie[v][i], tn+freq[v]);
	}
	if(!not_lf) // is a leaf and thus the end of some word
	{
		tn++;
		ans = max(ans, tn);
	}
}

int main()
{
	cin >> n;
	int nd = 0;
	for(int i = 0; i < n; i++)
	{
		string S;
		cin >> S;
		int x = 0;
		for(int j = 0; j < S.length(); j++)
		{
			int ind = S[j] - 'a';
			if(trie[x][ind] == 0) trie[x][ind] = nd++;
			x = trie[x][ind];
		}
		freq[x]++;
	}
	dfs(0, 0);
	cout << ans << endl;
}