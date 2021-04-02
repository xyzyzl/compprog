#include <bits/stdc++.h>

using namespace std;
using ld = long double;

const int MAXN = 200005;

int N;
ld a[MAXN];

struct BIT
{
	ld bit[3*MAXN] = {0};
	void upd(int ind, ld val)
	{
		while(ind <= 3*MAXN)
		{
			bit[ind] += val;
			ind += (ind&-ind);
		}
	}
	ld sum(int ind)
	{
		ld ret = 0;
		while(ind > 0)
		{
			ret += bit[ind];
			ind -= (ind&-ind);
		}
		return ret;
	}
	ld sum(int l, int r)
	{
		return sum(r)-sum(l-1);
	}
} id, val;

map<ld, ld> C;
void coco()
{
	set<ld> vals;
	for(int i = 0; i < N; i++)
	{
		vals.insert(a[i]);
		vals.insert(a[i]-2);
		vals.insert(a[i]+2);
	}
	int nxt = 1;
	for(int x : vals)
	{
		C[x]=nxt;
		nxt++;
	}
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	coco();
	ld res = 0;
	for(int i = 0; i < N; i++)
	{
		ld x = val.sum(C[a[i]-2])-id.sum(C[a[i]-2])*a[i];
		ld y = val.sum(C[a[i]+2], 3*MAXN-1)-id.sum(C[a[i]+2], 3*MAXN-1)*a[i];
		res -= x;
		res -= y;
		id.upd(C[a[i]], 1);
		val.upd(C[a[i]], a[i]);
	}
	cout << setprecision(0) << fixed << res << endl;
}