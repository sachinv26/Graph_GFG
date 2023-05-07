#include<iostream>
#include<vector>
using namespace std;


void DFSrec(vector<vector<int>> &adj,vector<bool> &visited,int s)
{
    visited[s]=true;
    cout<<s<<" ";
    for(int u:adj[s])
    {
        if(visited[u]==false)
        {
            DFSrec(adj,visited,u);
        }
    }
}

void DFS(vector<vector<int>> &adj,int V,int s)
{
    vector<bool> visited(V,false);
    DFSrec(adj,visited,s);
}


void addEdge(vector<vector<int>> &adj,int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int V=5;
	vector<vector<int>> adj(V);
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,1,4);
	addEdge(adj,3,4);
	cout << "Following is Depth First Traversal: "<< endl; 
	DFS(adj,V,0);
}