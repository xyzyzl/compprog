#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> s;
		for(int i = 0; i < n; i++) s.push_back(9);
		for(int i = 0; i < ceil((double)n / 4.0); i++) s[i] = 8;
		reverse(s.begin(), s.end());
		for(int c : s) cout << c;
		cout << endl;
	}
}
