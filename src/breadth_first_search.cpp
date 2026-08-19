#include "bits/stdc++.h"
using namespace std;
constexpr static int inf = 1e9;

// calcola la distanza minima dal nodo src a ogni altro nodo (grafo non pesato)

struct graph {

    int n, m, src;
    vector<int> dist;
    vector<vector<int>> adj;

    void bfs() {
        queue<int> q;
        q.emplace(src);
        for (int i = 0; i < n; i++)
            dist[i] = inf;
        dist[src] = 0;
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            for (auto v: adj[u]) {
                if (dist[v] == inf) {
                    dist[v] = dist[u] + 1;
                    q.emplace(v);
                }
            }
        }
    }

    void build() {
        cin >> n >> m >> src;
        adj.resize(n);
        dist.resize(n);
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
        bfs();
    }

};

int main() {
    graph g;
    g.build();
}
