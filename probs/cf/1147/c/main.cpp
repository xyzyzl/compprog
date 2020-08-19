#include <iostream>
#include <queue>
#include <climits>

using namespace std;

#define MAXN 200005

int n;
int arr[MAXN];
queue<int> q;

int main() {
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) cin >> a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr[a-1
		] = i + 1;
	}
	if (arr[0]) { // the first index is in the pile
		int i = 1;
		// while there is already an increasing stack after 1
		while (i < n && arr[i] - arr[0] == i) i++;
		if (arr[i - 1] == n) {
			int j = i;
			while (j < n && arr[j] <= j - i) j++; // while there is another increasing stack before 1
			if (j >= n) {
				cout << n - i; // i steps have already been done, do the other n-i
				return 0;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, arr[i]-i+n); // the amount of time to move this index to the front, plus n to
		// play every index
	}
	cout << ans;

		return 0;
}