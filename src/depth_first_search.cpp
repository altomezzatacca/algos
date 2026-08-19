#include "bits/stdc++.h"
using namespace std;

// visita generica di un grafo

struct graph {

    int n, m;
    vector<vector<int>> adj;
    vector<bool> visited;

    void dfs(int node) {
        if (visited[node]) return;
        visited[node] = true;
        for (auto u: adj[node])
            dfs(u);
    }

    void build() {
        cin >> n >> m;
        adj.resize(n);
        visited.resize(n);
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            adj[a].emplace_back(b);
        }
        dfs(0);
    }

};

int main() {
    graph g;
    g.build();
}
