#include <bits/stdc++.h>

using namespace std;

int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> orderTopoSort;

void dfsTopoSort(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfsTopoSort(u);
    }
    orderTopoSort.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    orderTopoSort.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfsTopoSort(i);
    }
    reverse(orderTopoSort.begin(), orderTopoSort.end());
}