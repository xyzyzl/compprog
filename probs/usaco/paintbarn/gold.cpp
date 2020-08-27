#include <bits/stdc++.h>

#define int long long
using namespace std;

int n,k,ps[205][205],vl[205][205],pv[205][205],sc,ec,sr,er;

int max_rect()
{
	int ret = INT_MIN;
	for(int i = 0; i < 200; i++) for(int j = 0; j < 200; j++)
		pv[i][j] = vl[i][j];
	for(int i = 0; i < 200; i++) for(int j = 1; j < 200; j++)
		pv[i][j] += pv[i][j-1];
	for(int i = 0; i < 200; i++) for(int j = i; j < 200; j++)
	{
		// prefix sum from cols i...j
		vector<int> tmp(205);
		for(int r = 0; r < 200; r++) 
			tmp[r] = pv[r][j] - (i>0 ? pv[r][i-1] : 0);
		// current sum, current max sum
		int cs = 0, cm = 0;
		// current start row, temp. start row, current end row
		int csr = 0, tsr = 0, cer = -1;
		// Kadane
		for(int r = 0; r < 200; r++)
		{
			cs += tmp[r];
			if(cs < 0)
			{
				cs = 0;
				tsr = r+1;
			} else if(cs > cm)
			{
				cm = cs;
				csr = tsr;
				cer = r;
			}
		}
		// check if current end row doesn't exist
		if(cer == -1)
		{
			continue;
		}
		if(cm > ret)
		{
			ret = cm;
			sc = i;
			ec = j;
			sr = csr;
			er = cer;
		}
	}
	return ret;
}

signed main()
{
	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ps[x1][y1]++;
		ps[x1][y2]--;
		ps[x2][y1]--;
		ps[x2][y2]++;
	}
	for(int i = 0; i < 200; i++) for(int j = 0; j < 200; j++)
	{
		if(i) ps[i][j] += ps[i-1][j];
		if(j) ps[i][j] += ps[i][j-1];
		if(i&&j) ps[i][j] -= ps[i-1][j-1];
	}
	int cnt = 0;
	for(int i = 0; i < 200; i++) for(int j = 0; j < 200; j++)
	{
		if(ps[i][j] == k)
		{
			vl[i][j] = -1;
			cnt++;
		}
		else if(ps[i][j] == k-1) vl[i][j] = 1;
	}
	// cerr << cnt << endl;
	// cerr << max_rect() << endl;
	int a = max_rect();
	// cerr << sc << " " << ec << " " << sr << " " << er << endl;
	for(int i = sr; i <= er; i++)
	{
		for(int j = sc; j <= ec; j++)
		{
			vl[i][j] = -40000;
		}
	}
	int b = max_rect();
	cnt += max(a,0ll)+max(b,0ll);
	cout.tie(NULL);
	cout << cnt << endl;
}
