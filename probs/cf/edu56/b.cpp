#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		set<int> occ;
		for(int i = 0; i < s.length(); i++)
		{
			occ.insert(s[i]);
		}
		if(occ.size() == 1)
		{
			cout << -1 << endl;
			continue;
		}
		sort(s.begin(), s.end());
		cout << s << endl;
	}
}
