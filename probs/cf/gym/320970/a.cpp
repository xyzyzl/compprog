#include <bits/stdc++.h>

using namespace std;
const int MAXN = 105;

int n, a[MAXN];
void solve()
{
	cin >> n;
	int S = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		S += a[i];
	}
	sort(a, a+n);
	if(a[n-1] > S/2)
	{
		cout << "T" << endl;
	} else 
	{
		if(S%2) cout << "T" << endl;
		else cout << "HL" << endl;
	}
}

int main()
{
	int T; cin >> T;
	while(T--) solve();
}