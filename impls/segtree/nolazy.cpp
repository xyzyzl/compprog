#include <bits/stdc++.h>

using namespace std;

#define LEFT(x) 2*x
#define RIGHT(x) 2*x+1

#define INF 0x7fffffff

int st[400005], arr[100005];
int N, M;

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

void upd(int node, int a, int b, int x, int value)
{
    if(a == b)
    {
        st[node] = value;
        return;
    }

    if(x <= (a+b)/2) upd(LEFT(node), a, (a+b)/2, x, value);
    else upd(RIGHT(node), (a+b)/2+1, b, x, value);
    st[node] = max(st[LEFT(node)], st[RIGHT(node)]);
}

int main()
{
    return 0;
}