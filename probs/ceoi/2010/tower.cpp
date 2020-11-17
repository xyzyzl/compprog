#include <bits/stdc++.h>

#define MOD 1000000009
#define ll long long
using namespace std;

int n, d, a[1000005];
ll w[1000005], tot[1000005];
int main()
{
	cin >> n >> d; for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	tot[0] = 1;
	int lo=0;
	for(int i = 0; i < n; i++)
	{
		while(a[lo]+d < a[i]) lo++;
		w[i] = (i-lo)+1;
	}
	// for(int i = 0; i < n; i++) cerr << w[i] << endl;
	for(int i = 1; i < n; i++)
	{
		tot[i] = (tot[i-1]*w[i]) % MOD;
	}
	cout << tot[n-1] << endl;
}