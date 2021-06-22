#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n; cin >> n;
	if(n%2)
	{
		cout << "Bob" << endl;
	} else 
	{
		if(log2(n) == floor(log2(n)))
		{
			if((int)log2(n) % 2) cout << "Bob" << endl;
			else cout << "Alice" << endl;
		} else 
		{
			cout << "Alice" << endl;
		}
	}
}

int main()
{
	int t; cin >> t; while(t--) solve();
}