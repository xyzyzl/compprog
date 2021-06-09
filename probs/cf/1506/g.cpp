#include <bits/stdc++.h>

using namespace std;

void solve() 
{
	int n; string s;
	cin >> s; n = s.length();
	unordered_set<char> cs(s.begin(), s.end());
	int m = cs.size();
	string uniq="";
	unordered_set<char> sp;
	while(m)
	{
		char c = -1;
		for(char d : cs)
		{
			sp.clear();
			bool has=0;
			for(int i = 0; i < n; i++)
			{
				if((s[i] != d) && has) sp.insert(s[i]);
				else if(s[i] == d) has=1;
			}
			sp.insert(d);
			if(sp.size()==m) c = max(c,d);
		}
		uniq += c; --m; cs.erase(c);
		bool has = 0;
		string t="";
		for(int i = 0; i < n; i++)
		{
			if(s[i] != c && has) t += s[i];
			else if(s[i] == c) has=1;
		}
		s=t; n=s.length();
	}
	cout << uniq << endl;
}
int main() { int t; cin >> t; while(t--) solve(); }
