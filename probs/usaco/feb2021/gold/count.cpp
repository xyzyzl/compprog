// Found a grid pattern immediately after reading it
// Managed to solve Subtask 2 at time T=2 hours left
// Tried to but couldn't make progress on the rest
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int q;
ll p3[40], num[40];

// generate for a specific power and offset
void gen(int P, ll off)
{
	off = abs(off);
	if(P == 0)
	{
		num[P] = (off == 0);
	}
	else if(off >= p3[P-1])
	{
		gen(P-1, off-2*p3[P-1]);
		num[P] = num[P-1];
	} else 
	{
		gen(P-1, off);
		num[P] = 3*num[P-1];
	}
}

ll rec(ll x, ll y, int P)
{
	x %= p3[P];
	y %= p3[P];

	if(P == 0) return 1;
	if(x < y) swap(x, y);
	if(x-y >= p3[P-1])
	{
		if(x < 2*p3[P-1]) return 0;
		else if(y < p3[P-1]) return rec(x, y, P-1);
		else return num[P-1];
	}
	if(x < p3[P-1])
	{
		return rec(x, y, P-1);
	}
	if(y < p3[P-1])
	{
		return num[P-1];
	}
	if(x < 2*p3[P-1])
	{
		return num[P-1] + rec(x, y, P-1);
	}
	if(y < 2*p3[P-1])
	{
		return 2*num[P-1];
	}
	return 2*num[P-1]+rec(x, y, P-1);
}

ll diag(ll x, ll y)
{
	if(x < 0 || y < 0) return 0;
	gen(39, x-y);
	return rec(x, y, 39);
}

int main()
{
	cin >> q;
	p3[0] = 1;
	for(int i = 1; i <= 39; i++)
	{
		p3[i] = p3[i-1]*3;
	}
	while(q--)
	{
		ll d, x, y; cin >> d >> x >> y;
		cout << (diag(x+d,y+d)-diag(x-1,y-1)) << endl;
	}
}
