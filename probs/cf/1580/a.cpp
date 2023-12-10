#include <iostream>
#include <climits>

using namespace std;

const int MAXN = 401;

int n, m;
int a[MAXN][MAXN], ps[MAXN][MAXN], smin[MAXN];

int rect_sum(int x1, int y1, int x2, int y2) {
	return ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c; cin >> c;
			a[i][j] = c - '0';
		}
	}
	// calculate the prefix sums of a
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ps[i][j] = a[i][j] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
		}
	}
	int ans = INT_MAX;
	for (int lo = 1; lo <= n; lo++) {
		for (int hi = lo + 4; hi <= n; hi++) {
			for (int right = 4; right <= m; right++) {
				smin[right] = rect_sum(lo + 1, 1, hi - 1, right - 1)
								+ right - 1 - rect_sum(lo, 1, lo, right - 1)
								+ right - 1 - rect_sum(hi, 1, hi, right - 1)
								+ hi - lo - 1 - rect_sum(lo + 1, right, hi - 1, right); 
			}
			// take the suffix minimum.
			for (int right = m - 1; right >= 4; right--) {
				smin[right] = min(smin[right + 1], smin[right]);
			}
			// for each left portal frame, find the corresponding right portal frame.
			for (int left = 1; left <= m - 3; left++) {
				int cur = smin[left + 3]	
							- rect_sum(lo + 1, 1, hi - 1, left)
							- (left - rect_sum(lo, 1, lo, left))
							- (left - rect_sum(hi, 1, hi, left))
							+ hi - lo - 1 - rect_sum(lo + 1, left, hi - 1, left);
				ans = min(ans, cur);
			}
		}
	}
	cout << ans << endl;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
}
