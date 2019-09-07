#include <bits/stdc++.h>

#define LEFT(x) 2*x
#define RIGHT(x) 2*x+1

#define OTHER 0

#define int long long

using namespace std;

struct Node {
  int sm, mn;
};

int N, M;
vector<Node> tree;
vector<int> lazy;
vector<int> v;

void build(int node, int a, int b) {
  if(a > b) return;
  if(a==b)
  {
    tree[node].sm = v[a];
    tree[node].mn = v[a];
    return;
  }
  int mid = (a+b)/2;
  build(LEFT(node), a, mid);
  build(RIGHT(node), mid+1, b);
  tree[node].sm = tree[LEFT(node)].sm + tree[RIGHT(node)].sm;
  tree[node].mn = min(tree[LEFT(node)].mn, tree[RIGHT(node)].mn);
}

void prop(int node, int a, int b) {
  tree[node].sm += (b-a+1)*lazy[node];
  tree[node].mn += lazy[node];
  if(a != b)
  {
    lazy[LEFT(node)] += lazy[node];
    lazy[RIGHT(node)] += lazy[node];
  }
  lazy[node] = OTHER;
}

void upd(int node, int a, int b, int i, int j, int fl) {
  if(lazy[node] != OTHER)
    prop(node, a, b);
  if(b < i || j < a)
    return;
  if(a >= i && b <= j) {
    tree[node].sm += fl * (b-a+1);
    tree[node].mn += fl;
    if(a != b)
    {
      lazy[LEFT(node)] += fl;
      lazy[RIGHT(node)] += fl;
    }
    return;
  }
  
  int mid = (a+b)/2;
  upd(LEFT(node), a, mid, i, j, fl);
  upd(RIGHT(node), mid+1, b, i, j, fl);

  tree[node].sm = tree[LEFT(node)].sm + tree[RIGHT(node)].sm;
  tree[node].mn = min(tree[LEFT(node)].mn, tree[RIGHT(node)].mn);
}

int rsq(int node, int a, int b, int i, int j) {
  if (lazy[node] != OTHER)
    prop(node, a, b); 
  if(a > b || a > j || b < i) return 0;
  if(a >= i && b <= j) return tree[node].sm;
  
  int mid = (a+b)/2;
  int q1 = rsq(LEFT(node), a, mid, i, j);
  int q2 = rsq(RIGHT(node), mid+1, b, i, j);
  return q1 + q2;
}

int rmq(int node, int a, int b, int i, int j) {
  if (lazy[node] != OTHER)
    prop(node, a, b); 
  if(a > b || a > j || b < i) return INT_MAX-1;
  if(a >= i && b <= j) return tree[node].mn;
  
  int mid = (a+b)/2;
  int q1 = rmq(LEFT(node), a, mid, i, j);
  int q2 = rmq(RIGHT(node), mid+1, b, i, j);
  return min(q1, q2);
}

int32_t main() {
  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);
  cin >> N >> M;
  tree.resize(4*N);
  lazy.assign(4*N, OTHER);
  v.resize(N+5);
  for(int i = 1; i <= N; i++)
  {
    cin >> v[i];
  }
  // cerr << "w" << endl;
  build(1, 1, N);
  int ct = 0;
  for(int i = 0; i < M; i++) {
    char c;
    cin >> c;
    if(c == 'S') {
      int x, y;
      cin >> x >> y;
      cout << rsq(1, 1, N, x, y) << endl;
    } else if(c == 'M') {
      int x, y;
      cin >> x >> y;
      cout << rmq(1, 1, N, x, y) << endl;
    } else {
      int a, b, c;
      cin >> a >> b >> c;
      upd(1, 1, N, a, b, c);
    }
  }
}
