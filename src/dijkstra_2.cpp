#include "bits/stdc++.h"
using namespace std;
constexpr static int inf = 1e9;

// calcola la distanza minima dal nodo src a ogni altro nodo (grafo pesato)
// complessità di O(N^2) -> grafi densi

struct graph {

    int n, m, src;
    vector<int> dist;
    vector<bool> visited;
    vector<vector<pair<int, int>>> adj;

    void dijkstra() {
        for (int i = 0; i < n; i++)
            dist[i] = inf;
        dist[src] = 0;
        for (int i = 0; i < n; i++) {
            int cur = -1;
            for (int j = 0; j < n; j++)
                if (!visited[j] && (cur == -1 || dist[j] < dist[cur]))
                    cur = j;
            if (cur == -1 || dist[cur] == inf) break;
            visited[cur] = true;
            for (auto [u, w]: adj[cur])
                if (dist[u] > dist[cur] + w)
                    dist[u] = dist[cur] + w;
        }
    }

    void build() {
        cin >> n >> m >> src;
        adj.resize(n);
        dist.resize(n);
        visited.resize(n);
        for (int i = 0; i < m; i++) {
            int a, b, x; cin >> a >> b >> x;
            adj[a].emplace_back(b, x);
            adj[b].emplace_back(a, x);
        }
        dijkstra();
    }

};

int main() {
    graph g;
    g.build();
}
