#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		multiset<int> ms;
		for(int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			ms.insert(a);
		}
		int ret = 0;
		for(int su = 1; su <= 2*n; su++)
		{
			int ct = 0;
			multiset<int> nms = ms;
			while(!nms.empty())
			{
				int x = *nms.begin();
				auto it = nms.lower_bound(su-x);
				if(it == nms.begin()) it++;
				if(it == nms.end())
				{
					nms.erase(nms.begin());
					continue;
				}
				int y = *it;
				if(x+y > su)
				{
					nms.erase(nms.begin());
					continue;
				}
				nms.erase(nms.begin());
				nms.erase(it);
				ct++;
			}
			ret = max(ret, ct);
		}
		cout << ret << endl;
	}
}
