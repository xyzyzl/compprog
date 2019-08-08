#include <bits/stdc++.h>

using namespace std;

#define MAXN 200005
#define MOD 998244353

int n;
long long deg[MAXN], fact[MAXN+6];
void find_fact()
{
    fact[0] = 1;
    for(int i = 1; i <= 200005; i++)
    {
        fact[i] = (fact[i-1] * i) % MOD;
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    find_fact();
    long long ans = n;
    for(int i = 1; i <= n; i++) ans = (ans * fact[deg[i]]) % MOD;
    cout << ans << endl;
}