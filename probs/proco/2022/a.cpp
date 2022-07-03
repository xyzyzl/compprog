#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<pair<double, int> > a(n);
	for(int i = 0; i < n; i++)
	{
		int p, q, r; cin >> p >> q >> r;
		double d = (double)q/r;
		a[i] = {-d, p};
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++)
	{
		cout << a[i].second << endl;
	}
}