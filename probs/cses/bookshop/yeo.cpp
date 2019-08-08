#include <iostream>

using namespace std;

int n, x, i, j;
int o[100005], c[1005], w[1005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> n >> x;
    for (i = 0; i < n; i++)
        cin >> c[i];
    for (i = 0; i < n; i++)
        cin >> w[i];
    fill(o, o + x + 4, -63);
    o[0] = 0;

    for (j = 0; j < n; j++)
        for (i = 1; i <= x; i++)
            if (i >= c[j] && o[i - c[j]] >= 0)
                o[i] = max(o[i], o[i - c[j]] + w[j]);
    cout << o[x] << endl;
}