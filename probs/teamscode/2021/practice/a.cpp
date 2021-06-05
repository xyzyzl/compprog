#include <bits/stdc++.h>

using namespace std;

string V[1005];
int main()
{
	string s;
	cin >> s;
	int id = 0, sz = 0;
	V[id] = "https://hzxjhs.com/";
	while(s != "QUIT")
	{
		if(s == "VISIT")
		{
			string site; cin >> site;
			cout << site << endl;
			V[++id] = site;
			sz = id;
		} else if(s == "BACK")
		{
			if(id == 0) cout << "Ignored" << endl;
			else cout << V[--id] << endl;
		} else if(s == "FORWARD")
		{
			if(id == sz) cout << "Ignored" << endl;
			else cout << V[++id] << endl;
		}
		cin >> s;
	}
}
