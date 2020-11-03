#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define ll long long
int N;
ll lens[MAXN], nl, par[MAXN], l[MAXN], as[MAXN];
bool leaf[MAXN];
vector<pair<int,int> > adj[MAXN];

void dfs(int v, int p)
{
	for(pair<int,int> x : adj[v])
	{
		dfs(x.first,v);
		// add all files
		l[v] += l[x.first];
		// add this directory to the number of files in its subtree
		as[v] += as[x.first] + l[x.first]*(x.second);
	}
}

// actual answers for each
ll at[MAXN];
// p is everything above v
void dfs2(int v, ll abv)
{
	// number above + number below
	at[v] = abv+as[v];
	ll cur = 0; // this current subtree
	for(pair<int,int> x : adj[v])
	{
		// add all files below this current index (and remove them when processing the next indices)
		cur += as[x.first]+l[x.first]*x.second;
	}
	for(pair<int,int> x : adj[v])
	{
		// all leaves not in the next subtree get a ../ to them
		// everything not in this index. exclude anything that would be double counted
		// -(as[x.first]+l[x.first]*x.second) because of overcount
		// p2 is everything that's in v but not in x.first (but including x.first preliminarily)
		dfs2(x.first, abv+cur-(as[x.first]+l[x.first]*x.second)+3*(nl-l[x.first]));
	}
}

int main()
{
	freopen("dirtraverse.in", "r", stdin);
	freopen("dirtraverse.out", "w", stdout);
	cin >> N;
	par[0] = -1;
	for(int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		lens[i] = s.length();
		int M; cin >> M;
		if(!M)
		{
			nl++;
			l[i]++;
			leaf[i]=1;
		}
		for(int j = 0; j < M; j++)
		{
			int k; cin >> k;
			--k;
			par[k] = i;
		}
	}
	for(int i = 0; i < N; i++)
	{
		if(par[i] >= 0)
		{
			adj[par[i]].push_back(make_pair(i, lens[i]+!leaf[i]));
		}
	}
	dfs(0, -1);
	dfs2(0, 0);

	ll ans = LLONG_MAX;
	for(int i = 0; i < N; i++)
	{
		ans = min(ans, at[i]);
	}
	cout << ans << endl;
}
