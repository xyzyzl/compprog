#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> ps(n+1);
	int q; cin >> q;
	for(int i = 1; i <= n; i++)
	{
		char a; cin >> a;
		ps[i] = ps[i-1] + a - ('a'-1);
	}
	while(q--)
	{
		int a, b; cin >> a >> b;
		cout << ps[b] - ps[a-1] << endl;
	}
}