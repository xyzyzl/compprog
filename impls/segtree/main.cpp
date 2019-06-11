#include <bits/stdc++.h>

using namespace std;

#define LEFT(x) 2*x
#define RIGHT(x) 2*x+1

#define INF 0x7fffffff

int st[200005];

struct Node {
    int l, r, mx, sz;
};

int N, M;
vector<Node> tree;
vector<int> lazy;

void build(int node, int a, int b) {
    tree[node].l=tree[node].r=tree[node].mx=tree[node].sz=b-a+1;
    if(a != b) {
        int mid = (a+b)/2;
        build(LEFT(node), a, mid);
        build(RIGHT(node), mid+1, b);
    }
}

void upd(int node, int a, int b, int i, int j, int value)
{
    if(a > b || a > j || b < i) return;
    if(a == b)
    {
        tree[node] += value;
        return;
    }

    upd(LEFT(node), a, (a+b)/2, i, j, value);
    upd(RIGHT(node), (a+b)/2+1, b, i, j, value);
    st[node] = max(st[LEFT(node)], st[RIGHT(node)]);
}

int rmq(int node, int a, int b, int i, int j)
{
    if(a > b || a > j || b < i) return -INF;
    if(a >= i && b <= j) return st[node];

    int q1 = rmq(LEFT(node), a, (a+b)/2, i, j);
    int q2 = rmq(RIGHT(node), (a+b)/2+1, b, i, j);
    return max(q1, q2); // this operation will change if it becomes something else
}

int main()
{
    return 0;
}