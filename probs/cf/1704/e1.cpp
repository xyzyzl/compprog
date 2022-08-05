#include<bits/stdc++.h>
using namespace std;
const int N = 500005, inf = 2147483647, M = 998244353;
int n, m, a[N], u, v, i, d[N], q[N], r, mx;
int b[N], tmp[N];
vector<int> g[N], z[N];
long long s[N];
int p[15];
void NEX(int M) {
	for (int i = 1; i <= n; ++i)
		if (b[i]) {
			tmp[i] += b[i] - 1;
			for (auto it : g[i])
			{
				cerr << it << endl;
				++tmp[it];
			}
		}
	for (int i = 1; i <= n; ++i) {
		if (tmp[i] >= M)
			b[i] = tmp[i] % M + M;
		else
			b[i] = tmp[i] % M;
		tmp[i] = 0;
	}
}
int cal(int M) {
	for (int i = 1; i <= n; ++i) {
		b[i] = a[i];
	}
	for (int i = 1; i <= n; ++i) {
		bool fl = false;
		for (int j = 1; j <= n; ++j)
			if (b[j])
				fl = true;
		if (!fl)
			return i - 1;
		NEX(M);
	}
	return n;
}
int main() {
	freopen("e.in","r",stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			g[i].clear();
			z[i].clear();
			d[i] = 0;
			tmp[i] = 0;
			s[i] = 0;
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%d %d", &u, &v);
			++d[u];
			g[u].push_back(v);
			z[v].push_back(u);
		}
		mx = cal(M);
		for(int i = 1; i <= n; i++)
		{
			cerr << b[i] << " ";
		}
		cerr << endl;
		if (mx < n) {
			cout << mx << endl;
			continue;
		}
		r = 0;
		for (int i = 1; i <= n; ++i)
			if (!d[i])
				q[++r] = i;
		s[q[1]] = 1;
		for (int i = 1; i <= r; ++i) {
			s[q[i]] %= M;
			for (auto it : z[q[i]]) {
				--d[it];
				s[it] += s[q[i]];
				if (!d[it])
					q[++r] = it;
			}
		}
		long long ans = n;
		for (int i = 1; i <= n; ++i)
			ans = (ans + s[i] * b[i]) % M;
		cout << ans << endl;
	}
}