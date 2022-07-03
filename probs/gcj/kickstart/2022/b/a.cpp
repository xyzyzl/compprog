#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589

void solve()
{
	int r, a, b; cin >> r >> a >> b;
	double ans = 0;
	while(r > 0)
	{
		double k = PI * r * r + PI * (r*a) * (r*a);
		ans += k;
		r *= a;
		r /= b;
	}
	cout << setprecision(9) << fixed << ans << endl;
}

int main()
{
	int t; cin >> t;
	for(int i = 0; i < t; i++)
	{
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}