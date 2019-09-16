#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

int n, k;
bool vis[100005];
vector<int> adj[100005];
int ct;
void bfs(int i){
  queue<int> q;
  q.push(i);
  while(!q.empty()) {
    int x = q.front();
    q.pop();
    if(vis[x]) continue;
    vis[x] = true;
    for(int nx : adj[x]) q.push(nx); 
  }
}

int main()
{
  cin >> n >> k;
  for(int i = 0; i < k; i++){
    int a, b;
    cin >> a >> b;
    adj[--a].push_back(--b);
    adj[b].push_back(a);
  }
  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      ct++;
      bfs(i);
    }
  }
  cout << k-(n-ct) << endl;
}
