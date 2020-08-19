#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second
#define ll long long

#define X 97ll
#define M 999999929ll

int n, k[205], H[205], p[205];
pii arr[205];

void gen_hash()
{
	p[0] = 1;
	for(int i = 1; i < n; i++)
	{
		p[i] = (ll)(p[i-1]*X) % (ll)M;
	}
	H[0] = k[0];
	for(int i = 1; i < n; i++)
	{
		H[i] = ((ll)(H[i-1]*X) % M + (ll)k[i]) % M;
	}
}

int cwdist[205][205], dist[205];
void gen_dist()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			cwdist[i][(j+1)%n] = cwdist[i][j] + abs((arr[j].f - arr[(j+1)%n].f) + (arr[j].s - arr[(j+1)%n].s));
			if(j+1 != n) cwdist[(j+1)%n][i] = INT_MAX;
		}
	}
	for(int i = 0; i < n; i++)
	{
		dist[i] = min(cwdist[0][i], cwdist[i][0]);
	}
}

int main()
{
	// freopen("lightsout.in", "r", stdin);
	// freopen("lightsout.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i].f >> arr[i].s;
	}
	for(int i = 1; i < n; i++)
	{
		int pre = i-1;
		int nxt = (i+1)%n;
		if(arr[i].f - arr[pre].f > 0)
		{
			if(arr[nxt].s - arr[i].s > 0) k[i] = 1;
			else k[i] = 2;
		} else if(arr[i].f - arr[pre].f < 0)
		{
			if(arr[nxt].s - arr[i].s > 0) k[i] = 2;
			else k[i] = 1;
		} else 
		{
			if(arr[i].s - arr[pre].s > 0)
			{
				if(arr[nxt].f - arr[i].f > 0) k[i] = 2;
				else k[i] = 1;
			} else if(arr[i].s - arr[pre].s < 0)
			{
				if(arr[nxt].f - arr[i].f > 0) k[i] = 1;
				else k[i] = 2;
			}
		}
	}
/*
	for(int i = 0; i < n; i++) cerr << k[i] << " ";
	cerr << endl;
	*/
	gen_dist();
	gen_hash();
	dist[0] = 0;
	int ans = 0;
	for(int sp = 0; sp < n-1; sp++)
	{
		int know = -1;
		for(int L = 1; L < n-sp; L++)
		{
			int x = (H[sp+L] - ((ll)H[sp]*p[L])%M + M)%M;
			int nocc = 0;
			for(int pt = 0; pt < n-L; pt++)
			{
				if((H[pt+L] - ((ll)H[pt]*p[L])%M + M)%M == x)
					nocc++;
			}
			if(nocc == 1)
			{
				know = sp+L;
				break;
			}
		}
		int a = cwdist[sp+1][0];
		if(know != -1)
		{
			a = dist[know] + cwdist[sp+1][know];
		}
		int b = dist[sp+1];
		// cerr << a << " " << b << endl;
		ans = max(ans, a-b);
	}
	cout << ans << endl;
}
