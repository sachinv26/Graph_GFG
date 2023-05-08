#include <bits/stdc++.h> 
using namespace std; 
#define V 4


vector<int> djikstra(vector<vector<int>> &graph,int src)
{
    vector<int> key(V,INT_MAX);
    vector<bool> mset(V,false);

    key[src]=0;

    for(int count=0;count<V-1;count++){

        int u=-1;
        for(int i=0;i<V;i++){
            if(mset[i]==false && (u==-1 || key[i]<key[u]))
            {
                u=i;
            }
        }
        mset[u]=true;

        for(int v=0;v<V;v++){
            if(graph[u][v]!=0 && mset[v]==false)
            {
                key[v]=min(key[v],key[u]+graph[u][v]);
            }
        }
    }
    return key;
}


int main() 
{ 
    vector<vector<int>> graph = { { 0, 50, 100, 0}, 
						{ 50, 0, 30, 200 }, 
						{ 100, 30, 0, 20 }, 
						{ 0, 200, 20, 0 },};

    for(int x:djikstra(graph,0)){
        cout<<x<<" ";
    }

    return 0; 
}