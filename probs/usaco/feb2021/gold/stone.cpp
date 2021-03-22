#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 100005;

int n, a[MAXN], maxa;
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		maxa = max(maxa, a[i]);
	}
	vector<int> c(maxa+1); // cumulative maximum
	for(int i = 0; i < n; i++) c[a[i]]++;
	for(int i = 1; i <= maxa; i++) c[i] = c[i-1]+c[i];

	ll ans = 0;
	for(int k = 1; k <= maxa; k++)
	{
		vector<int> ct;
		// find the frequency of each interval ki to k(i+1)-1. these values aren't mutually reachable
		for(int i = 1; k*i <= maxa; i++)
		{
			if(k*(i+1)-1 <= maxa) ct.push_back(c[k*(i+1)-1]-c[k*i-1]);
			else ct.push_back(c.back()-c[k*i-1]);
		}
		// for(int x : ct) cerr << x << " ";
		vector<int> odds;
		for(int i = 0; i < ct.size(); i++)
		{
			if(ct[i]%2) odds.push_back(i+1); // pick an interval with odd # of occurences
		}
		if(odds == vector<int>{1} || (odds.size()==2 && odds[0]+1==odds[1])) ans += ct[odds.back()-1];
	}
	cout << ans << endl;	
}