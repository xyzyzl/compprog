#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std; 

const int MAXN = 200005;
const int INF = 1e9+7;

typedef pair<int, int> pii;
#define f first
#define s second
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> os;

int n, q, cst[MAXN];
os ost;
int main()
{
	cin >> n >> q;
	for(int i = 0; i < n; i++)
	{
		cin >> cst[i];
		ost.insert({cst[i], i});
	}
	for(int i = 0; i < q; i++)
	{
		char tp; int a, b; cin >> tp >> a >> b;
		if(tp == '!')
		{
			--a;
			ost.erase({cst[a], a});
			cst[a] = b;
			ost.insert({cst[a], a});
		} else 
		{
			cout << ost.order_of_key({b, INF}) - ost.order_of_key({a, -INF}) << endl;
		}
	}
}
