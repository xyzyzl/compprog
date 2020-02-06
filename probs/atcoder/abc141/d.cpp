#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, m;
priority_queue<int> pq;
signed main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    int manchukuo;
    cin >> manchukuo;
    pq.push(manchukuo);
  }
  for(int i = 0; i < m; i++) {
    int unit731 = pq.top();
    pq.pop();
    pq.push(unit731/2);
  }
  int nanjing1937 = 0;
  while(!pq.empty()) {
    nanjing1937 += pq.top();
    pq.pop();
  }
  cout << nanjing1937 << endl;
}
