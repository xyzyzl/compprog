// OMG WORKS！!!!!!!!!!!
#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;

#define int long long

#define LEFT(x) 2*x
#define RIGHT(x) 2*x+1
 
#define INF 0x7fffffff
 
int st[800069], arr[200005], n, q;
 
int lf[200069], rt[200069];
 
void build(int node, int a, int b) {
	if (a > b) return;
	if (a == b) {
		st[node] = arr[a];
		return;
	}
	build(LEFT(node), a, (a + b) / 2);
	build(RIGHT(node), (a + b) / 2 + 1, b);
 
	st[node] = st[LEFT(node)]+st[RIGHT(node)];
}
 
int rmq(int node, int a, int b, int i, int j) {
	if (a > b || a > j || b < i) return 0;
	if (a >= i && b <= j) return st[node];
 
	int q1 = rmq(LEFT(node), a, (a + b) / 2, i, j);
	int q2 = rmq(RIGHT(node), (a + b) / 2 + 1, b, i, j);
	return q1+q2; // this operation will change if it becomes something else
}
 
int freq[200069];
int bad_arr[100005];
 
signed main() {
	// freopen("moo.txt", "r", stdin);
	// freopen("output.out", "w", stdout);
	// n=100000;
	bool t=1;
	while (t==1) {
		cin >> n >> q;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> arr[i];
		}
 
		build(1, 0, n - 1);
		// cout << q << endl;
		for (int i = 0; i < q; i++) {
			int l, r;
			cin >> l >> r;
			l--;
			r--;
 
			int d1 = 0;
			int d2 = 0;
			cout << rmq(1, 0, n - 1, l + d1, r - d2) << endl;
		}
		t=0;
	}
	// cout << "terminates" << endl;
	return 0;
}