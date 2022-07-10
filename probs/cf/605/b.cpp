#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n, m;
vector<pair<pair<int, int>, int> > e;
pair<int, int> ans[MAXN];
int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		e.push_back({{a,-b},i});
	}
	sort(e.begin(), e.end());
	int lst = 1;
	int p=2,q=3;
	for(int i = 0; i < m; i++)
	{
		if(e[i].first.second == -1)
		{
			lst++;
			ans[e[i].second] = {1, lst};
		} else 
		{
			if(p > lst || q > lst)
			{
				cout << -1 << endl;
				return 0;
			}
			ans[e[i].second] = {p,q};
			p++;
			if(p == q)
			{
				q++;
				p = 2;
			}
		}
	}
	for(int i = 0; i < m; i++)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}