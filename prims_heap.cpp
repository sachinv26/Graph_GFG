#include<bits/stdc++.h>
using namespace std;
#define V 4

int primMST(vector<vector<pair<int,int>>> graph) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> key(V, INT_MAX);
    vector<bool> mSet(V, false);
    int res = 0;
    pq.push(make_pair(0, 0));
    key[0] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(mSet[u]) continue;

        mSet[u] = true;
        res += key[u];

        for(auto it: graph[u]) {
            int v = it.first;
            int weight = it.second;
            if(!mSet[v] && weight < key[v]) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
            }
        }
    }
    return res;
}

int main() {
    vector<vector<pair<int,int>>> graph = {
        {{1,5},{2,8},{3,0}},
        {{0,5},{2,10},{3,15}},
        {{0,8},{1,10},{3,20}},
        {{0,0},{1,15},{2,20}}
    };

    cout<<primMST(graph)<<endl;
    return 0;
}
