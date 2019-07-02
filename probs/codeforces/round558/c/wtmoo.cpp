/**
ID: albert.28
LANG: C++14
PROB: poetry
**/

/// Time:

#include <bits/stdc++.h>

/**
Mod operations in O(lg n)
Source: Benjamin Qi, https://github.com/bqi343/USACO/blob/master/Implementations/11%20-20(4)/Operators/modOp.cpp?fbclid=IwAR0m2afS-1xVg9kgeF8q8EJIeP9TP3Lct8dYb_hPJuI5gqHP1Utp5EkiOQ8
**/

using namespace std;

#define MAXN 2500
#define MOD 1000000007

#define FOR(g,i,n) for(int i = g; i < n; i++)
#define FORD(g,i,n) for(int i = g; i >= n; i--)

#define apple() ios_base::sync_with_stdio(0)
#define hentai() cin.tie(); cout.tie()

#define mp make_pair
#define pb push_back
#define	ll long long
// #define int ll
#define INF (1e9*1)+5
#define LL_INF (1e18*1)+5
#define bitinc(s) (s&-s)
#define endl '\n'

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mi;
#define f first
#define s second
typedef vector<pii> vii;
typedef set<pii> sii;
typedef map<pii, pii> mii;

void fileio(char* in, char* out)
{
	freopen(in, "r", stdin);
	freopen(out, "w", stdout);
}

namespace modOp
{
    int ad(int a, int b, int mod = MOD) { return (a+b)%mod; }
    int sub(int a, int b, int mod = MOD) { return (a-b+mod)%mod; }
    int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }

    int AD(int& a, int b, int mod = MOD) { return a = ad(a,b,mod); }
    int SUB(int& a, int b, int mod = MOD) { return a = sub(a,b,mod); }
    int MUL(int& a, int b, int mod = MOD) { return a = mul(a,b,mod); }

    int po (int b, int p, int mod = MOD) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }
    int inv (int b, int mod = MOD) { return po(b,mod-2,mod); }

    int invGeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
        if (a == 0) return b == 1 ? 0 : -1;
        int x = invGeneral(b%a,a);
        return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
    }
}

using namespace modOp;

typedef pair<pii, pii> line;

int orientation(pii x, pii y, pii z)
{
	/// -1 = ccw, 0 = collinear, 1 = cw
	int val = (y.s-x.s)*(z.f-y.f) - (y.f-x.f)*(z.s-y.s);
	if(val == 0) return 0;
	return val > 0 ? 1 : -1;
}

bool cool(pii p, pii q, pii r)
{
	if (q.f <= max(p.f, r.f) && q.f >= min(p.f, r.f) && q.s <= max(p.s, r.s) && q.s >= min(p.s, r.s)) return 1;
	return 0;
}

bool intersect(line x, line y)
{
	int o1 = orientation(x.f, x.s, y.f);
	int o2 = orientation(x.f, x.s, y.s);
	int o3 = orientation(y.f, y.f, x.f);
	int o4 = orientation(y.f, y.s, x.f);

	if(o1 != o2 && o3 != o4) return 1;

	/*
	if(o1 == 0 && cool(x.f, y.f, x.s)) return 1;
	if(o2 == 0 && cool(x.f, y.s, x.s)) return 1;
	if(o3 == 0 && cool(y.f, x.f, y.s)) return 1;
	if(o4 == 0 && cool(y.f, x.s, y.s)) return 1;
	*/
	return  0;
}

int n, m;
vii poles;
vector<line> A;
void printdebug(int i, int j)
{
	cout << "----" << endl;
	cout << "Line 1 s: " << A[i].f.f << " " << A[i].f.s << endl;
	cout << "Line 1 e: " << A[i].s.f << " " << A[i].s.s << endl;
	cout << "Line 2 s: " << A[j].f.f << " " << A[j].f.s << endl;
	cout << "Line 2 e: " << A[j].s.f << " " << A[j].s.s << endl;
	cout << "----" << endl;
}
int main()
{
	cin >> n;
	FOR(0, i, n)
	{
		int x1, x2;
		cin >> x1 >> x2;
		poles.pb(mp(x1, x2));
	}
	sort(poles.begin(), poles.end());
	FOR(0, i, n) FOR(i+1, j, n)
	{
		A.pb(mp(poles[i], poles[j]));
	}
	m = A.size();
	int ct = 0;
	FOR(0, i, m)
	{
		FOR(i+1, j, m)
		{
			bool a = intersect(A[i], A[j]);
			printdebug(i, j);
			cout << "Intersects: " << (a ? "Yes" : "No") << endl	;
			ct += a;
		}
	}
	cout << ct << endl;
}
