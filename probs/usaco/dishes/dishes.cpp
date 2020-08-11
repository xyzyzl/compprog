#include <bits/stdc++.h>

using namespace std;

int n, stk[100005], b_stk[100005];
vector<int> soap[100005];
bool ok(int m)
{
	for(int i = 0; i < n; i++)
	{
		b_stk[i] = 0;
		soap[i].clear();
	}
	int first_ok = 0;
	for(int i = 0; i < m; i++)
	{
		if(stk[i] < first_ok) return 0;
		// which stack each dish will end up going to is
		// fixed.
		for(int j = stk[i]; j >= 0; j--)
		{
			if(b_stk[j]) break;
			b_stk[j] = stk[i];
		}
		// now insert this dish into the correct stack
		// and remove everything in the stack above this
		// dish. all previous stacks will also be removed
		// in theory (but not in fact because that's slow).
		while(!soap[b_stk[stk[i]]].empty() && soap[b_stk[stk[i]]].back() < stk[i])
		{
			first_ok = soap[b_stk[stk[i]]].back();
			soap[b_stk[stk[i]]].pop_back();
		}
		soap[b_stk[stk[i]]].push_back(stk[i]);
	}
	return 1;
}

int main()
{
	freopen("dishes.in", "r", stdin );
	freopen("dishes.out","w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> stk[i];
	// bsearch for answer
	int lo = 1, hi = n;
	while(lo < hi - 1)
	{
		int mid = (lo+hi)/2;
		if(ok(mid)) lo = mid;
		else hi = mid-1;
	}
	cout << (ok(hi) ? hi : lo) << endl;
}
