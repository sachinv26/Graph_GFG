#include<bits/stdc++.h>
using  namespace std;


void BFS(vector<vector<int>> &adj,int s,vector<bool> &visited)
{
    queue<int> q;

    visited[s]=true;
    q.push(s);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        // cout<<u<<" ";

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

int BFSDin(vector<vector<int>> &adj,int V)
{
    vector<bool> visited(V,false);
    int count=0;
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            count++;
            BFS(adj,i,visited);
        }
    }
    return count;
}


void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


int main()
{
    int V=7;
	vector<vector<int>> adj(V);
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,4,5);
	addEdge(adj,5,6);
	addEdge(adj,4,6);

	cout << "Following is Breadth First Traversal: "<< endl; 
	int count=BFSDin(adj,V); 
    cout<<count;
	return 0; 
}