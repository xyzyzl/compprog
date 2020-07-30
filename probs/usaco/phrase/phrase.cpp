// Solution by: Albert Ye
// AlphaStar 2020 Smmmer Camp: CC31AB
// Problem: feb06-phrase
#include <bits/stdc++.h>

using namespace std;

int n, m;
string book[10005];
int main()
{
	cin >> m >> n;
	getline(cin, book[0]); // deal with newline
	for(int i = 0; i < m; i++)
	{
		getline(cin, book[i]); // input whole line
	}
	// sort books s.t. we can binary search on them
	sort(book, book+m);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		string t = *(lower_bound(book, book+m, s)); // the phrase in the book
		// lexicographically following the phrase.
		t.resize(s.size()); // we only care about the first |s| characters of each string when finding if s is a prefix.
		if(s == t) // if prefix matches
			ans++;
	}
	// O(n lg m) solution, as intended
	cout << ans << endl;
}
