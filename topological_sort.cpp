#include <bits/stdc++.h>
using namespace std;

void addedge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}

void topology(vector<vector<int>> &adj,int V)
{
    vector<int> in_degree(V,0);
    for(int u=0;u<V;u++)
    {
        for(int x:adj[u])
        {
            in_degree[x]++;
        }
    }

    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(in_degree[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int x:adj[u])
        {
            if(--in_degree[x]==0)
            {
                q.push(x);
            }
        }
    }
}

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);
    addedge(adj, 0, 1);
    addedge(adj, 0, 2);
    addedge(adj, 1, 3);
    addedge(adj, 1, 4);
    addedge(adj, 2, 3);
    cout << "the toplogical sort is ";
    topology(adj, V);
    return 0;
}