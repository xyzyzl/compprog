#include <bits/stdc++.h>
#define bitinc(x) (x&-x)

using namespace std;
using ll=long long;
const int MAXN = 100005;

int n, a[MAXN], b[MAXN], c[MAXN];

class node 
{
public:
	vector<int> arr, pl, pr, bit;
	int s, e;
	node* lc;
	node* rc;
	node(int s, int e)
	{
		this->s = s;
		this->e = e;
		arr.resize(e-s+2);
		if(s == e)
		{
			arr[1] = c[s];
		} else {
			int m = (s+e)/2;
			lc = new node(s, m);
			rc = new node(m+1, e);
			pl.resize(lc->arr.size());
			pr.resize(rc->arr.size());
			int lid = 1, rid = 1;
			int id = 1;
			vector<int> larr = lc->arr;
			vector<int> rarr = rc->arr;
			while(lid < larr.size() && rid < rarr.size())
			{
				if(larr[lid] < rarr[rid])
				{
					pl[lid] = id;
					arr[id++] = larr[lid++];
				} else
				{
					pr[rid] = id;
					arr[id++] = rarr[rid++];
				}
			}
			while(lid < larr.size())
			{
				pl[lid] = id;
				arr[id++] = larr[lid++];
			}
			while(rid < rarr.size())
			{
				pr[rid] = id;
				arr[id++] = rarr[rid++];
			}
			bit.resize(e-s+2);
		}
	}
};

int bit[2*MAXN];
int sum(int ind)
{
	int sm = 0;
	while(ind > 0)
	{
		sm += bit[ind];
		ind -= bitinc(ind);
	}
	return sm;
}
void upd(int ind, int val)
{
	while(ind <= n)
	{
		bit[ind] += val;
		ind += bitinc(ind);
	}
}

ll ct_inv()
{
	ll ret=0;
	int mx = 0;
	for(int i = 0; i <= n; i++)
	{
		bit[i] = 0;
	}
	for(int i = n; i > 0; i--)
	{
		ret += sum(c[i]-1);
		upd(c[i], 1);
	}
	return ret;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int k; cin >> k;
		a[k] = i;
	}
	for(int i = 1; i <= n; i++) {
		int k; cin >> k;
		b[k] = i;
		c[a[i]] = b[i];
	}
	ll tot = ct_inv();
}