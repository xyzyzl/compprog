/*input
28
VOTEFORTHEGREATALBANIAFORYOU
CHOOSETHEGREATALBANIANFUTURE
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int INF = 1e9+7;

#define LEFT(x) (2*x)
#define RIGHT(x) (2*x+1)

int n, m, st[4*MAXN];
vector<int> sa, isa, lcp;
string s;

void build(int node, int a, int b) {
	if (a > b) return;
	if (a == b) {
		st[node] = lcp[a];
		return;
	}
	build(LEFT(node), a, (a + b) / 2);
	build(RIGHT(node), (a + b) / 2 + 1, b);

	st[node] = max(st[LEFT(node)], st[RIGHT(node)]);
}

int rmq(int node, int a, int b, int i, int j) {
	if (a > b || a > j || b < i) return -INF;
	if (a >= i && b <= j) return st[node];

	int q1 = rmq(LEFT(node), a, (a + b) / 2, i, j);
	int q2 = rmq(RIGHT(node), (a + b) / 2 + 1, b, i, j);
	return max(q1, q2); // this operation will change if it becomes something else
}

void gensa()
{
	sa.resize(n);
	isa.resize(n);
	sa[0] = n-1;
	iota(sa.begin()+1, sa.end(), 0);
	sort(sa.begin()+1, sa.end(), [&](int a, int b) { return s[a]<s[b]; });
	for(int i = 1; i < n; i++)
	{
		int a = sa[i-1], b = sa[i];
		isa[b] = (i > 1 && s[a] == s[b]) ? isa[a] : i;
	}
	for(int l = 1; l < n; l*=2)
	{
		vector<int> sa_(sa), isa_(isa), pos(n); iota(pos.begin(), pos.end(), 0);
		for(int t : sa_)
		{
			int t_ = t-l;
			if(t_ >= 0) sa[pos[isa[t_]]++] = t_;
		}
		for(int i = 1; i < n; i++)
		{
			int a = sa[i-1], b = sa[i];
			isa[b] = (isa_[a] == isa_[b] && isa_[a+l] == isa_[b+l]) ? isa[a] : i;
		}
	}
}

void genlcp()
{
	lcp.resize(n-1);
	int h = 0;
	for(int b = 0; b < n-1; b++)
	{
		int a = sa[isa[b]-1];
		while(a+h < s.length() && s[a+h]==s[b+h]) h++;
		lcp[isa[b]-1] = h;
		if(h)
			h--;
	}
	build(1, 0, lcp.size()-1);
}

int getlcp(int a, int b) 
{
	if(a == b) return s.length()-a;
	int l = isa[a], r = isa[b];
	if(l > r)
		swap(l,r);
	return rmq(1, 0, lcp.size()-1, l, r);
}

int main()
{
	cin >> n;
	m=n;
	string a, b;
	cin >> a >> b;
	s = a+"!"+b;
	// now need to find the suffix array
	n = 1+s.length();
	gensa();
	genlcp();
	for(int i = 0; i < n; i++) cout << sa[i] << " ";
	cout << endl;

	int sta=0, l=0;
	for(int i = 1; i < n; i++)
	{
		// must be divided
		if((sa[i]<m && sa[i-1]>m) || (sa[i]>m && sa[i-1]<m))
		{
			if(lcp[i] > l)
			{
				sta = sa[i];
				l = lcp[i];
			}
		}
	}
	for(int i = sta; i < sta+l; i++) cout << s[i];
	cout << endl;
}