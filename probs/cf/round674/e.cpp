#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a[2], b[2];
	for(int i = 0; i < 2; i++)
	{
		int p,q,r;
		cin >> p >> q >> r;
		a[i].push_back(p);
		a[i].push_back(q);
		a[i].push_back(r);
		b[i] = a[i];
	} 
	vector<vector<int> > v;
	v.push_back({0, 0});
	v.push_back({1, 1});
	v.push_back({2, 2});
	v.push_back({0, 2});
	v.push_back({1, 0});
	v.push_back({2, 1});
	sort(v.begin(), v.end());
	int mna = INT_MAX;
	do
	{
		int L = 0;
		for(int i = 0; i < 3; i++)
		{
			a[0][i] = b[0][i];
			a[1][i] = b[1][i];
		}
		for(int i = 0; i < 6; i++)
		{
			int k = min(a[0][v[i][0]], a[1][v[i][1]]);
			a[0][v[i][0]] -= k;
			a[1][v[i][1]] -= k;
			L += k;
		}
		mna = min(mna, n-L);
	} while (next_permutation(v.begin(), v.end()));
	int mxa = 0;
	for(int i = 0; i < 3; i++)
	{
		int k = min(b[0][i], b[1][(i+1)%3]);
		mxa += k;
	}	
	cout << mna << " " << mxa << endl;
}