#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

#define LEFT(x) 2*x
#define RIGHT(x) 2*x+1

#define INF 0x7fffffff

int st[200069], arr[100005], n, q;

int lf[200069], rt[200069];

void build(int node, int a, int b) {
	if (a > b) return;
	if (a == b) {
		st[node] = arr[a];
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

int freq[200069];
int bad_arr[100005];

int main() {
	freopen("moo.txt", "r", stdin);
	// freopen("output.out", "w", stdout);
	int jjjjjj;
	cin >> jjjjjj;
	cout << jjjjjj << endl;
	return 0;
	while (1) {
		// cout << n << " w" << endl;
		cin >> n;
		// cout << n << " w" << endl;
		if(n==0) return 0;
		// fill(arr, arr + 100005, 0);
		// fill(freq, freq+200069, 0);
		for(int i = 0; i < 200069; i++) freq[i]=0;
		// fill(lf, lf+200069, 0);
		// fill(rt, rt+200069, 0);
		// fill(lf, lf + 100005, 0);
		// fill(rt, rt + 100005, 0);
		// fill(st, st + 200005, 0);
		cin >> q;
		cout << q << " drunk compiler" << endl;
		// cout << "m" << endl;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			cerr << a << endl;
			bad_arr[i] = a;
			bad_arr[i]+=100020;
			// cerr << bad_arr[i] << endl;
			freq[bad_arr[i]]++;
		}
		for (int i = 0; i < n; i++) arr[i] = freq[bad_arr[i]];
		// cout << "array" << endl;
		// for (int i = 0; i < n; i++) cout << arr[i] << endl;
		// cout << "array" << endl;
		lf[bad_arr[0]] = 0;
		for (int i = 1; i < n; i++) {
			if (bad_arr[i] != bad_arr[i - 1]) {
				rt[bad_arr[i - 1]] = i - 1;
				lf[bad_arr[i]] = i;
			}
		}
		rt[bad_arr[n - 1]] = n - 1;

		build(1, 0, n - 1);
		// cout << q << endl;
		for (int i = 0; i < q; i++) {
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			if (bad_arr[l] == bad_arr[r]) {
				// cout << "this should be happening ";
				cout << r - l + 1 << endl;
				// cout << "this should continue the for loop unless compiler is intoxicated" << endl;
				continue;
			}

			int d1 = 0;
			if (l <= rt[bad_arr[l]] && l != lf[bad_arr[l]]) d1 = rt[bad_arr[l]] - l + 1;
			// cout << d1 << " d1" << endl;
			int d2 = 0;
			if (r >= lf[bad_arr[r]] && r != rt[bad_arr[r]]) d2 = r - lf[bad_arr[r]] + 1;
			// cout << d2 << " d2" << endl;

			int better = max(d1, d2);
			// cout << rt[-100] << endl;
			cout << max(better, rmq(1, 0, n - 1, l + d1, r - d2)) << endl;
		}
	}
	// cout << "terminates" << endl;
	return 0;
}
