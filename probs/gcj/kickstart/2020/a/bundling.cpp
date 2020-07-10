#include <bits/stdc++.h>

using namespace std;

#define MAXA 26
#define MAXD 2000005

typedef pair<int, int> pii;
#define f first
#define s second

int n, k;
int trie[MAXD][MAXA];
int freq[MAXD];

long long ret;
void dfs(int v, int dep)
{
	for(int i = 0; i < MAXA; i++)
	{
		if(trie[v][i] == 0) continue; // not defined
		dfs(trie[v][i], dep+1);
		freq[v] += freq[trie[v][i]]; // everything in this part of the string
		// also a part of previous nodes
	}
	long long x = freq[v];
	freq[v] %= k;
	ret += (long long)dep * (x / k);
}

long long solve()
{
	ret = 0;
	memset(trie, 0, sizeof trie);
	memset(freq, 0, sizeof freq);
	cin >> n >> k;
	int nd = 1;
	for(int i = 0; i < n; i++)
	{
		string each;
		cin >> each;
		int x = 0;
		for(int j = 0; j < each.length(); j++)
		{
			int ind = each[j] - 'A';
			if(trie[x][ind] == 0) trie[x][ind] = nd++;
			x = trie[x][ind];
		}
		freq[x]++; // add one downstream and it propagates up the tree
	}
	dfs(0, 0);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		// more convenient to use printf here
		printf("Case #%d: %d\n", i, solve());
	}
}
