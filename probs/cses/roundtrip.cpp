#include <bits/stdc++.h>

using namespace std;

int n, m, color[100005], mark[100005], par[100005];
vector<int> adj_lst[100005];
bool vis[100005];

void dfs_cycle(int u, int p, int& cyclenumber) {

    if (color[u] == 2) {
        return;
    }

    if (color[u] == 1) {

        cyclenumber++;
        int cur = p;
        mark[cur] = cyclenumber;

        while (cur != u) {
            cur = par[cur];
            mark[cur] = cyclenumber;
        }
        return;
    }
    par[u] = p;
    color[u] = 1;
    for (int v : graph[u]) {
        if (v == par[u]) {
            continue;
        }
        dfs_cycle(v, u, cyclenumber);
    }

    color[u] = 2;
}

bool cyclic(int v, int parent) {
	vis[v]=1;
	for(int i : adj_lst[v]) {
		if(!vis[i]) {
			return cyclic(i, v);
		}
		else if(i != parent) return 1;
	}
	return 0;
}

bool cyclic() {
	for(int i = 0; i < n; i++) {
		if(!vis[i]) if(cyclic(i, -1)) return 1;
	}
	return 0;
}

int main()
{
	cin >> n >> m;
    for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj_lst[x].push_back(y);
		adj_lst[y].push_back(x);
    }
    if(cyclic()) {
		int cyclenumber = 0;
		dfs_cycle(0, -1, cyclenumber);
    } else {
		cout << "IMPOSSIBLE" << endl;
    }
}
