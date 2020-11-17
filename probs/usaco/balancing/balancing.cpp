#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef pair<int,int> pii;
#define f first
#define s second

int n;
pii a[100005];

vector<int> find_y(int x)
{
	int sm = 0, top = n-1, ind = 0;
	vector<int> C(n), ret;
	for(int i = 0; i < n; i++)
	{
		while(ind < n && a[ind].f == i)
		{
			int y = a[ind].s;
			C[y]++;
			if(y <= top) sm++;
			ind++;
		}
		while(sm > x) sm -= C[top--];
		ret.push_back(top);
	}
	return ret; // returns the highest satisfying y-value for each x-value starting from left
}
// really need to find lowest/highest y starting from the left/right.

int main()
{
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].f >> a[i].s;
	}
	{
		map<int, int> k;
		int c = 0;
		for(int i = 0; i < n; i++) k[a[i].f] = 0;
		for(pii i : k) k[i.f] = c++;
		for(int i = 0; i < n; i++) a[i].f = k[a[i].f];
	}
	{
		map<int, int> k;
		int c = 0;
		for(int i = 0; i < n; i++) k[a[i].s] = 0;
		for(pii i : k) k[i.f] = c++;
		for(int i = 0; i < n; i++) a[i].s = k[a[i].s];
	}
	sort(a, a+n);
	int lo=1, hi=n;
	while(lo != hi)
	{
		int mid = (lo+hi)/2;
		// cerr << mid << endl;
		vector<int> p = find_y(mid);
		// for(int x : p) cerr << x << ' ';
		// cerr << endl;
		for(int i = 0; i < n; i++) a[i].s = n-1-a[i].s;
		vector<int> q = find_y(mid);
		// for(int x : q) cerr << x << ' ';	
		// cerr << endl;
		reverse(a,a+n);
		for(int i = 0; i < n; i++) a[i].s = n-1-a[i].s;
		for(int i = 0; i < n; i++) a[i].f = n-1-a[i].f;
		vector<int> r = find_y(mid);
		// for(int x : r) cerr << x << ' ';	
		// cerr << endl;
		for(int i = 0; i < n; i++) a[i].s = n-1-a[i].s;
		vector<int> t = find_y(mid);
		// for(int x : t) cerr << x << ' ';	
		reverse(a,a+n);
		for(int i = 0; i < n; i++) a[i].s = n-1-a[i].s;
		for(int i = 0; i < n; i++) a[i].f = n-1-a[i].f;
		// cerr << endl;
		// cerr << endl;

		bool ok = 0;
		for(int i = 0; i < n-1; i++)
		{
			if(min(p[i], r[n-2-i])+1 + min(q[i], t[n-2-i])+1 >= n) ok=1;
		}	
		if(ok) hi = mid;
		else lo = mid+1;
	}
	cout << lo << endl;
}