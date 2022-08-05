#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define x second
#define y first
#define point pair<long long, long long>
using namespace __gnu_pbds;
#define ordered_set tree<point, null_type,less<point>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;

struct line {
  point p1,p2;
  long long type; // 0: sort by first, 1: sort by second, 2: sort by first(vertical);
  line(point p1, point p2, int type) : 
  p1(p1), p2(p2), type(type) {};
};
bool compare(line a, line b) { 
  // sort by x
  return a.p1.x < b.p1.x; 
}

long long output = 0;
ordered_set s;
void getI(vector<line> lines) {
  for (line thing : lines) {
    if (thing.type == 0) s.insert(thing.p1);
    else if (thing.type == 1) if(s.find(thing.p2) != s.end()) s.erase(thing.p2);
    else {
      if (thing.p2.y > thing.p1.y) {
        output += s.order_of_key(mp(thing.p2.y + 1, 0)) - s.order_of_key(mp(thing.p1.y, 0));
      } else {
        output += s.order_of_key(mp(thing.p1.y + 1, 0)) - s.order_of_key(mp(thing.p2.y, 0));
      }
    }
  }
}
int main () {
  long long n, in;
  vector<line> lines;
  cin >> n;
  long long x1, y1, x2, y2;

  for (int i = 0; i < n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    if(y1 == y2) { // horizontal
      lines.push_back(line(mp(y1, x1), mp(y2, x2), 0));
      lines.push_back(line(mp(y2, x2), mp(y1, x1), 1));
      in += 2;
    }
    else { // vertical
      lines.push_back(line(mp(y1,x1), mp(y2,x2), 2));
      in++;
    }
  }
  sort(lines.begin(), lines.end(), compare);
  getI(lines);
  cout << output;
  return 0;
}