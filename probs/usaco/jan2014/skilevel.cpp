#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int M, N, p[505*505], sz[505*505], T, a[505][505], ans[505*505];
vector<int> sta;
vector<pair<int, pair<int, int> > > eg;

int find_set(int i)
{
	int j = p[i];
	if(p[j] != j) find_set(j);
	if(ans[i] == -1)
	{
		ans[i] = (ans[j] == -1 ? ans[p[j]] : ans[j]);
	}
	return p[i] = p[j];
}

bool union_set(int i, int j)
{
	int x = find_set(i);
	int y = find_set(j);
	if (x == y)
		return false;
	p[x] = p[y] = x;
	sz[x] += sz[y];
	return true;
}

void init()
{
	for (int i = 0; i < M*N; i++)
		p[i] = i;
	for (int i = 0; i < N*M; i++)
		sz[i] = 1;
}

int co(int i, int j) {
	return N*i+j;
}

int main() {
	freopen("skilevel.in", "r", stdin);
	freopen("skilevel.out", "w", stdout);
	memset(ans, -1, sizeof ans);
	cin >> M >> N >> T;
	for(int i = 0; i < M; i++) for(int j = 0; j < N; j++) {
		cin >> a[i][j];
	}
	for(int i = 0; i < M; i++) for(int j = 0; j < N; j++) {
		int x; cin >> x;
		if(x == 1) sta.push_back(co(i, j));
	}
	init();
	// add the edges
	for(int i = 0; i < M; i++) for(int j = 1; j < N; j++)
	{
		int w = abs(a[i][j] - a[i][j-1]);
		eg.push_back({w, {co(i, j), co(i, j-1)}});
	}
	for(int i = 1; i < M; i++) for(int j = 0; j < N; j++)
	{
		int w = abs(a[i][j] - a[i-1][j]);
		eg.push_back({w, {co(i, j), co(i-1, j)}});
	}
	sort(eg.begin(), eg.end());

	int K = eg.size();
	for(int i = 0; i < K; i++)
	{
		int a = find_set(eg[i].second.first);
		int b = find_set(eg[i].second.second);
		if(a == b) continue;
		if(sz[a] + sz[b] >= T)
		{
			if(sz[a] < T) ans[a] = eg[i].first;
			if(sz[b] < T) ans[b] = eg[i].first;
		}
		union_set(a, b);
	}
	ll sum = 0;
	for(int a : sta)
	{
		find_set(a);
		sum += (ll) ans[a];
	}
	cout << sum << endl;
}