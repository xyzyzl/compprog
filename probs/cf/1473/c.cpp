#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, k; cin >> n >> k;
		vector<int> seq; for(int i = 0; i < k-(n-k)-1; i++) seq.push_back(i+1);
		for(int i = k; i >= k-(n-k); i--) seq.push_back(i);
		for(int x : seq) cout << x << " ";
		cout << endl; 
	}
}