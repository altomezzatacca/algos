#include "bits/stdc++.h"
using namespace std;
constexpr static int inf = 1e9;

// calcola la distanza minima dal nodo src a ogni altro nodo (grafo pesato)
// complessità di O(M * log N) -> grafi sparsi

struct graph {

    int n, m, src;
    vector<int> dist;
    vector<vector<pair<int, int>>> adj;

    void dijkstra() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < n; i++)
            dist[i] = inf;
        pq.emplace(dist[src] = 0, src);
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (dist[u] < d) continue;
            for (auto [v, w]: adj[u])
                if (dist[v] > dist[u] + w)
                    pq.emplace(dist[v] = dist[u] + w, v);
        }
    }

    void build() {
        cin >> n >> m >> src;
        adj.resize(n);
        dist.resize(n);
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
