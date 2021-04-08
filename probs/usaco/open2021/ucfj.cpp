#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long

const int MAXN = 200005;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> os;

int N, b[MAXN], lps[MAXN];
os lpos;
signed main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> b[i];
	}
	lps[b[1]] = 1;
	lpos.insert({1, b[1]});
	long long ans = 0;
	for(int i = 2; i <= N; i++)
	{
		if(!lps[b[i]])
		{
			lps[b[i]] = i;
			ans += lpos.size();
			lpos.insert({i, b[i]});
		} else 
		{
			int k = lpos.order_of_key({lps[b[i]], b[i]});
			int fq = lpos.size()-k-1;
			ans += fq;
			lpos.erase({lps[b[i]], b[i]});
			lps[b[i]] = i;
			lpos.insert({lps[b[i]], b[i]});
		}
	}
	cout << ans << endl;
}