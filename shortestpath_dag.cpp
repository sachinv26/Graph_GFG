// O(V+E)

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<pair<int,int>>> &adj,int u,int v,int wt)
{
    adj[u].push_back(make_pair(v,wt));
}

vector<int> topoSort(vector<vector<pair<int,int>>> &adj, int V) {
    vector<int> inDegree(V, 0);
    for (int u = 0; u < V; u++) {
        for (auto i : adj[u]) {
            int v = i.first;
            inDegree[v]++;
        }
    }
    vector<int> topoOrder;
    queue<int> q;
    for (int u = 0; u < V; u++) {
        if (inDegree[u] == 0) {
            q.push(u);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);
        for (auto i : adj[u]) {
            int v = i.first;
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    return topoOrder;
}


void shortestPath(vector<vector<pair<int,int>>> &adj,int V,int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src]=0;
    vector<int> topoOrder = topoSort(adj, V);
    for(int u:topoOrder){
        if(dist[u]!=INT_MAX)
        {
            for(auto i:adj[u])
            {
                if(dist[u]+i.second<dist[i.first])
                {
                    dist[i.first]=dist[u]+i.second;
                }
            }
        }
    }

    for(int i=0;i<V;i++)
    {
        if(dist[i]==INT_MAX)
        {
            cout<<"INF"<<" ";
        }
        else
        {
            cout<<dist[i]<<" ";
        }
    }
}

int main()
{
    int V=6;
    vector<vector<pair<int,int>>> adj(V);
    addEdge(adj,0,1,2); 
    addEdge(adj,0,4,1); 
    addEdge(adj,1,2,3); 
    addEdge(adj,4,2,2); 
    addEdge(adj,4,5,4); 
    addEdge(adj,5,3,1); 
    addEdge(adj,2,3,6); 
    shortestPath(adj,V,0);
    return 0;
}
