#include <bits/stdc++.h>
#define int long long

using namespace std;

struct var
{
	int len, ct;
	string l, r;
};

map<string, var> vars;

void solve()
{
	int n; cin >> n;
	string last = "";
	for(int i = 0; i < n; i++)
	{
		string vn; cin >> vn;
		last = vn;
		string op; cin >> op;
		if(op[0] == ':')
		{
			// is an assignment op
			var ne = var();
			string s2; cin >> s2; 
			ne.len = s2.length();
			int ct = 0;
			for(int i = 0; i < ne.len-3; i++)
			{
				if(s2.substr(i, 4) == "haha")
				{
					ct++;
				}
			}
			ne.ct = ct;
			ne.l = s2.substr(0, min(3ll, ne.len));
			ne.r = s2.substr(max(0ll, ne.len-3), min(3ll, ne.len));
			vars[vn] = ne;
			// cerr << ne.l << " " << ne.r << " " << s2 << " " << ne.ct << endl;
		} else 
		{
			string v1, pl, v2; cin >> v1 >> pl >> v2;
			var ne = var();
			var o1 = vars[v1];
			var o2 = vars[v2];
			ne.len = o1.len + o2.len;
			string s2 = o1.r + o2.l;
			int ct = 0;
			for(int i = 0; i < (int)s2.length() - 3; i++)
			{
				if(s2.substr(i, 4) == "haha")
				{
					ct++;
				}
			}
			ne.ct = ct + o1.ct + o2.ct;
			if(o1.len < 3 || o2.len < 3)
			{
				string l, r;
				if(o1.len < 3)
				{
					l = o1.l + o2.l.substr(0, min(o2.len, 3-o1.len));
				} else l = o1.l;
				if(o2.len < 3)
				{
					r = o1.r.substr(0, min(o1.len, 3-o2.len)) + o2.r;
				} else r = o2.r;
				ne.l = l;
				ne.r = r;
			} else 
			{
				ne.l = o1.l;
				ne.r = o2.r;
			}
			vars[vn] = ne;
		}
	}
	cout << vars[last].ct << endl;
}

main()
{
	int t; cin >> t;
	while(t--) solve();
}