
#include <bits/stdc++.h>

using namespace std;

void check(string &t, string &part)
{
	if (t.size() < part.size())
	{
		return;
	}
	string k = t.substr(t.size() - part.size());
	if (k == part)
	{
		t.resize(t.size() - part.size());
	}
}

string removeOccurrences(string s, string part)
{
	string t;
	for (char c : s)
	{
		t.push_back(c);
		check(t, part);
	}
	return t;
}

int main()
{
	string s; cin >> s;
	string part; cin >> part;
	cout << removeOccurrences(s, part) << endl;
}