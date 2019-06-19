#include <bits/stdc++.h>

using namespace std;

int n, m, pp[100005];
vector<int> adj_lst[100005];
bool vis[100005];

bool cyclic(int v, int parent) {
	vis[v]=1;
	for(int i : adj_lst[v]) {
		if(!vis[i]) {
            pp[i] = v;
			return cyclic(i, v);
		}
		else if(i != parent) {
            int ct=2;
            int j = v;
            while(j != i) {
                ct++;
                j=pp[j];
            }
            cout << ct << endl;
            cout << i+1 << " ";
            j = v;
            while(j != i) {
                cout << j+1 << " ";
                j=pp[j];
            }
            cout << i+1 << endl;
            return 1;
        }
	}
	return 0;
}

vector<int> vals;
bool cyclic() {
	for(int i : vals) {
		if(!vis[i]) if(cyclic(i, -1)) return 1;
	}
	return 0;
}

int main()
{
    // freopen("in.txt", "r", stdin);
	cin >> n >> m;
    for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
        vals.push_back(x);
        vals.push_back(y);
		adj_lst[x].push_back(y);
		adj_lst[y].push_back(x);
    }
    if(cyclic()) {
		// ok belarusian government is slowing down my code
    } else {
		cout << "IMPOSSIBLE" << endl;
    }
}
