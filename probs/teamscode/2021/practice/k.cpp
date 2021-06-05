#include <bits/stdc++.h>

using namespace std;

// sounds like a trie question to me. go and add each of the nodes and find the
// greatest depth of some node
int n;
const int MAXD = 100005;
const int MAXA = 26;
int trie[MAXD][MAXA];
int freq[MAXD];

int ret;
void dfs(int v, int dep)
{
	for(int i = 0; i < MAXA; i++)
	{
		if(trie[v][i] == 0) continue; // not defined
		dfs(trie[v][i], dep+1);
		freq[v] += freq[trie[v][i]]; // everything in this part of the string
		// also a part of previous nodes
	}
	if(v) ret = max(ret, freq[v]);
}
int main()
{
	ret = 0;
	memset(trie, 0, sizeof trie);
	memset(freq, 0, sizeof freq);
	cin >> n;
	int nd = 1;
	for(int i = 0; i < n; i++)
	{
		string s; cin >> s;
		int x = 0;
		for(int j = 0; j < s.length(); j++)
		{
			int ind = s[j] - 'a';
			if(trie[x][ind] == 0) trie[x][ind] = nd++;
			x = trie[x][ind];
		}
		freq[x]++;
	}
	dfs(0, 0); cout << ret << endl;
}
