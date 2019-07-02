/**
ID: albert.28
LANG: C++14
PROB: labyrinth
**/

/// Time: 44:20

#include <bits/stdc++.h>

/**
Mod operations in O(lg n)
Source: Benjamin Qi, https://github.com/bqi343/USACO/blob/master/Implementations/11%20-20(4)/Operators/modOp.cpp?fbclid=IwAR0m2afS-1xVg9kgeF8q8EJIeP9TP3Lct8dYb_hPJuI5gqHP1Utp5EkiOQ8
**/

using namespace std;

#define MAXN 1005
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

int n, m, level[MAXN][MAXN], dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}; // D, R, U, L
bool grid[MAXN][MAXN];
pii st, en, parent[MAXN][MAXN];
int main()
{
	apple();
	hentai();
	cin >> n >> m;
	FOR(0, i, n) FOR(0, j, m)
	{
		char c;
		cin >> c;
		if(c=='#') grid[i][j] = 0;
		else if(c == '.') grid[i][j] = 1;
		else if(c == 'A')
		{
			grid[i][j] = 1;
			st = mp(i, j);
		} else
		{
			grid[i][j] = 1;
			en = mp(i, j);
		}
	}
	queue<pii> q;
	q.push(st);
	parent[st.f][st.s] = mp(-1, -1);
	level[st.f][st.s] = 1;
	bool found = 0;
	while(!q.empty())
	{
		pii fr = q.front();
		if(fr.f == en.f && fr.s == en.s)
		{
			found = 1;
			break;
		}
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			if(!grid[fr.f + dx[i]][fr.s + dy[i]] || level[fr.f + dx[i]][fr.s + dy[i]]) continue; // it's a wall and you can't pass
			q.push(mp(fr.f + dx[i], fr.s + dy[i]));
			parent[fr.f + dx[i]][fr.s + dy[i]] = fr;
			level[fr.f + dx[i]][fr.s + dy[i]] = level[fr.f][fr.s] + 1;
		}
	}
	if(found)
	{
		cout << "YES" << endl;
		cout << level[en.f][en.s]-1 << endl;
		pii idx=en;
		vector<char> tt;

		while(idx.f != st.f || idx.s != st.s)
		{
			pii par = parent[idx.f][idx.s];
			if(idx.f != par.f)
			{
				if(idx.f-par.f > 0) tt.pb('D');
				else tt.pb('U');
			} else
			{
				if(idx.s-par.s > 0) tt.pb('R');
				else tt.pb('L');
			}
			idx = par;
			// cout << idx.f << " " << idx.s << " " << st.f << " " << st.s << endl;
		}

		reverse(tt.begin(), tt.end());
		for(char c : tt) cout << c;
		cout << endl;
	} else cout << "NO" << endl;
}
