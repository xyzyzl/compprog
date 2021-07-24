/*input
5 2
1 5
8 10
3 6
2 5
6 9
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k; cin >> n >> k;
	vector<pair<int, int> > S(n);
	for(int i = 0; i < n; i++)
		cin >> S[i].second >> S[i].first;
	sort(S.begin(), S.end());
	multiset<int> ms;
	for(int i = 0; i < k; i++)
		ms.insert(0);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(ms.upper_bound(S[i].second) != ms.begin())
		{
			++ans;
			ms.erase(prev(ms.upper_bound(S[i].second)));
			ms.insert(S[i].first);
		}
	}
	cout << ans << endl;
}