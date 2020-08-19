#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, l;
	cin >> n >> l;
	vector<int> pts(n);
	for(int i = 0; i < n; i++)
	{
		cin >> pts[i];
	}
	sort(pts.begin(), pts.end());
	double mx = 0;
	for(int i = 0; i < n-1; i++)
	{
		double y = (double)(pts[i+1]-pts[i])/2.0;
		mx = max(mx, y);
	}
	mx = max(mx, (double)max(pts[0], l - pts[n-1]));
	cout << setprecision(10) << fixed << mx << endl;
}
