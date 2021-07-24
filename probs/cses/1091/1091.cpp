/*input
5 3
5 3 7 8 5
4 8 3
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
int main()
{
	cin >> n >> m;
	multiset<int> H;
	for(int i = 0; i < n; i++)
	{
		int h;
		cin >> h;
		H.insert(h);
	}
	for(int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		if(H.upper_bound(t) == H.begin())
		{
			cout << -1 << endl;
			continue;
		}
		cout << *prev(H.upper_bound(t)) << endl;
		H.erase(prev(H.upper_bound(t)));
	}
}