#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n; cin >> n;
	vector<vector<int> > q(n);
	for(int i = 0; i < n; i++) for(int j = 0; j < n-1; j++)
	{
		int w; cin >> w;
		q[i].push_back(w);
	}
	vector<int> p(n);
	for(int i = 0; i < n; i++) 
	{
		// assume q[i] has no 1.
		int j = (i+1)%n; // another index w/o 1 missing
		int T = 0;
		bool ok = 1;
		while(T < 2)
		{
			int a_i = 0, a_j = 0, a_p = 0;
			while(a_i < n-1)
			{
				if(a_j < n-1 && q[j][a_j] == 1)
				{
					if(T == 0)
					{
						p[a_p] = q[i][a_i]+1;
						a_i++;
						p[a_p+1] = 1;
						a_p++;
					}
					else if(T == 1) p[a_p] = 1;
				}
				else
					p[a_p] = q[i][a_i++]+1;
				a_j++;
				a_p++;
			}
			// let p be our desired p.
			vector<int> vis(n+1,0);
			for(int k = 0; k < n; k++)
			{
				ok = 1;
				for(int no = 1; no <= n; no++)
				{
					if(vis[no] == 1) continue;
					ok = 1;
					a_p = 0;
					for(int l = 0; l < n-1; l++)
					{
						if(p[a_p] == no) l--;
						else
						{
							if(p[a_p] > no)
							{
								if(p[a_p]-1 != q[k][l]) 
								{
									ok = 0; break;
								}
							}
							else if(p[a_p] != q[k][l])
							{
								ok = 0; break;
							}
						}
						a_p++;
					}
					if(ok)
					{
						vis[no] = 1;
						break;
					}
				}
				if(!ok) break;
			}
			if(ok)
			{
				break;
			}
			T++;
		}
		if(ok) break;
	}
	for(int i = 0; i < n; i++) 
	{
		cout << p[i] << " ";
	}
	cout << endl;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		solve();
	}
}
