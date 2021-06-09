#include <bits/stdc++.h>

using namespace std;
const int N = 2e7+5;

vector<int> D, V;
void solve()
{
	int c, d, x;
	cin >> c >> d >> x;
	int ans = 0;
	for(int i = 1; i * i <= x; i++)
	{
		if((x%i)) continue;

		int k1 = x/i+d;
		if(!(k1%c)){
			// find the number of values.
			ans += (1 << V[k1/c]);
		}

		if(i*i==x) continue;
		int k2 = i+d;
		if(!(k2%c)){
			// find the number of values.
			ans += (1 << V[k2/c]);
		}
	}
	cout << ans << endl;
}

int main()
{
	D.assign(N, -1);
	V.resize(N);
	D[1] = 1;
	for(int i = 2; i < N; i++)
	{
		if(D[i] == -1) for(int j = i; j < N; j+=i) if(D[j] == -1) D[j] = i;
	}
	for(int i = 2; i < N; i++)
	{
		int j = i / D[i];
		V[i] = V[j] + (D[i] != D[j]);
	}
	int t; cin >> t;
	while(t--) solve();
}