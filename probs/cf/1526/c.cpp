#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAXN = 200005;

int n, a[MAXN];
signed main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	multiset<int> S;
	int h = 0;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		++ans;
		h += a[i];
		if(a[i] < 0)
		{
			S.insert(a[i]);
		}
		while(h < 0)
		{
			h -= *S.begin();
			S.erase(S.begin());
			--ans;
		}
	}
	cout << ans << endl;
}