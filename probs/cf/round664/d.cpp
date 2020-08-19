#include <bits/stdc++.h>

using namespace std;

int n;
long long d, m, a[100005], b[100005];
int sa, sb;
int main()
{
	cin >> n >> d >> m;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if(x <= m)
		{
			a[++sa] = x;
		} else
		{
			b[++sb] = x;
		}
	}
	sort(a+1, a+sa+1);
	reverse(a+1, a+sa+1);
	for(int i = 1; i <= sa; i++) a[i] = a[i-1] + a[i];
	sort(b+1, b+sb+1);
	reverse(b+1, b+sb+1);
	for(int i = 1; i <= sb; i++) b[i] = b[i-1] + b[i];
	long long ans = 0;
	for(int i = 0; i <= sb; i++)
	{
		if(i)
		{
			long long lhs = b[i];
			if(n-(d+1)*(i-1)-1 < 0) continue;
			long long rhs = a[min((long long)sa, n-(d+1)*(i-1)-1)];
			ans = max(ans, lhs+rhs);
		} else
		{
			ans = a[sa];
		}
	}
	cout << ans << endl;
}
