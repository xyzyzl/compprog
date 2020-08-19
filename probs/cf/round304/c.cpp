#include <bits/stdc++.h>

#pragma GCC optimize ("O3")

using namespace std;

int n;
queue<int> q1, q2;
set<pair<int, int> > vis;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int ppp;
    cin >> ppp;
    for(int i = 0; i < ppp; i++)
    {
        int j;
        cin >> j;
        q1.push(j);
    }
    cin >> ppp;
    for(int i = 0; i < ppp; i++)
    {
        int j;
        cin >> j;
        q2.push(j);
    }
    int rd = 0;
    while(!q1.empty() && !q2.empty())
    {
        rd++;
        int a = q1.front();
        q1.pop();
        int b = q2.front();
        q2.pop();
        if(rd > 3628800)
        {
            cout << -1 << endl;
            return 0;
        }
        if(a > b)
        {
            // give them both to q1
            q1.push(b);
            q1.push(a);
        } else 
        {
            // give them both to q2
            q2.push(a);
            q2.push(b);
        }
    }
    cout << rd << " ";
    if(q1.empty()) cout << 2 << endl;
    else cout << 1 << endl;
}

// issue: i had some flawed way of calculating visited (found cycle only in first 2)
// instead i should have just found the entire 10! loop

// instead of trying to find antigeniosity workaround just implement solution if works