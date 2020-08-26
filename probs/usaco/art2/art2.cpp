#include <bits/stdc++.h>

using namespace std;

int n, a[100005], e[100005], vis[100005];
int main()
{
	freopen("art2.in", "r", stdin);
	freopen("art2.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		e[a[i]] = i;
	}
	stack<int> st;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(!a[i]) continue;
		if(vis[a[i]] && st.top() != a[i])
		{
			cout << -1 << endl;
			return 0;
		}
		if(!vis[a[i]]) 
		{
			st.push(a[i]);
			vis[a[i]] = 1;
			ans = max(ans, (int)st.size());
		}
		if(e[st.top()] == i)
		{
			st.pop();
		}
	}
	cout << ans << endl;
}
