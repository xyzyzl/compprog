// 27:54

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200005
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie();                    \
	cout.tie()

int n, a[MAXN];
multiset<int> b;
int main()
{
	DUEHOANG;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		b.insert(m);
	}
	for(int i = 0; i < n; i++)
	{
		auto it = b.lower_bound(n - a[i]);
		if(it == b.end()) it = b.begin();
		a[i] += *it;
		a[i] %= n;
		b.erase(it);
	}
	for(int i = 0; i < n; i++) cout << a[i] << " ";
}