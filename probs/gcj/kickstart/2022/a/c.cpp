#include <bits/stdc++.h>

using namespace std;

int fvi[8] = {0, 4, 10, 14, 17, 21, 27, 31};
int svi[8] = {0, 12, 18, 30, 33, 45, 51, 63};

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (n < 5)
	{
		cout << "POSSIBLE" << endl;
		return;
	}
	// calc initial set
	vector<int> a(32), b(32);
	vector<int> v;
	if (s[0] == '0')
		v.push_back(0);
	else if (s[0] == '1')
		v.push_back(1);
	else
	{
		v.push_back(0);
		v.push_back(1);
	}
	for (int i = 1; i < 5; i++)
	{
		if (s[i] == '0')
		{
			for (int &x : v)
			{
				x *= 2;
			}
		}
		else if (s[i] == '1')
		{
			for (int &x : v)
			{
				x *= 2;
				x++;
			}
		}
		else
		{
			for (int &x : v)
			{
				x *= 2;
			}
			int y = v.size();
			for (int i = 0; i < y; i++)
			{
				v.push_back(v[i] + 1);
			}
		}
	}
	for (int x : v)
	{
		for (int y : fvi)
			if (x == y)
			{
				v.erase(find(v.begin(), v.end(), x));
			}
	}
	unique(v.begin(), v.end());
	if (v.empty())
	{
		cout << "IMPOSSIBLE" << endl;
	}
	for (int i = 5; i < n; i++)
	{
		vector<int> toadd;
		vector<int> toera;
		// for(int x : v)
		// {
			// cerr << x << " ";
		// }
		// cerr << endl;
		for (int &x : v)
		{
			if (s[i] == '?')
			{
				vector<int> coc(2);
				for (int j = 0; j < 2; j++)
				{

					int y = x * 2 + j;
					for (int z : svi)
					{
						if (y == z)
						{
							coc[j] = 1;
							break;
						}
					}
				}
				if(!coc[0])
				{
					toadd.push_back(x%16*2);
				} else if(!coc[1])
				{
					toadd.push_back(x%16*2+1);
				}
				toera.push_back(x);
				continue;
			}
			int y = x * 2 + (s[i] - '0');
			bool bad = 0;
			for (int z : svi)
			{
				if (y == z)
				{
					bad = 1;
					break;
				}
			}
			if (bad)
			{
				// v.erase(find(v.begin(), v.end(), x)); // can't use this
				toera.push_back(x);
				continue;							  // will lead to a big palindrome
			}
			x %= 16;
			x *= 2;
			if (s[i] == '1')
			{
				x++;
			}
		}
		for (int y : toadd)
		{
			v.push_back(y);
		}
		for (int y : toera)
		{
			v.erase(find(v.begin(), v.end(), y));
		}
		unique(v.begin(), v.end());
		for (int x : v)
		{
			for (int y : fvi)
			{
				if (x == y)
				{
					v.erase(find(v.begin(), v.end(), x));
				}
			}
		}
		if (v.empty())
		{
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}
	cout << "POSSIBLE" << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
}