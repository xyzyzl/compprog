// Solution by: Albert Ye
// AlphaStar 2020 Summer Camp: CC31AB
// Problem: dec14-marathon
#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> pos[100005];

// distance between checkpoints i, j
int dist(int i, int j)
{
	return abs(pos[i].first-pos[j].first) + abs(pos[i].second-pos[j].second);
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> pos[i].first >> pos[i].second;
	}
	// Find the total distance to run through the course without any skips. This is an option
	// that Bessie can take.
	int tot = 0;
	for(int i = 1; i < n; i++)
	{
		tot += dist(i, i-1);
	}
	int ans = tot;
	// Bessie can choose any of the checkpoints from indices 1..n-2 to skip
	for(int i = 1; i < n-1; i++)
	{
		// temporary variable that stores the answer if checkpoint i is skipped
		int tmp = tot;
		// remove i-1 -> i, i -> i+1
		tmp -= dist(i-1, i);
		tmp -= dist(i, i+1);
		// add i-1 -> i+1
		tmp += dist(i-1, i+1);
		ans = min(ans, tmp);
	}
	cout << ans << endl;
}
