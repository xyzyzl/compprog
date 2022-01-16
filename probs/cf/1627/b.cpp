#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 200005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define F1R(i, n) for (int i = 1; i <= n; i++)
#define F1RD(i, n) for (int i = n; i >= 1; i--)
#define pb push_back
#define mp make_pair
#define ins insert
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define ll long long
#define MOD ((1e9*1)+7)
#define MOD2 998244353
#define INF (1e9*1)+5

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef vector<iii> viii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;

typedef set<ll> sl;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> lll;
typedef vector<pll> vll;
typedef vector<lll> vlll;
typedef priority_queue<ll> pql;
typedef stack<ll> stl;
typedef queue<ll> ql;
typedef deque<ll> dl;
typedef map<ll, ll> mll;

// ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> osii;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> osll;
#define f first
#define s second

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

#define bitinc(x) x&-x

const int MAX(int &a, int b)
{
	return a = max(a, b); 
}
const int MIN(int &a, int b)
{
	return a = min(a, b); 
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve()
{
    int n, m; cin >> n >> m;
    vector<vi> v(n, vi(m, 1e8));
    vector<vi> vs(n, vi(m));
    queue<pair<int, int> > q;
    q.push({n/2, m/2});
    if(n%2) q.push({(n-1)/2, m/2});
    if(m%2) q.push({n/2, (m-1)/2});
    if(n%2 && m&2) q.push({(n-1)/2, (m-1)/2});
    v[n/2][m/2] = v[(n-1)/2][m/2] = v[n/2][(m-1)/2] = v[(n-1)/2][(m-1)/2] = n/2+m/2;
    while(!q.empty())
    {
        pii tp = q.front();
        q.pop();
        int i = tp.f, j = tp.s;
        if(vs[i][j])
        {
            continue;
        }
        vs[i][j] = 1;
        FOR(w, 4)
        {
            if(i+dx[w] < 0 || i+dx[w] >= n || j+dy[w] < 0 || j+dy[w] >= m) continue;
            if(vs[i+dx[w]][j+dy[w]]) continue;
            v[i+dx[w]][j+dy[w]] = min(v[i+dx[w]][j+dy[w]], v[i][j] + 1);
            q.push({i+dx[w], j+dy[w]});
        }
    }
    vi u; FOR(i, n) FOR(j, m) u.pb(v[i][j]);
    sort(u.begin(), u.end());
    FOR(i, n*m) cout << u[i] << " ";
    cout << endl;
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}

/**
 * Hey, did you know that in terms of male human and female Pokémon breeding, Vaporeon
 * is actually not the most compatible Pokémon for humans?
 * This is a common and understandable misconception, however Vaporeon has it's human on Pokémon
 * breedability outclassed by it's cousin evolution, Umbreon.
 * Umbreon weights approximately 60 pounds, or around 27 kilograms, and is 3'3" tall (About a meter), 
 * making it not only large enough to appropriately handle human genitalia, but also light enough to
 * easily be lifted, and promptly set back down repeatedly. 
 * It's relatively small size would also prove a tight entry, which is always a good thing.
 * Umbreon also boasts an extremely impressive defensive stat spread.
 * With it's combination of very high HP, Defense, and Special Defense stats,
 * it can take a great pounding and come back for more! It's ability, Inner Focus,
 * allows it to keep slamming attentively, without getting fatigued. Umbreon also
 * has access to the ability Synchronize, which allows it to share it's current
 * status with you, meaning you will receive all of the pleasure it feels COMBINED with all
 * the pleasure you're getting from pounding this perfect breedable Pokémon. Umbreon also
 * has the capability of seeing perfectly in pitch-black darkness, allowing it to effectively
 * attend a midnight fornication session. Even if you do manage to drain Umbreon's energy with
 * all the furious thrusts, it can recover very quickly with its access to the move Moonlight.
 * Its black fur is also a giant positive attribute, allowing all the excretions you make to
 * be easily seen all over its body. A great fun fact, Umbreon can excrete toxins in its sweat,
 * which would in turn soak into your member and swell it up, making it even more sizable and
 * sensitive. This would not only enhance the experience for you, but for your Umbreon as well
 * (Which with Synchronize, ends up pleasing you exponentially more). Umbreon's wide movepool
 * also supports the hypothesis that Umbreon is the best Pokémon to breed with. It can learn
 * Payback, which doubles in power after the Pokémon is hit, meaning Umbreon with throw it back
 * twice as hard as normally if you're hitting it good. Umbreon can also learn Guard Swap; it could
 * give YOU its insane durability, and go crazy on you all night with your now massive endurance.
 * Speaking of endurance, Umbreon also has access to Endure, making it practically immune to fatigue,
 * it will always have energy left over. Charm is also within Umbreon's movepool, letting it be extremely
 * seductive towards you, easily getting you in the mood. Umbreon can also use Taunt, in turn making you
 * ONLY able to to attacking moves such as Slam, Pound, etc; none of that foreplay shit, right into the
 * action. It also has access to Sleep Talk, giving it the ability to not only give consent in its sleep,
 * allowing access to any of its ports and any time, but also move in it's sleep, making it an effective
 * 24/7 fuckmate. Umbreon still has even more great moves that good to have while smashing, such as Quick
 * Attack, allowing swift slams and bounces, which can have even greater power if Umbreon uses Curse
 * beforehand. Curse would also raise Umbreon's defense, making it able to take powerful thrusting for
 * almost any duration. Looking back, Umbreon's slightly small size ensures a gorilla grip cavity and
 * easy physical manipulation. Its ungodly bulk allows it to take poundings for hours on end and resume
 * after recovering with moonlight (Which works even better when it's sunny). It's access to the abilities
 * Inner Focus and Synchronize allow it to unwaveringly throw it back and add all of its pleasure onto
 * yours, effectively making it twice as amazing as any other Pokémon, or even FOUR TIMES, factoring in
 * the doubled power of payback of course. All of this information in combination with its extremely useful
 * movepool in the world of intercourse makes Umbreon the Pokémon most qualified to breed with humans;
 * able to take dick of any shape, any size, in any position easily for extensive periods of time, while
 * having the ability to return for even more mere seconds later.
 */
