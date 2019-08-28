#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
 
using namespace std;
 
#define MAXN 201
 
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORD(i, n) for(int i = n-1; i >= 0; i--)
#define FOBIR(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
 
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

string a;
bool vow(char c)
{
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
bool odd(char c)
{
    return (c=='1'||c=='3'||c=='5'||c=='7'||c=='9');
}
int main()
{
    DUEHOANG;
    cin >> a;
    int b=0;
    FOR(i, a.length())
    {
        if(vow(a[i]) || odd(a[i])) b++;
    }
    cout << b << endl;
}