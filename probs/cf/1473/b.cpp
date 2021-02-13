#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t; cin >> t; while(t--)
	{
		string s1, s2; cin >> s1 >> s2;
		int n = s1.length(), m = s2.length();
		int L = n*m/__gcd(n, m);
		string A = "";
		string B = "";
		for(int i = 1; i <= L/n; i++) A += s1;
		for(int i = 1; i <= L/m; i++) B += s2;
		if(A == B) cout << A << endl;
		else cout << -1 << endl;
	}
}