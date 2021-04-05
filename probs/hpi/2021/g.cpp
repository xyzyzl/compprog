#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int> ;
#define f first
#define s second

bool on(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{
	if (q.f <= max(p.f, r.f) && q.f >= min(p.f, r.f) &&
		q.s <= max(p.s, r.s) && q.s >= min(p.s, r.s))
		return true;

	return false;
}

int ort(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{
	int val = (q.s - p.s) * (r.f - q.f) - (q.f - p.f) * (r.s - q.s);
	if (val == 0)
		return 0;
	return (val > 0) ? 1 : 2;
}

int N;
pii A[205];
int main()
{
	cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i].f >> A[i].s;
	int ans = 0;
	for(int i = 0; i < N; i++) for(int j = i+1; j < N; j++) for(int k = j+1; k < N; k++) ans += (ort(A[i], A[j], A[k]) != 0);
	cout << ans << endl;
}
