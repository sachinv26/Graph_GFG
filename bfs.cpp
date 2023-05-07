#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<vector<int>> &adj,int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BFS(vector<vector<int>> &adj,int s)
{
    int n=adj.size();
    vector<bool> visited(n,false);
    queue<int> q;
    visited[s]=true;
    q.push(s);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:adj[u])
        {
            if(!visited[v])
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
}

int main()
{
    int V=5;
    vector<vector<int>> adj(V);
    addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3);
	addEdge(adj,3,4);
	addEdge(adj,2,4);
    BFS(adj,0);
}