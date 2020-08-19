#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<int> p;
	for(int i = 0; i < n; i+=2)
	{
		p.push_back(a[i]);
	}
	for(int i = 1; i < n; i+=2)
	{
		p.push_back(a[i]);
	}
	{
		int tmp = p.size();
		for(int i = 0; i < tmp; i++)
		{
			p.push_back(p[i]);
		}
	}
	vector<long long> psum(p.size());
	psum[0] = p[0];
	for(int i = 1; i < p.size(); i++)
	{
		psum[i] = psum[i-1] + (long long)p[i];
	}
	long long mx = psum[(n-1)/2];
	for(int a = (n+1)/2; a < psum.size(); a++)
	{
		mx = max(mx, psum[a]-psum[a-(n+1)/2]);
	}
	cout << mx << endl;
}
