#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector <int> v [n+1];
    priority_queue <pair<int,int>> pq;
    int lv [n+1];
    bool direct [n+1];
    for(int i = 0; i <= n; i++){
        lv[i] = 0;
    }
    lv[1] = 1000000000;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
   //     cout << a << b << endl;
        pq.push(make_pair(b,a));
        lv[a] = b;
        direct[a] = true;
    }
    for(int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    while(!pq.empty()){
        int cur = pq.top().second;
        int dis = pq.top().first;
    //    cout << cur << " " << dis << endl;
        pq.pop();
        if(lv[cur] > dis){
            continue;
        }
        for(int i = 0; i < v[cur].size(); i++){
            if(lv[v[cur][i]] < dis/2 && !direct[v[cur][i]]){
                pq.push(make_pair(dis/2,v[cur][i]));
                lv[v[cur][i]] = dis/2;
            }
        }
    }
    vector <pair<int,int>> t;
    for(int i = 2; i <= n; i++){
        t.push_back(make_pair(lv[i],-i));
    }
    sort(t.begin(), t.end());
    for(int i = n-2; i >= 0; i--){
        cout << -t[i].second << " " << t[i].first << endl;
    }
}
