#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;

const int MAXN = 200005;

int n, x[MAXN];
os st;
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		st.insert(i);
		cin >> x[i];
	}
	for(int i = 0; i < n; i++)
	{
		int q; cin >> q;
		--q;
		int pos = *st.find_by_order(q);
		st.erase(pos);
		cout << x[pos] << ' ';
	}
	cout << endl;
}