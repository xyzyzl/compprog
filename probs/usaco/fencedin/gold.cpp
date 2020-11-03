#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

typedef pair<int, int> ii;
#define ff first
#define ss second

int A, B, n, m;
int V, E;

class UnionFind
{
private:
    vector<int> p;

public:
    UnionFind(int N)
    {
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    bool unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            int a = findSet(i), b = findSet(j);
            if (a > b)
            {
                swap(a, b);
            }
            p[a] = b;
            return 1;
        }
        else
            return 0;
    }
};

int p[2005 * 2005];

int find_set(int i)
{
    return (p[i] == i) ? i : (p[i] = find_set(p[i]));
}

bool union_set(int i, int j)
{
    int x = find_set(i);
    int y = find_set(j);
    if (x == y)
        return false;
    p[x] = p[y] = p[i] = p[j] = x;
    return true;
}

int mv(int r, int c)
{
    return r * m + c;
}

vector<int> a, b, pa, pb;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    cin >> A >> B >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    a.push_back(0);
    a.push_back(B);
    sort(a.begin(), a.end());
    pa.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        pa[i] = a[i + 1] - a[i];
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    b.push_back(0);
    b.push_back(A);
    sort(b.begin(), b.end());
    pb.resize(m + 1);
    for (int i = 0; i <= m; i++)
    {
        pb[i] = b[i + 1] - b[i];
    }
    // cout << pa[n] << endl;
    n++;
    m++;

    a.clear();
    b.clear();

    sort(pa.begin(), pa.end());
    sort(pb.begin(), pb.end());

    V = (n) * (m);

    for (int i = 0; i < V; i++)
        p[i] = i;

    long long cost = 0;
    for (int i = 0, j = 0; i < n || j < m;)
    {
        // cerr << pa[i] << " " << pb[j] << endl;
        if (j == m || (i < n && pa[i] < pb[j]))
        {
            for (int s = 0; s < m - 1; s++)
            {
                if (union_set(mv(i, s), mv(i, s + 1)))
                {
                    // cerr << pa[i] << endl;
                    cost += pa[i];
                }
            }
            i++;
        }
        else
        {
            for (int s = 0; s < n - 1; s++)
            {
                // cerr << "here" << endl;
                if (union_set(mv(s, j), mv(s + 1, j)))
                {
                    cost += pb[j];
                }
            }
            j++;
        }
    }
    cout << cost << endl;
}