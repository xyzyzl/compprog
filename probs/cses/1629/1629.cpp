/*input
3
3 5
4 9
5 8
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<pair<int, int> > S(n);
	for(int i = 0; i < n; i++)
	{
		pair<int, int> p;
		cin >> p.second >> p.first;
		S[i] = p;
	}
	sort(S.begin(), S.end());
	int ans = 0;
	int cur_end = -1;
	for(int i = 0; i < n; i++)
	{
		if(S[i].second >= cur_end)
		{
			cur_end = S[i].first;
			ans++;
		}
	}
	cout << ans << endl;
}