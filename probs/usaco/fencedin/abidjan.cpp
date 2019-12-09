#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

typedef pair<int, int> ii;
#define ff first
#define ss second

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
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            int a = findSet(i), b = findSet(j);
            if (a > b)
            {
                swap(a, b);
            }
            p[a] = b;
        }
    }
};

int A, B, n, m;
int V, E;
int mv(int r, int c)
{
    return r * (n + 1) + c;
}

vector<int> a, b, pa, pb;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    vector<pair<int, ii>> edges;

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

    a.clear();
    b.clear();
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            // cout << mv(i, j) << endl;
            if (i > 0)
                edges.push_back(make_pair(pa[j], make_pair(mv(i, j), mv(i - 1, j))));
            if (i > 0)
                edges.push_back(make_pair(pa[j], make_pair(mv(i - 1, j), mv(i, j))));
            if (j > 0)
                edges.push_back(make_pair(pb[i], make_pair(mv(i, j), mv(i, j - 1))));
            if (j > 0)
                edges.push_back(make_pair(pb[i], make_pair(mv(i, j - 1), mv(i, j))));
        }
    }

    // cout << mv(2,5) << endl;

    // cout << "aa" << endl;
    V = (n + 1) * (m + 1);

    E = edges.size();
    sort(edges.begin(), edges.end());

    UnionFind uf(V);
    long long cost = 0;
    for (int i = 0; i < E; i++)
    {
        pair<int, ii> fr = edges[i];
        if (!uf.isSameSet(fr.ss.ff, fr.ss.ss))
        {
            cost += fr.ff;
            uf.unionSet(fr.ss.ff, fr.ss.ss);
        }
    }
    cout << cost << endl;
}