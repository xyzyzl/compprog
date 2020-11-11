#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;

int n, m, vs[3005], dst[3005], ml[3005][3], mr[3005][3], D[3005][3005], RD[3005][3005];
int _D[3005][3005], _RD[3005][3005];
vector<int> l[3005], r[3005], adj[3005], adj2[3005];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		if (a == b)
			continue;
		adj[a].push_back(b);
		adj2[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		memset(dst, -0x7f, sizeof dst);
		memset(vs, 0, sizeof vs);
		dst[i] = 0;
		queue<int> q;
		q.push(i);
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			if (vs[x])
				continue;
			vs[x] = 1;
			for (int y : adj[x]) if(dst[y] < 0)
			{
				dst[y] = dst[x] + 1;
				q.push(y);
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (dst[j] > 2e9)
			{
				D[i][j] = -1;
				continue;
			}
			D[i][j] = dst[j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		memset(dst, -0x7f, sizeof dst);
		memset(vs, 0, sizeof vs);
		dst[i] = 0;
		queue<int> q;
		q.push(i);
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			if (vs[x])
				continue;
			vs[x] = 1;
			for (int y : adj2[x]) if(dst[y] < 0)
			{
				dst[y] = dst[x] + 1;
				q.push(y);
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (dst[j] > 2e9)
			{
				RD[i][j] = -1;
				continue;
			}
			RD[i][j] = dst[j];
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			_D[i][j] = D[i][j];
			_RD[i][j] = RD[i][j];
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			int k = max_element(D[i], D[i]+n)-D[i];
			r[i].push_back(k);
			D[i][k] = -1;
			k = max_element(RD[i], RD[i]+n)-RD[i];
			l[i].push_back(k);
			RD[i][k] = -1;
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			D[i][j] = _D[i][j];
			RD[i][j] = _RD[i][j];
		}
	}
	/*
    for(int i = 0; i < n; i++) for(int L : l[i]) for(int R : r[i])
    {
        cerr << L << ' ' << i << ' ' << R << endl;
    }
    */
	int mx = 0;
	int a = 0, b = 0, c = 0, d = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(i != j)
	{
		for(auto L : l[i]) for(auto R : r[j]) if(L != R && L != i && R != i && L != j && R != j)
		{
			int x = RD[i][L] + D[i][j] + D[j][R];
			if(x > mx)
			{
				// cerr << x << endl;
				mx = x;
				a = L+1;
				b = i+1;
				c = j+1;
				d = R+1;
			}
		}
	}
	cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
}
