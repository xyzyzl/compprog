#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
	long long A; cin >> A;
	int ans = 0;
	for(int d1 = 1; d1 <= 9; d1++) for(int d2 = 0; d2 <= 9; d2++) for(int d3 = 0; d3 <= 9; d3++) for(int d4 = 0; d4 <= 9; d4++)
	for(int d5 = 0; d5 <= 9; d5++)
	{
		long long k = (d1 * 1000000001ll) + (d2*100000010ll) + (d3*10000100ll) + (d4*1001000ll) + (d5*1100000ll);
		ans += (A % k == 0);
		k = (d1 * 100000001ll) + (d2*10000010ll) + (d3*1000100ll) + (d4*101000ll) + (d5*10000ll);
		ans += (A % k == 0);
	}
	for(int d1 = 1; d1 <= 9; d1++) for(int d2 = 0; d2 <= 9; d2++) for(int d3 = 0; d3 <= 9; d3++) for(int d4 = 0; d4 <= 9; d4++)
	{
		long long k = (d1 * 10000001ll) + (d2 * 1000010ll) + (d3 * 100100ll) + (d4 * 11000ll);
		ans += (A % k == 0);
		k = (d1 * 1000001ll) + (d2 * 100010ll) + (d3 * 10100ll) + (d4 * 1000ll);
		ans += (A % k == 0);
	}
	for(int d1 = 1; d1 <= 9; d1++) for(int d2 = 0; d2 <= 9; d2++) for(int d3 = 0; d3 <= 9; d3++)
	{
		long long k = (d1 * 100001) + (d2 * 10010) + (d3 * 1100);
		ans += (A % k == 0);
		k = (d1 * 10001) + (d2 * 1010) + (d3 * 100);
		ans += (A % k == 0);
	}
	for(int d1 = 1; d1 <= 9; d1++) for(int d2 = 0; d2 <= 9; d2++)
	{
		long long k = (d1 * 1001) + (d2*110);
		ans += (A % k == 0);
		k = (d1*101) + (d2*10);
		ans += (A % k == 0);
	}
	for(int i = 1; i <= 9; i++)
	{
		ans += (A % i == 0);
		ans += (A % (i*11) == 0);
	}
	cout << ans << endl;
}

signed main()
{
	int t; cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
}