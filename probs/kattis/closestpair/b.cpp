#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
#define f first
#define s second
#define ll long long
#define mp make_pair
using namespace std;
// i have already been diagnosed with skill issue three times

double dist(pair<ll, ll> a, pair<ll, ll> b) {
  return sqrt(pow(abs(b.f - a.f), 2) + pow(abs(b.s - a.s), 2));
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  pair<ll, ll> arr[n];
  set<pair<ll, ll> > ptsY;
  for(int i = 0; i < n; ++i) {
    cin >> arr[i].f >> arr[i].s;
  }
  sort(arr, arr + n);
  double d = 1e6, cur = 0;
  for(int i = 1; i < n; ++i) {
    ptsY.insert(mp(arr[i - 1].s, arr[i - 1].f));
    for(int j = 0; j < lower_bound(arr, arr + n, arr[i].f - d) - arr; ++j) {
      ptsY.erase(mp(arr[j].s, arr[j].f));
    }
    for(set<pair<ll, ll> >::iterator it = ptsY.lower_bound(mp((ll)(arr[i].s - d), -1e6)); it != ptsY.upper_bound(mp((ll)(arr[i].s + d), 1e6)); ++it) {
      cur = dist(mp(it->s, it->f), arr[i]);
      if(d > cur) d = cur;
    }
  }
  cout << d << "\n";
}