#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define MAXC 30
int a[MAXN], b[MAXN];
int n;
int gr[MAXC][MAXC];
int main()
{
	string S, T;
	cin >> S >> T;
	if(S.size() != T.size()) 
	{
		cout << -1 << endl;
		return 0;
	}
	int r = 0;
	for(int i = 0; i < S.size(); i++)
	{
		r++;
		a[i] = S[i] - 'a';
		b[i] = T[i] - 'a';
	}
	cin >> n;
	for(int i = 0; i < MAXC; i++)
		for(int j = 0; j < MAXC; j++)
			gr[i][j] = 1e8+7;
	for(int i = 0; i < MAXC; i++) gr[i][i] = 0;
	for(int i = 0; i < n; i++)
	{
		char u, v;
		int p, q, w;
		cin >> u >> v >> w;
		p = u - 'a';
		q = v - 'a';
		gr[p][q] = min(gr[p][q], w);
	}
	for(int k = 0; k < 26; k++)
		for(int i = 0; i < 26; i++)
			for(int j = 0; j < 26; j++)
			{
				if(gr[i][k] > 1e8 || gr[k][j] > 1e8)
					continue;
				if(gr[i][j] > gr[i][k] + gr[k][j])
				{
					gr[i][j] = gr[i][k] + gr[k][j];
				}
			}
	int aa = 0;
	vector<char> str;
	for(int i = 0; i < r; i++)
	{
		int fin = -1, mn = 1e8+7;
		for(int j = 0; j < 26; j++)
		{
			int x = gr[a[i]][j];
			int y = gr[b[i]][j];
			if(x > 1e8 && y > 1e8) 
			{
				continue;
			}
			if(x+y < mn)
			{
				fin = j;
				mn = min(mn, x+y);
			}
		}
		if(fin == -1)
		{
			cout << -1 << endl;
			return 0;
		}
		aa += mn;
		str.push_back(fin + 'a');
	}
	cout << aa << endl;
	for(char c : str) cout << c;
	cout << endl;
}

