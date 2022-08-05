#include <bits/stdc++.h>
using namespace std;
struct ladder {
  int a, b, c, d, h;
};
struct pos {
  int i, j, h;
};
int main() {
  int t;
  cerr << "skill issue" << endl;
	cin >> t;
	int n, m, k, multiplier[100001], ans, memo[100001][100001];
	vector<vector<int> > ladders_on_floor(100001);
	ladder ladders[100001];
	pos start;
	queue<pos> cur;
	while (t--) {
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				memo[i][j] = INT_MAX;
			}
		}
		for (int i = 1; i <= n; i++) {
			cin >> multiplier[i];
		}
		for (int i = 1; i <= n; i++) {
			ladders_on_floor[i].clear();
		}
		for (int i = 0; i < k; i++) {
			cin >> ladders[i].a >> ladders[i].b >> ladders[i].c >> ladders[i].d >> ladders[i].h;
			ladders_on_floor[ladders[i].a].push_back(i);
		}
		start.i = 1;
		start.j = 1;
		start.h = 0;
	  ans = INT_MAX;
	  cur.push(start);
		while (cur.empty() != true) {
      cerr << cur.size() << endl;
			for (int idx = cur.size(); idx > 0; idx--) {
				cerr << cur.empty() << endl;
				if (cur.front().i == n) {
					ans = min(ans, cur.front().h + (m - cur.front().j) * multiplier[n]);
				} else {
					if (memo[cur.front().i][cur.front().j] > cur.front().h) {
						for (int i = 0; i < ladders_on_floor[cur.front().i].size(); i++) {
							start.i = ladders[ladders_on_floor[cur.front().i][i]].c;
			
							start.j = ladders[ladders_on_floor[cur.front().i][i]].d;
							start.h = abs(cur.front().j - ladders[ladders_on_floor[cur.front().i][i]].b) * multiplier[cur.front().i] + cur.front().h - ladders[ladders_on_floor[cur.front().i][i]].h;
							cur.push(start);
						}
						memo[cur.front().i][cur.front().j] = cur.front().h;
					}
				}
				cur.pop();
			}
		}
		if (ans != INT_MAX) {
			cout << ans << endl;
		} else {
			cout << "NO ESCAPE" << endl;
		}
	}
}
/* 
4
5 3 3
5 17 8 1 4
1 3 3 3 4
3 1 5 2 5
3 2 5 1 6
6 3 3
5 17 8 1 4 2
1 3 3 3 4
3 1 5 2 5
3 2 5 1 6
5 3 1
5 17 8 1 4
1 3 5 3 100
5 5 5
3 2 3 7 5
3 5 4 2 1
2 2 5 4 5
4 4 5 2 3
1 2 4 2 2
3 3 5 2 4
*/