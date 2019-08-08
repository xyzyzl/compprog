#include <iostream>

using namespace std;

int n, x, i, j, c[1005], w[1005], d[1005][100005], a;
int main()
{
    cin >> n >> x;
    for (i = 1; i <= n; i++)
        cin >> c[i];
    for (i = 1; i <= n; i++)
        cin >> w[i];
    d[0][0] = 0;
    for (j = 0; j <= x; j++)
        d[0][j] = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= x; j++)
        {
            if (c[i] > j)
                d[i][j] = d[i - 1][j];
            else
                d[i][j] = max(d[i - 1][j], d[i - 1][j - c[i]] + w[i]);
        }
    for (i = 1; i <= n; i++)
        a = max(a, d[i][x]);
    cout << a;
}