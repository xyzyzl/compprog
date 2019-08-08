#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORD(i, n) for(int i = n-1; i >= 0; i--)
#define FOBIR(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
 
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

int n, m;
bool can_reach_n[2505];
vi bck_lst[2505];
void dfs(int v)
{
	if(can_reach_n[v]) return;
	can_reach_n[v] = 1;
	for(int i : bck_lst[v]) dfs(i);
}
int main() {
    DUEHOANG;
    int c=1;
    FOR(i, c) {
        int n, m;
        cin >> n >> m;
        if(n==1) {
            cout << 0 << endl;
            return 0;
        }
        vector<pii> adj_lst[n];
        long long dist[n];
        FOR(i, m) {
            int a, b, w;
            cin >> a >> b >> w;
            a--; b--;
            adj_lst[a].pb(mp(-w, b));
			bck_lst[b].pb(a);
        }
        fill(dist, dist+n, INT_MAX);
        dist[0] = 0;
		dfs(n-1);
        FOR(_i, n) {
            FOR(i, n) {
                for(pii j : adj_lst[i]) {
                    if(dist[i]+j.f < dist[j.s]) {
                        dist[j.s] = dist[i]+j.f;
                    }
                }
            }
        }
		// I solved a USAMO problem!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        bool bad = false;
        FOR(i, n) {
			if(!can_reach_n[i]) continue;
			for(pii j : adj_lst[i]) {
				// cout << j.s << endl;
        	    if(dist[i]+j.f < dist[j.s]) {
        	        bad = true;
        	    }
        	}
		}
        if(bad) cout << -1 << endl;
		else {
			cout << -dist[n-1] << endl;
		}
    }
}