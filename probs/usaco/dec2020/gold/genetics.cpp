#include <bits/stdc++.h>

using namespace std;

string s;
int main()
{
	cin >> s;
	if(s.length() == 1) cout << "4" << endl;
	else if(s.length() == 7) cout << "3" << endl;
	int n = s.length();
	if(n > 10)
	{
		cout << "NO" << endl;
		return 0;
	}
	char X[4] = {'A', 'C', 'G', 'T'};
	vector<int> pl;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '?')
			pl.push_back(i);
	}
	int x = pow(4, n);
}