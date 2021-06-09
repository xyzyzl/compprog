#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define int long long

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;
    FenwickTree(){}
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
} tree;

int n;
vector<int> adj[MAXN];
int in[MAXN];
int arr[MAXN];
set<pair<int, int>, greater<pair<int, int>>> st;
int ans;

signed main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n; tree = FenwickTree(n);
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b; --a; --b;
        adj[b].push_back(a);
        in[a]++;
    }
    for(int i = 0; i<n; i++) if(in[i] == 0) st.insert({arr[i], i});
    while(!st.empty()){
        auto x = (*st.begin()); st.erase(st.begin());
        int v = x.second, val = x.first;
        tree.add(v, val);
        ans += tree.sum(0, v)+2*val;
        for(auto u : adj[v]){
            in[u]--;
            if(in[u] == 0) st.insert({arr[u], u});
        }
    }
    cout << ans << endl;
}
