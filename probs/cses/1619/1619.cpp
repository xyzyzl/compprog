/*input
3
5 8
2 4
3 9
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<pair<int, int> > v;
	for(int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		v.push_back({a, -1});
		v.push_back({b, 1});
	}
	sort(v.begin(), v.end());
	int k = 0;
	int ans = 0;
	for(auto x : v)
	{
		k -= x.second;
		ans = max(ans, k);
	}
	cout << ans << endl;
}