#include <bits/stdc++.h>

using namespace std;

int n,m,pp[100005],color[100005],best_i=-1,best_v=-1;
vector<int> adj_lst[100005],vals;
bool vis[100005];

bool cyclic(int v, int parent, int col)
{
    vis[v]=1;
	color[v]=col;
    for(int i:adj_lst[v])
    {
        if(!vis[i])
        {
            pp[i]=v;
            return cyclic(i,v,col);
        }
        else if(i!=parent)
        {
			if(color[i]!=col) continue;
            best_i=i;
            best_v=v;
            return 1;
        }
    }
    return 0;
}

bool cyclic()
{
	int col=0;
    for(int i:vals)
    {
        if(!vis[i])
            if(cyclic(i,-1,++col))
                return 1;
    }
    return 0;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        vals.push_back(x);
        vals.push_back(y);
        adj_lst[x].push_back(y);
        adj_lst[y].push_back(x);
    }
    sort(vals.begin(),vals.end());
    if(cyclic())
    {
        int j=best_v;
        int ct=2;
        while(j!=best_i)
        {
			ct++;
            j=pp[j];
        }
        cout<<ct<<endl;
        
        cout<<best_i+1<<" ";
        j=best_v;
        while(j!=best_i)
        {
            cout<<j+1<<" ";
            j=pp[j];
        }
        cout<<best_i+1<<endl;
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
}
