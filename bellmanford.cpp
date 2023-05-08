#include<bits/stdc++.h>
using namespace std;

void bellman_ford(int n,int m,vector<vector<pair<int, int>>> &adj_list,int start){
    vector<int> dist(n+1,INT_MAX);
    dist[start]=0;


    for(int i=1;i<=n-1;i++){
        for(int u=1;u<=n;u++){
            for(auto edge:adj_list[u]){
                int v=edge.first;
                int w=edge.second;
                if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }
    }
    for (int u = 1; u <= n; u++) {
        for (auto edge : adj_list[u]) {
            int v = edge.first, w = edge.second;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                cout << "Graph contains negative-weight cycle" << endl;
                return;
            }
        }
    }

    cout << "Distances from node " << start << ":" << endl;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;
}


int main() {
    int n = 5, m = 8, start = 1;
    vector<vector<pair<int, int>>> adj_list(n+1);
    adj_list[1].push_back({2, 6});
    adj_list[1].push_back({3, 5});
    adj_list[1].push_back({4, 5});
    adj_list[2].push_back({5, -1});
    adj_list[3].push_back({2, -2});
    adj_list[3].push_back({5, 1});
    adj_list[4].push_back({3, -2});
    adj_list[4].push_back({5, -1});
    bellman_ford(n, m, adj_list, start);
    return 0;
}