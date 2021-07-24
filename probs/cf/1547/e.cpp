#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, k; cin >> n >> k;
	vector<int> L(n+2, 2e9), R(n+2, 2e9);
	vector<int> a(k), t(k);
	for(int i = 0; i < k; i++)
		cin >> a[i];
	for(int i = 0; i < k; i++)
		cin >> t[i];
	for(int i = 0; i < k; i++)
		L[a[i]] = R[a[i]] = t[i];
	for(int i = 1; i <= n; i++) L[i] = min(L[i-1]+1, L[i]);
	for(int i = n; i >= 1; i--) R[i] = min(R[i+1]+1, R[i]);
	for(int i = 1; i <= n; i++) cout << min(L[i], R[i]) << ' ';
	cout << endl;
}

int main()
{
	int t; cin >> t; 
	while(t--) solve();
}
