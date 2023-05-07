#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<vector<int>> &adj,int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}


bool dfsrec(vector<vector<int>> &adj,int s,vector<bool> &visited,vector<bool> &recst)
{
    visited[s]=true;
    recst[s]=true;


    for(int u:adj[s])
    {
        if(visited[u]==false && dfsrec(adj,u,visited,recst)==true)
        {
            return true;
        }
        else if(recst[u]==true)
        {
            return true;
        }
    }
    recst[s]=false;
    return false;
}

bool DFS(vector<vector<int>> &adj,int v)
{
    vector<bool> visited(v,false);
    vector<bool> recst(v,false);
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            if(dfsrec(adj,i,visited,recst)==true)
                return true;
        }
    }
}

int main()
{
    int V=6;
	vector<vector<int>> adj(V);
	addEdge(adj,0,1); 
	addEdge(adj,2,1); 
	addEdge(adj,2,3); 
	addEdge(adj,3,4); 
	addEdge(adj,4,5);
	addEdge(adj,5,3);

	if(DFS(adj,V))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

	return 0; 
}